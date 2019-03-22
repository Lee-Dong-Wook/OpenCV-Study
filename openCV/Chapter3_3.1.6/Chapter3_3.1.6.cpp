#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {

	//Scalar_ Ŭ����
	//Vec<Tp,4>���� �Ļ��� ���ø� Ŭ����
	//ȭ���� ���� �����ϱ� ���� �ڷ������� ���� R,G,B,A
	//Scalar_<double>�� Scalar �� ������ ���� 
	//Vec Ŭ�������� ����ϴ� ��κ� ���� ���� 

	//�⺻ ���� ���
	Scalar_<uchar>	red(0, 0, 255); //uchar = unsigned char 
	Scalar_<int>	blue(255, 0, 0);
	Scalar_<double> color1(500);
	Scalar_<float>	color2(100.f, 200.f, 125.9f);

	Vec3d	green(0, 0, 300.5);
	Scalar	green1 = color1 + (Scalar)green; //����� ����ȯ �ʿ� 
	Scalar  green2 = color2 + (Scalar_<float>)green; //������ ����ȯ �߻�
													 //���������� ����� ����ȯ, 
													 //����������� ������ ����ȯ
	cout << "blue = " << blue[0] << "," << blue[1];
	cout << "," << blue[1] << "," << blue[2] << endl;
	cout << "red = " << red << endl; 
	cout << "green1 = " << green1 << endl;
	cout << "green2 = " << green2 << endl; 
	
	return 0;
}