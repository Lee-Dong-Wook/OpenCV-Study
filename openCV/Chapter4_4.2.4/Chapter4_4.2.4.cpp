#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//4.2.4 마우스 및 트랙바 이벤트 사용 

string title = "트랙바 이벤트", bar_name = "밝기 값";
Mat image;

void onChange(int value, void *userdata) {				//트랙바 콜백 함수 구현 

	int add_value = value - 130;						//-126~129 범위 
	cout << "추가 화소 값" << add_value << endl;

	Mat tmp = image + add_value;						//원본 행렬에 -126~129 사이값 더더하기 
	imshow(title, tmp);
}

void onMouse(int event, int x, int y, int flags, void *param) {		

	switch (event) {									//event 값에 따라 버튼 종류 구분 				

	case EVENT_LBUTTONDOWN:								//오른쪽 버튼 클릭 시 영상 밝기 10씩 증가 
		cout << "마우스 왼쪽버튼 누르기" << endl;
		add(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0)); //트랙바 위치 변경 
		imshow(title, image);
		
		break;

	case EVENT_RBUTTONDOWN:								//왼쪽 버튼 클릭 시 영상 밝기 10씩 감소 
		cout << "마우스 오른쪽버튼 누르기" << endl;
		subtract(image, 10, image);
		setTrackbarPos(bar_name, title, image.at<uchar>(0)); //트랙바 위치 변경 
		imshow(title, image);
		break;
	}
}

int main() {

	int value = 130;
	image = Mat(300, 500, CV_8UC1, Scalar(120));			//1채널 uchar 행렬 선언 

	namedWindow(title, WINDOW_AUTOSIZE);					//윈도우 생성
	createTrackbar("밝기값", title, &value, 255, onChange);	//트랙바 이름, 트랙바 등록할 창이름, 트랙바 변경값, 최대값, 콜백함수 이름 
	setMouseCallback(title,onMouse,0);
	imshow(title, image);
	waitKey(0);
	return 0;
}


