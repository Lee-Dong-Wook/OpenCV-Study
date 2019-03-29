#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.4.01 이미지 파일 읽기(흑백영상 일기)
//영상처리란 화소값으로 구성된 2차원 배열에 대한 조작.
//영상파일을 읽어들여 행렬에 저장. 행렬의 연산 과정들에서 행렬의 원소. 즉 화소값들이 나타내는 이미지를 필요할 때마다
//직접 눈으로 확인 가능해야한다. 처리된 결과 행렬에 대해서 영상 파일로 저장할 수 있어야한다. 

//수행결과 
//gray2gray = 88			명암도 영상(1채널 화소)
//gray2color = 88, 88, 88   3채널화소 : 명암도 여상에서 변환해서 동일한 값이 나온다. 

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

	string filename = "C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg";			//영상 파일 위치 명암도(흑백)영상  
	Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);							//영상파일 로드, 명암도 영상읽기  
	Mat gray2Color = imread(filename, IMREAD_COLOR);								//영상파일 로드, 컬러 영상 읽기 	
	CV_Assert(gray2gray.data && gray2Color.data);									//예외처리,	    영상 파일이 없으면 에러 발생  

	Rect roi(100, 100, 1, 1);														//행렬 내 한 화소 사각형 
	cout << "행렬 좌표 (100,100) 화소값" << endl;
	cout << "gray2gray" << gray2gray(roi) << endl;									//부분 행렬 원소 출력 이미지 100,100위치 grayscale로 값이 얼마
	cout << "gray2Color" << gray2Color(roi) << endl << endl;						//부분 행렬 원소 출력 이미지 100,100위치 color로 값이 얼마인지 

	print_matInfo("gray2gray", gray2gray);											//행렬 정보 출력
	print_matInfo("gray2Color", gray2Color);

	imshow("gray2gray", gray2gray);													//행렬 정보 영상으로 표시 
	imshow("gray2Color", gray2Color);


	waitKey(0);
	return 0;
}


