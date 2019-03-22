#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main() {

	//영상 처리를 위해 입력받는 영상 데이터는 기본적으로 채널당 8비트로 인코딩된 데이터 
	//8비트만을 이용하기 때문에 화소의 값에서 제한된 범위를 가진다. 
	
	//수식 : I(x,y) = min(max(round(r),0),255)

	//OpenCV에서는 행렬에 대해서 연산을 할 경우에는 기본적으로 포화 산술이 적용된다. 
	//또 한 기본 자료형에 대해서는 포화 산술 연산이 가능하도록 saturate_cast()를 구현 

	Matx<uchar, 2, 2>	m1;		//Matx객체 선언 	
	Matx<ushort, 2, 2>	m2; 

	m1(0, 0) = -50;
	m1(0, 1) = 300;
	m1(1, 0) = saturate_cast<uchar>(-50);
	m1(1, 1) = saturate_cast<uchar>(300);

	m2(0, 0) = -50;
	m2(0, 1) = 80000;
	m2(1, 0) = saturate_cast<unsigned short>(-50);
	m2(1, 1) = saturate_cast<unsigned short>(80000);

	cout << "[m1] = " << endl << m1 << endl; 
	cout << "[m2] = " << endl << m2 << endl;
	return 0;
}