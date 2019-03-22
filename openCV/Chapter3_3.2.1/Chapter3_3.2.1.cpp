#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int main() {

	float data[] = {		//m4 ��� �ʱ�ȭ�� ���� data �迭 ���� 

		1.2f,2.3f,3.2f,
		4.5f,5.f,6.5f,
	};

	//Mat��ü ���� ���
	Mat m1(2, 3, CV_8U);				//2��, 3�� uchar�� ��� ���� - ä�ι������� 1ä�� 
	Mat m2(2, 3, CV_8U, Scalar(300));	//�ʱⰪ ���� - uchar���̶� 255�̻��� 255�� ����, uchar -> 255����  
	Mat m3(2, 3, CV_16S,Scalar(300));   //											   short -> 300���� 	
	Mat m4(2, 3, CV_32F,data);          //float �� ��� ���� 

	//Size_ ��ü�� mat ��ü ���� ��� 
	Size sz(2, 3);
	Mat m5(Size(2, 3), CV_64F,Scalar(0));			//2x3 ũ�� ��� ���� 3�� 2��    
	Mat m6(sz, CV_32F, data);           //Size_�� ��ü �ʱ�ȭ 

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;
	cout << "[m3] = " << endl << m3 << endl;
	cout << "[m4] = " << endl << m4 << endl<<endl;
	cout << "[m5] = " << endl << m5 << endl;
	cout << "[m6] = " << endl << m6 << endl;
   
	return 0;
	
}