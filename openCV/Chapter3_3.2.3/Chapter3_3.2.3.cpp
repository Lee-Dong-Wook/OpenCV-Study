#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int main() {

	//Mat Ŭ�������� ��ӵ� ���ø� Ŭ����
	//���� Mat Ŭ������ ��� ������ ���� �޼ҵ� 
	//MatŬ������ Mat_Ŭ���� ���� ������ �����͸� �����Ӱ� ��ȯ 
	
	double	a = 32.12345678, b = 2.7;	//a,b�� m5����� ���ҷ� ���� �� �Ҽ��� ���� �ҽ� ���� Ȯ���� ����
	short	c = 400;
	float	d = 10.f, e = 11.f, f = 13.f; 

	Mat_<int>		m1(2,4);		//2�� 4�� int�� ��� 
	Mat_<uchar>		m2(3,4,100);	//3�� 4�� uchar�� ��� ���� �� 100���� ���� �ʱ�ȭ 	
	Mat_<short>		m3(4,5,c);		//4�� 5�� short�� ��ļ��� �� ���� c�� ���� 400���� �����ʱ�ȭ 

	m1 << 1, 2, 3, 4, 5, 6;								//��Ʈ��(<<)�����ڷ� m1 ����� ���Ұ��� �� ���� ����
														//m1�� ���Ұ� 8���ε� 6���� ����־� ������ 2���� �ǹ̰��� �� 
	Mat m4 = (Mat_<double>(2, 3) << 1, 2, 3, 4, 5, 6); 
	Mat m5 = (Mat_<float>(2, 3) << a, b, c, d, e, f);	//2��,3�� float�� ���, ������ ���� �� �ʱ�ȭ, a�� �Ҽ��� �Ϻ� �ҽ� 

	cout << "[m1] = " << endl << m1 << endl << endl;
	cout << "[m2] = " << endl << m2 << endl << endl;
	cout << "[m3] = " << endl << m3 << endl << endl;
	cout << "[m4] = " << endl << m4 << endl << endl;
	cout << "[m5] = " << endl << m5 << endl << endl;
	
														

	

	return 0;

}