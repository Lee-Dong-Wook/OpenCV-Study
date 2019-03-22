#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void print_mathInfo(string _name, Mat m) {

	cout << "[" << _name << " 행렬]" << endl;
	cout << "채널 수 = " << m.channels() << endl;
	cout << "행 x 열 = " << m.rows << " x " << m.cols << endl << endl; 
}

int main() {

	//Mat::reshape()
	//전체원소개수 유지. 채널, 행 개수를 변경 할때 사용 
	Mat m1(2, 6, CV_8U);		//2행, 6열 char형 행렬 선언 
	Mat m2 = m1.reshape(2);		//2채널 행렬로 변경 생성 
	Mat m3 = m1.reshape(3, 2);  //3채널, 2행 행렬로 변경 생성 

	cout << m1 << endl<<endl;			//2행, 6열 char형 행렬
	print_mathInfo("m1(2,6)", m1);
	cout << m2 << endl << endl;			//신기하게도 출력하면 행렬은 모두 그대로 
	print_mathInfo("m2 = m1.reshape(2)", m2);
	cout << m3 << endl << endl;			
	print_mathInfo("m3 = m1.reshape(3, 2)", m3);

	m1.create(3, 5, CV_16S);
	cout << m1 << endl<<endl; 
	print_mathInfo("m1m1.create(3, 5, CV_16S)", m1);
	 

	return 0;

}