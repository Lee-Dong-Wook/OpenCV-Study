#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

//4.3.4 타원 그리기 
//RotatedRect클래스는 중심 좌표, 사각형의 크기 회전 각도를 모두 포함하기에 RotatedRect 클래스의 객체를 이용ㅇ해서 쉽게 타원을 그릴 수 있다.
//다만 시작각도와 종료각도가 없기 때문에 호는 그리지 못한다. 
//RotatedRect 클래스에서 사각형의 크기는 타원의 반지름이 아니라 지름을 의미한다. 

int main() {
	
	Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	Mat image(300, 700, CV_8UC3, Scalar(255, 255, 255));
	
	Point pt1(120, 150), pt2(550, 150);
	circle(image, pt1, 1, Scalar(0), 1);							//타원 중심점(1픽셀 원) 표시
	circle(image, pt2, 1, Scalar(0), 1);

	//타원 그리기 
	ellipse(image, pt1, Size(100, 60), 0, 0, 360, orange, 2);		//pt1에서 100x60크기 오렌지색 타원(0~360도)
	ellipse(image, pt1, Size(100, 60), 0, 30, 270, blue, 4);		//pt1에서 100x60크기 파란색 타원(30~270도)

	////호 그리기 
	ellipse(image, pt2, Size(100, 60), 30, 0, 360, orange, 2);		//pt1에서 100x60크기 오렌지색 타원(0~360도)
	ellipse(image, pt2, Size(100, 60), 30, -30, 160, blue, 4);		//pt1에서 100x60크기 오렌지색 타원(30~270도)

	
	imshow(" 타원 및 호 그리기 ",image);
	waitKey(0);
	return 0;
}


