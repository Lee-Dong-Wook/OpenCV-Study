#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

//4.2.3 트랙바 이벤트 제어 
//일정한 범위 내에서 특정한 값을 선택하고자 할때 사용. 스크롤 바 , 슬라이더 바 등 

string title = "트랙바 이벤트";
Mat image;

void onChange(int value, void *userdata) {				//트랙바 콜백 함수 구현 

	int add_value = value - 130;						//-126~129 범위 
	cout << "추가 화소 값" << add_value << endl; 
    
	Mat tmp = image + add_value;						//원본 행렬에 -126~129 사이값 더더하기 
	imshow(title, tmp);
}


int main() {

	int value = 128; 
	image = Mat(300, 400, CV_8UC1, Scalar(120));		//1채널 uchar 행렬 선언 

	namedWindow(title, WINDOW_AUTOSIZE);				//윈도우 생성
	createTrackbar("밝기값",title,&value,255,onChange);	//트랙바 이름, 트랙바 등록할 창이름, 트랙바 변경값, 최대값, 콜백함수 이름 

	imshow(title, image);

	waitKey(0);
	return 0; 
}


