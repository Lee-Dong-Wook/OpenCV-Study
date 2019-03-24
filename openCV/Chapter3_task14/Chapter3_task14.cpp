#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
  
	//좌표를 10,10 평행이동 , 20x30만큼 증가  // 포인트 연산, 사이즈와 연산 
	//size.width, size.hieght, size.area(), size 객체 명은 가로x세로 출력 

	//사각형 생성 Rect(시작좌표x,시작좌표y,너비w,높이h)
	Rect_<float>  rect(30.0f, 40.0f, 100.0f, 200.0f);

	cout << " 초기사각형 정보 "<< rect << endl; 
	cout << " 초기사각형의 넓이 "<<rect.area() << endl<<endl; 

	//좌표와 크기 객체 생성 
	Size2f sz(20,30);
	Point2f pt(10, 10);

	rect = rect + sz;
	cout << " 크기 조절 후 사각형 정보 " << rect << endl;
	cout << " 크기 조절 후 사각형 넓이 " << rect.area() << endl<<endl;
	
	rect = rect + pt; 
	cout << " 좌표 이동 후 사각형 정보 " << rect << endl;
	

	return 0;
}