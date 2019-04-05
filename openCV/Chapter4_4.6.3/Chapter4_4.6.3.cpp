#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.6.3 FileStorage 클래스로 행렬 데이터 저장 
//test.xml 파일을 읽어 picture 노드의 원소인 영상파일들을 읽어 들이고 
//이 영상들을 채널별로 평균과 표준편차를 데이터로 저장해 보자. 

//실행 결과 
//fs_r에서 xml 파일에 저장된 이미지의 이름을 가지고와 출력을 먼저한다. 
//imshow(node_pic[i], images[i]); 코드 부분에서 멈춘다. 3개의 이미지를 출력해놓은 상태, cmd 창은 아무런 메세지가 없다. 
//해당 프로젝트 파일에 보면 result.xml이 생성되었지만 0KB이다. 
//이미지 창을 모두 닫으면 비로서 CMD창에 메세지 출력, result.xml을 보면 1KB로 imshow(node_pic[i], images[i]); 이후 코드가 실행 
//가지고 온 이미지에 대해서 평균과 표준편차를 구한다. 
//result.xml 에 이미지에 대한 평균과 표준편차가 저장된다. 

int main(){

	FileStorage fs_r("test.xml",FileStorage::READ);			//test.xml을 스토리지 객체로 읽는다. 
	CV_Assert(fs_r.isOpened());								//예외처리 

	FileNode node_pic = fs_r["picture"];					//시퀸스 노드
	vector<Mat> images;

	string filePath = "C:/Users/Raynor/Desktop/openCVEXImage/";
	for (int i = 0; i < node_pic.size(); i++) {

		//이미지를 행렬로 받아온다. 경로폴더만 스트링으로 받고 xml파일에 저장된 파일명을 받아와 string으로 변환하여 경로로 지정하였다. 
		Mat tmp = imread(filePath + (string)node_pic[i], IMREAD_UNCHANGED); //영상 파일 정보대로 읽기 
		CV_Assert(tmp.data);
		images.push_back(tmp);
		imshow(node_pic[i], images[i]);
	}

	FileStorage fs_w("result.xml", FileStorage::WRITE);		//스토리지 객체 저장모드 
	CV_Assert(fs_w.isOpened());

	vector<double> mean, dev; 
	for (int i = 0; i < images.size(); i++) {

		string pic_name = ((string)node_pic[i]).substr(0,5);	//string.substr() 파일 이름만 가지고 오기 
		
		meanStdDev(images[i], mean, dev);						//평균과 표준편차를 벡터로 반환 
		fs_w << pic_name + "_mean" << "[";						//시퀸스 노드로 저장 

		for (int j = 0; j < (int)mean.size(); j++) {			//각 채널 평균은 원소로 저장 
			fs_w << mean[i];									//원소하나씩 저장 
		}

		fs_w << "]";
		fs_w << pic_name + "_dev" << dev;						//표준편차는 벡터로 저장 
	}

	waitKey();													//키입력이 받을 때까지 종료하지않는다. 없을 시 실행하고 바로 프로그램이 종료된다.	
	fs_r.release();

	return 0;

	
}

