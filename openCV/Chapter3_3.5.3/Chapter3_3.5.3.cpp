#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main() {

	//행렬 연산 함수 
	//Mat::inv() 행렬의 의사 역행렬 
	//Mat::mul() 두행렬의 각 원소간 곱셈 

	float data[]{
		1,0,2,
		-3,4,6,
		-1,-2,3
	};

	Mat m1(3,3,CV_32F,data);			//3행 3열 행렬 선언 
	Mat m2(Matx13f(6,30,8));			//Matx 객체로 1행 3열 행렬 선언 
	Mat m2_t=m2.t();					//행렬곱을 위한 전치 
	
	Mat m1_inv = m1.inv(DECOMP_LU);		//역행렬 계산 
	Mat x	   = m1_inv * m2_t;			//행렬 곱 

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m1_inv(역행렬)] = " << endl << m1_inv << endl;
	cout << "[m2(전치행렬)] = " << endl << m2_t << endl;

	cout << "연립방정식의 해 x1, x2, x3 = " << x.t() << endl << endl;

	return 0;
}