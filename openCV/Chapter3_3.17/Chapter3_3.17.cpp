#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int main() {

	//RotatedRect 클래스 

	Mat		image(300, 500, CV_8UC1, Scalar(255)); //행렬선언, 300행, 500열 1채널 uchar 행렬 선언 및 원소 255로 초기화 -> 흰색 바탕색  
	Point2f center(250, 150);					   //회전사각형의 중심점 
	Point2f pts[4];
	Size2f	size(300, 100);						   //회전사각형의 크기 변수 지정
	RotatedRect rot_rect(center, size, 20);		   //회전 사각형 선언 

	Rect bound_rect = rot_rect.boundingRect();	   //회전사각형의 4개 모서리를 모두 포함하는 최소크기의 사각형 영역을 반환한다.
	rectangle(image, bound_rect, Scalar(0), 1);	   //1픽셀 검은색 사각형 그리기
	circle(image, rot_rect.center, 1, Scalar(0), 2);   //2픽셀 검은색 원 그리기 circle(image, center, radius, color, pixel)
	rot_rect.points(pts);						   //회전사각형 꼭짓점 반환 

	for (int i = 0; i < 4; i++) {

		circle(image, pts[i], 4, Scalar(0), 1);					 //꼭짓점 표시 	
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2); //꼭짓점 잇는 직선 	
	}
	
	imwrite("image.jpg",image);
	imshow("회전사각형", image);
	waitKey();
	return 0;
}