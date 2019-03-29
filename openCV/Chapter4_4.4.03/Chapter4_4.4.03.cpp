#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.4.03 이미지 파일 정보대로 읽기

//수행결과 
//행렬 좌표(100, 100) 화소값
//color2unchanged[53, 14, 29]
//gray2unchanged[88, 88, 88]
//
//color2unchanged: depth(0) channels(3)->자료형 CV_8UC3
//gray2unchanged : depth(0) channels(3)->자료형 CV_8UC3

//결과를 통해 알 수 있는 것. 
//이미지를 행렬로 받아와 컬러 타입을 결정하는 것에 따라 출력하는 값이 다르게 나온다. 
//회색 이미지를 받아 오더라도 채널은 3개를 가지고 있다. 1개를 출력할 때는 grayscale일 때다. 

void print_matInfo(string name, Mat img) {				//행렬 정보 출력 함수 

	string mat_type;
	if (img.depth() == CV_8U)		mat_type = "CV_8U";
	else if (img.depth() == CV_8S)	mat_type = "CV_8S";
	else if (img.depth() == CV_16U) mat_type = "CV_16U";
	else if (img.depth() == CV_32S) mat_type = "CV_32S";
	else if (img.depth() == CV_32F) mat_type = "CV_32F";
	else if (img.depth() == CV_64F) mat_type = "CV_64F";

	cout << name;
	cout << format(": depth(%d) channels(%d) -> 자료형 ", img.depth(), img.channels());
	cout << mat_type << "C" << img.channels() << endl;
}
int main() {

	string filename1 = "C:/Users/Raynor/Desktop/openCVEXImage/image1.jpg";
	string filename2 = "C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg";
	Mat color2unchanged = imread(filename1, IMREAD_UNCHANGED);						//파일 정보대로 읽기 				
	Mat gray2unchanged = imread(filename2, IMREAD_UNCHANGED);
	CV_Assert(color2unchanged.data && gray2unchanged.data);

	Rect roi(100, 100, 1, 1);														
	cout << "행렬 좌표 (100,100) 화소값" << endl;
	cout << "color2unchanged" << color2unchanged(roi) << endl;
	cout << "gray2unchanged" << gray2unchanged(roi) << endl << endl;

	print_matInfo("color2unchanged", color2unchanged);
	print_matInfo("gray2unchanged", gray2unchanged);

	imshow("color2unchanged", color2unchanged);
	imshow("gray2unchanged", gray2unchanged);


	waitKey(0);
	return 0;
}


