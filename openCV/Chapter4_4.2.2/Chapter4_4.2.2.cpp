#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

	//4.2.2 마우스 이벤트 제어 
	//openCV에서 제공하는 콜백 함수를 통해 이벤트르 발생 및 제어 
	//개발자 함수 호출 방식이 아닌 어떤 이벤트가 발생하거나 특정 시점에 도달했을 때 시스템에서 개발자가 등록한 함수를 호출 하는 방식
	//마우스 이벤트 등록 : cv::setMouseCallback()

void onMouse(int, int, int, int, void *);		//마우스 콜백 함수 선언




int main() {

	Mat image(200, 300, CV_8U);
	image.setTo(255);													//image 행렬 초기화 - 흰색 바탕 
	imshow(" 마우스 이벤트1 ", image);									//창 생성 
	imshow(" 마우스 이벤트2 ", image);
	
	setMouseCallback(" 마우스 이벤트1 ", onMouse, 0);							//마우스 이벤트 콜백함수 시스템에 등록 	
	setMouseCallback(" 마우스 이벤트2 ", onMouse, 0);
	waitKey(0);
	
	return 0;
}

void onMouse(int event, int x, int y, int flags, void *param) {			//콜백함수 구현 

	switch (event) {													//event 값에 따라 버튼 종류 구분 

	case EVENT_LBUTTONDOWN:
		cout << "마우스 왼쪽버튼 누르기" << endl;
		break;

	case EVENT_RBUTTONDOWN:
		cout << "마우스 오른쪽버튼 누르기" << endl;
		break;

	case EVENT_RBUTTONUP:
		cout << "마우스 오른쪽버튼 떼기" << endl;
		break;

	case EVENT_LBUTTONDBLCLK:
		cout << "마우스 왼쪽버튼 더블클릭" << endl;
		break;

	}
}

