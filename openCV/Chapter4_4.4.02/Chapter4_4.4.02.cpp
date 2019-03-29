#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.4.02 �̹��� ���� �б�(�÷����� �ϱ�)

//������ 
//��� ��ǥ(100, 100) ȭ�Ұ�
//color2gray[23]
//color2Color[53, 14, 29]								3ä�� �÷� ���� ȭ�Ұ�
//gray2gray: depth(0) channels(1)->�ڷ��� CV_8UC1		�÷������̶� ��ϵ� Ÿ������ ������ 1ä�� ������ �ȴ�.
//gray2Color : depth(0) channels(3)->�ڷ��� CV_8UC3

void print_matInfo(string name, Mat img) {				//��� ���� ��� �Լ� 

	string mat_type;
	if (img.depth() == CV_8U)		mat_type = "CV_8U";
	else if (img.depth() == CV_8S)	mat_type = "CV_8S";
	else if (img.depth() == CV_16U) mat_type = "CV_16U";
	else if (img.depth() == CV_32S) mat_type = "CV_32S";
	else if (img.depth() == CV_32F) mat_type = "CV_32F";
	else if (img.depth() == CV_64F) mat_type = "CV_64F";

	cout << name;
	cout << format(": depth(%d) channels(%d) -> �ڷ��� ", img.depth(), img.channels());
	cout << mat_type << "C" << img.channels() << endl;
}
int main() {

	string filename = "C:/Users/Raynor/Desktop/openCVEXImage/image1.jpg";			//���� ���� ��ġ     �÷�  ���� 
	Mat color2gray = imread(filename, IMREAD_GRAYSCALE);								//�������� �ε�, ��ϵ� �����б�  
	Mat color2Color = imread(filename, IMREAD_COLOR);								//�������� �ε�, �÷� ���� �б� 	
	CV_Assert(color2gray.data && color2Color.data);									//����ó��,	    ���� ������ ������ ���� �߻�  

	Rect roi(100, 100, 1, 1);														//��� �� �� ȭ�� �簢�� 
	cout << "��� ��ǥ (100,100) ȭ�Ұ�" << endl;
	cout << "color2gray" << color2gray(roi) << endl;								//�κ� ��� ���� ��� �̹��� 100,100��ġ grayscale�� ���� ��
	cout << "color2Color" << color2Color(roi) << endl << endl;						//�κ� ��� ���� ��� �̹��� 100,100��ġ color�� ���� ������ 

	print_matInfo("gray2gray", color2gray);											//��� ���� ���
	print_matInfo("gray2Color", color2Color);

	imshow("gray2gray", color2gray);												//��� ���� �������� ǥ�� 
	imshow("gray2Color", color2Color);


	waitKey(0);
	return 0;
}


