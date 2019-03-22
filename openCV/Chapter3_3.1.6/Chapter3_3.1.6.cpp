#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//Scalar_ 클래스
	//Vec<Tp,4>에서 파생된 템플릿 클래스
	//화소의 값을 지정하기 위한 자료형으로 정의 R,G,B,A
	//Scalar_<double>이 Scalar 로 선언이 가능 
	//Vec 클래스에서 사용하는 대부분 연산 가능 

	//기본 선언 방법
	Scalar_<uchar>	red(0, 0, 255); //uchar = unsigned char 
	Scalar_<int>	blue(255, 0, 0);
	Scalar_<double> color1(500);
	Scalar_<float>	color2(100.f, 200.f, 125.9f);

	Vec3d	green(0, 0, 300.5);
	Scalar	green1 = color1 + (Scalar)green; //명시적 형변환 필요 
	Scalar  green2 = color2 + (Scalar_<float>)green; //묵시적 형변환 발생
													 //계산과정에서 명시적 형변환, 
													 //저장과정에서 묵시적 형변환
	cout << "blue = " << blue[0] << "," << blue[1];
	cout << "," << blue[1] << "," << blue[2] << endl;
	cout << "red = " << red << endl; 
	cout << "green1 = " << green1 << endl;
	cout << "green2 = " << green2 << endl; 
	
	return 0;
}