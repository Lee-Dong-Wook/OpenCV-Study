#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main() {

	//Mat 복사 및 자료형 변환
	//영상처리 시 원본 행렬 복사가 빈번히 발생한다. 

	double data[] = {

		1.1, 2.2, 3.3, 4.4,
		5.5, 6.6, 7.7, 8.9,
		9.9, 10, 11, 12
	};

	Mat m1(3, 4, CV_64F, data);			//행렬과 배열의 자료형 일치 유의
	Mat m2 = m1.clone();				//m1행렬의 복사본 생성, m2에 할당
	Mat m3, m4;							
	m1.copyTo(m3);						//m1행렬의 정보와 데이터를 복사, m3행렬로 반환 
	m1.convertTo(m4, CV_8U);			//m1를 CV_64F -> CV_8U형으로 변환 생성. 인수로 입력된 m4로 반환
	
	cout << "m1 =\n" << m1 << endl;
	cout << "m2 =\n" << m2 << endl;
	cout << "m3 =\n" << m3 << endl;
	cout << "m4 =\n" << m4 << endl;
	return 0;							

}