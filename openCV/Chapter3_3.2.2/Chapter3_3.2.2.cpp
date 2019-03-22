#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//Mat 클래스 초기화 
	//단위행렬이나 1로 구성된 행렬 등의 특수한 행렬을 생성하는 함수  
	Mat m1 = Mat::ones(3, 5, CV_8UC1);
	Mat m2 = Mat::zeros(3, 5, CV_8UC1);
	Mat m3 = Mat::eye(3, 3, CV_8UC1);

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;
	cout << "[m3] = " << endl << m3 << endl;
	return 0;
}