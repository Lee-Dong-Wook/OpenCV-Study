#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void print_mathInfo(string _name, Mat m) {

	cout << "[" << _name << " ���]" << endl;
	cout << "ä�� �� = " << m.channels() << endl;
	cout << "�� x �� = " << m.rows << " x " << m.cols << endl << endl; 
}

int main() {

	//Mat::reshape()
	//��ü���Ұ��� ����. ä��, �� ������ ���� �Ҷ� ��� 
	Mat m1(2, 6, CV_8U);		//2��, 6�� char�� ��� ���� 
	Mat m2 = m1.reshape(2);		//2ä�� ��ķ� ���� ���� 
	Mat m3 = m1.reshape(3, 2);  //3ä��, 2�� ��ķ� ���� ���� 

	cout << m1 << endl<<endl;			//2��, 6�� char�� ���
	print_mathInfo("m1(2,6)", m1);
	cout << m2 << endl << endl;			//�ű��ϰԵ� ����ϸ� ����� ��� �״�� 
	print_mathInfo("m2 = m1.reshape(2)", m2);
	cout << m3 << endl << endl;			
	print_mathInfo("m3 = m1.reshape(3, 2)", m3);

	m1.create(3, 5, CV_16S);
	cout << m1 << endl<<endl; 
	print_mathInfo("m1m1.create(3, 5, CV_16S)", m1);
	 

	return 0;

}