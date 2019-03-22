#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//Rect클래스 구현 
	//1) x좌표, y좌표, 너비, 높이 
	//2) 시작좌표(pt1)와 크기(sz)
	//3) 시작좌표(pt1)와 종류좌표(pt2)

	//Rect 클래스 사용 
	//1) rect = rect+-point 사각형에 대한 평행이동
	//2) rect = rect+-size  사각형 크기의 변경 
	//3) rect = rect1&rect2 사각형의 교차영역 
	//4) rect = rect1|rect2 rect2와 rect3 영역을 모두 포함하는 영역 

	Size2d sz(100.5, 60.6);							//사각형 크기
	Point2f pt1(20.f, 30.f), pt2(100.f, 200.f);		//시작 좌표 및 종료 좌표 

	Rect_<int>		rect1(10, 10, 30, 50);			// 1) x = 10, y = 10, 너비 = 30, 높이 = 50 
	Rect_<float>	rect2(pt1, pt2);                // 2) 시작위치 pt1, 종료위치 pt2
	Rect_<double>	rect3(Point2d(20.5, 10), sz);   // 3)  시작 좌표와 Size_ 객체로 선언 
	Rect_<float>		rect7(pt1, sz);

	Rect	rect4 = rect1 + (Point)pt1;				//rect1, pt1만큼 평행이동. 시작좌표 변경 
	Rect2f	rect5 = rect2 + (Size2f)sz;             //rect2, rect2 + sz 사각형 덧셈. 크기 변경 
	Rect2d	rect6 = rect1 & (Rect)rect2;            //두사각형 교차영역 비교하는 대상이 서로 형이 같아야함

	cout << "rect3 = " << rect3.x << ", "<< rect3.y << ","; 
	cout << rect3.width << "x" << rect3.height << endl;
	cout << "rect7 = " << rect7.width << "x" << rect3.height << endl;
	cout << "rect7 = " << rect7.area() << endl;

	cout << "rect4 = "<< rect4.tl() << " " << rect4.br() << endl;
	cout << "rect5 크기 = "<< rect5.size() << endl;
	cout << "[rect6] = "<< rect6 <<endl;
	

	return 0;
}