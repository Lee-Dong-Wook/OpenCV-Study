#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

//4.3.5 마우스 이벤트 및 그리기 종합 

string title = "이벤트 그리기";		//전역변수 
Mat	   image;

void onMouse(int event, int x, int y, int flags, void *param) {

	static Point pt(-1, -1);									//콜백함수 호출시 변수값이 유지되게 정적변수로 선언 
	if (event == EVENT_LBUTTONDOWN) {							//왼쪽 마우스 버튼 클릭한 위치 지정 
		
		if (pt.x < 0) pt = Point(x, y);							//x좌표가 0보다 작으면 입력한 좌표로 설정 
		else {
			rectangle(image, pt, Point(x, y), Scalar(50), 2);	//종료좌표 및 그리기 
			
			imshow(title, image);
			pt = Point(-1, -1);									//시작 좌표 초기화 
		}
	}

	else if (event == EVENT_RBUTTONDOWN) {

		if (pt.x < 0) pt = Point(x, y);
		else {
			Point2d pt2 = pt - Point(x, y);
			int radius = (int)sqrt((pt2.x * pt2.x) + (pt2.y * pt2.y)); //두 좌표간 거리 
			circle(image, pt, radius, Scalar(150), 2);

			imshow(title, image);
			pt = Point(-1, -1);		
		}
	}
}

int main() {

	image = Mat(300, 500, CV_8UC1, Scalar(255));
	imshow(title, image);			
	
	setMouseCallback(title, onMouse, 0);							//콜백함수 등록 

	waitKey(0);
	return 0;
}

