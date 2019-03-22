#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	//Mat 객체 크기 변경 - mat_resize
	//Mat::resize() = 행개수 증감 
	
	Mat m = (Mat_<uchar>(2, 4) << 1, 2, 3, 4, 5, 6, 7, 8);	//2행 4열 uchar형 행렬 선언 및 초기화
	cout << "[m] = " << endl << m << endl << endl;			

	m.resize(1);											//행렬의 행수를 2->1로 변경 
	cout << "[m.resize(1)] = " << endl << m << endl << endl;

	m.resize(3);
	cout << "[m.resize(3)] = " << endl << m << endl << endl; //1행 -> 3행으로 증가했고 추가된 원소는 임의의 값 
															 //debug 모드와 release 모드의 값이 다름
	
	m.resize(5, Scalar(50));								 //3행 -> 5행으로 증가. 추가된 행을 50으로 지정
	cout << "[m.resize(5)] = " << endl << m << endl << endl;

	m = 30;													//m의 모든 원소를 30으로 초기화 
	cout << "[m] = " << endl << m << endl << endl;
	
	return 0;

}