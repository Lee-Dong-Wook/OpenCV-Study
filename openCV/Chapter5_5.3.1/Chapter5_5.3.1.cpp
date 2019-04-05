#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.1 행렬 산술 연산 
//참고 
//Rect rect(Point(3, 0), Size(3, 3));				//관심영역 지정 
//mask(rect).setTo(1);							//사각형 영역만큼 mask 행렬에서 참조하여 원소값을 1로 지정 

//주의점 
//Mat 객체를 생성할 때 초기화를 해주지 않는다면 디버그 모드는 205, 릴리즈 모드는 0으로 초기화 된다. 
//관심영역 추출 시 0이면 관심영역에서 배재하는 식(정확하지 않음)이 기때문에 mask 원소값이 205로 초기화가 되어있으면 
//masking이 재대로 되지 않기 때문에 반드시 행렬을 초기화 해주어야한다. 혹은 실행을 릴리즈모드로 한다면 정확한 결과가 나온다. 

int main() {

	Mat m_add1, m_add2, m_sub, m_div1, m_div2;

	Mat m1(3, 6, CV_8UC1, Scalar(10));				//3행 6열 1채널 uchar 행렬 선언 및 초기화 
	Mat m2(3, 6, CV_8UC1, Scalar(50));
	Mat mask(m1.size(), CV_8UC1, Scalar(0));					//마스크 행렬 - 8bit 단일 채널 

	Rect rect(Point(2, 0), Size(3, 3));				//관심영역 지정 
	mask(rect).setTo(1);							//사각형 영역만큼 mask 행렬에서 참조하여 원소값을 1로 지정 

	add(m1, m2, m_add1);							//행렬 덧셈
	add(m1, m2, m_add2, mask);						//관심영역(mask 1인 영역)만 덧셈 수행 

	divide(m1, m2, m_div1);							//m1에서 m2 나누기 
	m1.convertTo(m1, CV_32F);						//형변환 - 소수부분 보존, 나눗셈시 행렬 자료형 변환을 통해 소수점 보존 
	m2.convertTo(m2, CV_32F);
	divide(m1, m2, m_div2);

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;
	cout << "[mask] = " << endl << mask << endl;

	cout << "[m_add1] = " << endl << m_add1 << endl;
	cout << "[m_add2] = " << endl << m_add2 << endl;
	cout << "[m_div1] = " << endl << m_div1 << endl;
	cout << "[m_div2] = " << endl << m_div2 << endl;

	waitKey();
	return 0;
}

