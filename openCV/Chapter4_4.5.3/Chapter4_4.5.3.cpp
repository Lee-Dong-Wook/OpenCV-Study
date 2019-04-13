#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
	
//4.5.3 카메라 프레임 동영상 파일 저장 
//실행결과 
//width x hieght : [640 x 360]
//VideoWriter::fourcc : 808802372
//delay : 33
//fps : 29.97
//
//카메라가 실행되어 촬영하는 동시에 바로 동영상파일로 저장된다. 

int main() {


	VideoCapture capture(0);										//비디오객체 선언 및 0번 카메라 연결 
	CV_Assert(capture.isOpened());									//카메라 연결 예외 처리 

	double fps = 29.97;												//초당 프레임 수 
	int	   delay = cvRound(1000.0 / fps);							//프레임간 지연시간 
	Size   size(1920,1080);											//동영상 파일 해상도
	int	   fourcc = VideoWriter::fourcc('D','X','5','0');			//압축 코덱 설정 

	capture.set(CAP_PROP_FRAME_WIDTH, size.width);					//해상도 설정(저장 해상도 지정 ) 
	capture.set(CAP_PROP_FRAME_HEIGHT, size.height);
	
	cout << "width x hieght : "			<< size << endl;
	cout << "VideoWriter::fourcc : "	<< fourcc << endl;			//동영상 정보 콘솔창 출력 
	cout << "delay : " << delay			<< endl; 
	cout << "fps : " << fps				<< endl;

	VideoWriter writer;												//동영상 파일 저장 객체 
	writer.open("C:/Users/Raynor/Desktop/openCVEXImage/Sleep dongwook.avi",fourcc,fps,size); //파일 개방 및 설정 
	CV_Assert(writer.isOpened());
	
	while (true) {
		Mat frame;
		capture >> frame;											//카메라 영상받기 
		writer << frame;											//프레임을 동영상으로 저장 
		//writer.write(frame);

		imshow("카메라 영상보기", frame);
		if (waitKey(delay) > 0) break;
	}
	return 0;
}

