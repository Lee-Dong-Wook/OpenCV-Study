#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.4.02 이미지 파일 읽기(컬러영상 일기)

//수행결과 
//행렬 좌표(100, 100) 화소값
//color2gray[23]
//color2Color[53, 14, 29]								3채널 컬러 영상 화소값
//gray2gray: depth(0) channels(1)->자료형 CV_8UC1		컬러영상이라도 명암도 타입으로 읽으면 1채널 영상이 된다.
//gray2Color : depth(0) channels(3)->자료형 CV_8UC3

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

	string filename = "C:/Users/Raynor/Desktop/openCVEXImage/image1.jpg";			//영상 파일 위치     컬러  영상 
	Mat color2gray = imread(filename, IMREAD_GRAYSCALE);								//영상파일 로드, 명암도 영상읽기  
	Mat color2Color = imread(filename, IMREAD_COLOR);								//영상파일 로드, 컬러 영상 읽기 	
	CV_Assert(color2gray.data && color2Color.data);									//예외처리,	    영상 파일이 없으면 에러 발생  

	Rect roi(100, 100, 1, 1);														//행렬 내 한 화소 사각형 
	cout << "행렬 좌표 (100,100) 화소값" << endl;
	cout << "color2gray" << color2gray(roi) << endl;								//부분 행렬 원소 출력 이미지 100,100위치 grayscale로 값이 얼마
	cout << "color2Color" << color2Color(roi) << endl << endl;						//부분 행렬 원소 출력 이미지 100,100위치 color로 값이 얼마인지 

	print_matInfo("gray2gray", color2gray);											//행렬 정보 출력
	print_matInfo("gray2Color", color2Color);

	imshow("gray2gray", color2gray);												//행렬 정보 영상으로 표시 
	imshow("gray2Color", color2Color);


	waitKey(0);
	return 0;
}


