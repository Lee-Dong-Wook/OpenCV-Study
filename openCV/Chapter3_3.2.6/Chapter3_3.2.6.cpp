#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	//Mat Ŭ������ �Ҵ�(=)������
	//��Į�� ��, ex) m1 =100, ����� ��� ���Ҹ� ������ ��Į�� ������ �����ϰ��� �� �� ����Ѵ�. ����ũ ����� ���� MatsetTo()���� ���� 
	//��ļ���   ex) m1 = m2 + m3, m1 = m3 - 6, ������ ����� m1��Ŀ� ����ȴ�. 
	//m1 = m2   ex) m2����� m1��Ŀ� ����Ǵ� ���� �ƴ϶� m2 ����� m1 ����� ����. 
	//				m2 ����� ���Ұ� ����Ǹ� m1����� ���ҵ� ���� ���� 

	Mat m1(2, 3, CV_8U, 2);		//2��,3�� ��� ���� �� �ʱ�ȭ 
	Mat m2(2, 3, CV_8U, Scalar(10));

	//��Ŀ���
	Mat m3 = m1 + m2;			//���� �� ����
	Mat m4 = m2 - 6;			//���ҿ� ��Į���� ����
	Mat m5 = m1;				//m5����� m1����� ���� 

	cout << "[m1] = " << endl << m1 << endl << endl; //2�� �ʱ�ȭ 
	cout << "[m2] = " << endl << m2 << endl << endl; //10���� �ʱ�ȭ
	cout << "[m3] = " << endl << m3 << endl << endl; //���� ��� ���� ��� 12�� ���� 
	cout << "[m4] = " << endl << m4 << endl << endl; //��� ���ҿ� 6�� ����. 10-6 = 4 

	cout << "[m1] = " << endl << m1 << endl << endl; //2
	cout << "[m5] = " << endl << m5 << endl << endl; //m1�� ���Ҹ� ���� 
	m5 = 100;										 //m5�� ���Ұ� 100�̵Ǵ� �����Ǵ� m1���� 100�� �ȴ�. 
	cout << "[m1] = " << endl << m1 << endl << endl; //100
	cout << "[m5] = " << endl << m5 << endl << endl; //100
	return 0;

}