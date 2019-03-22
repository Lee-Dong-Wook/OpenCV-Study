#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	//Mat ��ü ũ�� ���� - mat_resize
	//Mat::resize() = �ళ�� ���� 
	
	Mat m = (Mat_<uchar>(2, 4) << 1, 2, 3, 4, 5, 6, 7, 8);	//2�� 4�� uchar�� ��� ���� �� �ʱ�ȭ
	cout << "[m] = " << endl << m << endl << endl;			

	m.resize(1);											//����� ����� 2->1�� ���� 
	cout << "[m.resize(1)] = " << endl << m << endl << endl;

	m.resize(3);
	cout << "[m.resize(3)] = " << endl << m << endl << endl; //1�� -> 3������ �����߰� �߰��� ���Ҵ� ������ �� 
															 //debug ���� release ����� ���� �ٸ�
	
	m.resize(5, Scalar(50));								 //3�� -> 5������ ����. �߰��� ���� 50���� ����
	cout << "[m.resize(5)] = " << endl << m << endl << endl;

	m = 30;													//m�� ��� ���Ҹ� 30���� �ʱ�ȭ 
	cout << "[m] = " << endl << m << endl << endl;
	
	return 0;

}