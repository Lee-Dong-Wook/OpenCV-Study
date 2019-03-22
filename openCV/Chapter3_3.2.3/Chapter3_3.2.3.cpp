#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int main() {

	//Mat 클래스에서 상속된 템플릿 클래스
	//기존 Mat 클래스의 멤버 변수와 가상 메소드 
	//Mat클래스와 Mat_클래스 간에 참조와 포인터를 자유롭게 변환 
	
	double	a = 32.12345678, b = 2.7;	//a,b는 m5행렬의 원소로 사용될 때 소수점 이하 소실 여부 확인을 위함
	short	c = 400;
	float	d = 10.f, e = 11.f, f = 13.f; 

	Mat_<int>		m1(2,4);		//2행 4열 int형 행렬 
	Mat_<uchar>		m2(3,4,100);	//3행 4열 uchar형 행렬 선언 및 100으로 원소 초기화 	
	Mat_<short>		m3(4,5,c);		//4행 5열 short형 행렬선언 및 변수 c를 통해 400으로 원소초기화 

	m1 << 1, 2, 3, 4, 5, 6;								//스트림(<<)연산자로 m1 행렬의 원소값을 한 번에 지정
														//m1은 원소가 8개인데 6개만 집어넣어 나머지 2개는 의미값이 들어감 
	Mat m4 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6); 
	Mat m5 = (Mat_<float>(2, 3) << a, b, c, d, e, f);	//2행,3열 float형 행렬, 변수로 원소 값 초기화, a의 소수점 일부 소실 

	cout << "[m1] = " << endl << m1 << endl << endl;
	cout << "[m2] = " << endl << m2 << endl << endl;
	cout << "[m3] = " << endl << m3 << endl << endl;
	cout << "[m4] = " << endl << m4 << endl << endl;
	cout << "[m5] = " << endl << m5 << endl << endl;
	
														

	

	return 0;

}