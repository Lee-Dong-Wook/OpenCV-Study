#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;



int main() {

	//Mat ���� �� �ڷ��� ��ȯ
	//����ó�� �� ���� ��� ���簡 ����� �߻��Ѵ�. 

	double data[] = {

		1.1, 2.2, 3.3, 4.4,
		5.5, 6.6, 7.7, 8.9,
		9.9, 10, 11, 12
	};

	Mat m1(3, 4, CV_64F, data);			//��İ� �迭�� �ڷ��� ��ġ ����
	Mat m2 = m1.clone();				//m1����� ���纻 ����, m2�� �Ҵ�
	Mat m3, m4;							
	m1.copyTo(m3);						//m1����� ������ �����͸� ����, m3��ķ� ��ȯ 
	m1.convertTo(m4, CV_8U);			//m1�� CV_64F -> CV_8U������ ��ȯ ����. �μ��� �Էµ� m4�� ��ȯ
	
	cout << "m1 =\n" << m1 << endl;
	cout << "m2 =\n" << m2 << endl;
	cout << "m3 =\n" << m3 << endl;
	cout << "m4 =\n" << m4 << endl;
	return 0;							

}