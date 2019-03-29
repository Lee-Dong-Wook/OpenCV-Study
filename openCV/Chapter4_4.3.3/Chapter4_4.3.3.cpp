#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

//4.3.3 원 그리기 
//circle(Mat& 원을 그릴대상 행렬(영상), Point 중심 좌표, int 원의 반지름, Scalar& 선의 색상, int 선의 두께, int 선의 형태, cv::line()와 동일인자, int 좌표에 대한 비트 시프트 연산 )

int main() {

	Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255));				//흰색 컬러 영상 

	Point center = (Point)image.size() / 2;								//영상 중심좌표 
	Point pt1(70, 50), pt2(350, 220);

	circle(image, center, 100, blue);									//원 그리기 
	circle(image, pt1, 80, orange, 2);
	circle(image, pt2, 60, magenta, -1);								//원내부를 채움 

	int font = FONT_HERSHEY_COMPLEX;
	putText(image, "center_blue", center, font, 1.2, blue);
	putText(image, "pt1_orange" , pt1, font, 0.8, orange);
	putText(image, "pt2_magenta", pt2 + Point(2,2), font, 0.5, Scalar(0,0,0), 2);
	putText(image, "pt3_magenta", pt2, font, 0.5, magenta, 1);

	imshow("원그리기",image);
	waitKey(0);
	return 0;
}


