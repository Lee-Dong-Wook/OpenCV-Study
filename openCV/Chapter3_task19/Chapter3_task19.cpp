#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;


//void CropMax(Mat matx, int start_point1, int start_point2, int end_point1, int endPoint2, int setNumber)
void CropMatx(Mat m, int setNumber, int s_pt1, int s_pt2 ,int e_pt1, int e_pt2 ) {

	Mat	  matx; 
	Range start(s_pt1, s_pt2);
	Range end(e_pt1, e_pt2);

	matx = m(start, end);
	matx.setTo(setNumber);
}

int main() {

	//int형 행렬, 10x15크기 Mat클래스 사용 
	//범위 지정하는 함수 생성 Range()와 setTo()사용 
	//부모 행렬 입력, 범위지정할 좌표2개 입력,변경할 값입력

	Mat mat(10, 15, CV_32F, Scalar(100));

	CropMatx(mat, 200, 1, 5, 3, 8);
	CropMatx(mat, 300, 5, 9, 8, 14);
	CropMatx(mat, 555, 3, 7, 5, 10);
	
	cout << mat << endl; 
	return 0;
}