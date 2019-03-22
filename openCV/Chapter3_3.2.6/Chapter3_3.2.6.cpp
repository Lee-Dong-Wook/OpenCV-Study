#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	//Mat 클래스의 할당(=)연산자
	//스칼라 값, ex) m1 =100, 행렬의 모든 원소를 지정된 스칼라 값으로 변경하고자 할 때 사용한다. 마스크 행렬이 없는 MatsetTo()같은 역할 
	//행렬수식   ex) m1 = m2 + m3, m1 = m3 - 6, 수식의 결과가 m1행렬에 복사된다. 
	//m1 = m2   ex) m2행렬이 m1행렬에 복사되는 것이 아니라 m2 행렬을 m1 행렬이 공유. 
	//				m2 행렬의 원소가 변경되면 m1행렬의 원소도 같이 변경 

	Mat m1(2, 3, CV_8U, 2);		//2행,3열 행렬 선언 및 초기화 
	Mat m2(2, 3, CV_8U, Scalar(10));

	//행렬연산
	Mat m3 = m1 + m2;			//원소 간 덧셈
	Mat m4 = m2 - 6;			//원소와 스칼라값의 덧셈
	Mat m5 = m1;				//m5행렬이 m1행렬을 공유 

	cout << "[m1] = " << endl << m1 << endl << endl; //2로 초기화 
	cout << "[m2] = " << endl << m2 << endl << endl; //10으로 초기화
	cout << "[m3] = " << endl << m3 << endl << endl; //연산 결과 원소 모두 12로 변경 
	cout << "[m4] = " << endl << m4 << endl << endl; //모든 원소에 6을 뺀다. 10-6 = 4 

	cout << "[m1] = " << endl << m1 << endl << endl; //2
	cout << "[m5] = " << endl << m5 << endl << endl; //m1의 원소를 공유 
	m5 = 100;										 //m5의 원소가 100이되니 공유되는 m1또한 100이 된다. 
	cout << "[m1] = " << endl << m1 << endl << endl; //100
	cout << "[m5] = " << endl << m5 << endl << endl; //100
	return 0;

}