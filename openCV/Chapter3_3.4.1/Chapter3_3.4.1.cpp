#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main() {

	//Mat 클래스의 영역 참조(관심영역)
	//특정 영상 부분을 크롭하여 사용할 때 

    //Range 클래스 
	//start,end로 연속되는 범위를 규정. start는 주어진 범위 안에 포함, end는 범위에 포함 되지 않는다.
	//ex) 100이라고 할 때 0~99 

	Range r1(0, 3), r2(3, 7);   //범위를 나타내는 객체 
	int data[] = {				//행렬 원소로 사용될 배열 
		10,11,12,13,14,15,16,
		20,21,22,23,24,25,26,
		30,31,32,33,34,35,36,
		40,41,42,43,44,45,46,
	};

	Mat m1, m2;
	m1 = Mat(4, 7, CV_32S, data);   //4행, 7열 행렬선언 및 초기화 
	m2 = m1(r1, r2);				//범위객체로 관심 영역을 지정 

	cout << "[m1의 2번 행] = " << m1.row(2) << endl<<endl;
	cout << "[m1의 1번 열] = " << endl << m1.col(1) << endl<<endl;
	cout << "[m1의 (0~2행 모두)] = " << endl << m1.rowRange(r1) << endl << endl;

	cout << "[m1] = " << endl << m1 << endl << endl;
	cout << "[m2 (0~2행 3~6열) 참조] = " << endl << m2 << endl << endl;
	
	m2.setTo(50);					//m2행렬이 m1행렬을 참조하기에 m1행렬의 해당 관심영역도 변경이 된다. 
	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;

	return 0;

}