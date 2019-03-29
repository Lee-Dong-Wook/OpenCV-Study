#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.4.03 �̹��� ���� ������� �б�

//������ 
//��� ��ǥ(100, 100) ȭ�Ұ�
//color2unchanged[53, 14, 29]
//gray2unchanged[88, 88, 88]
//
//color2unchanged: depth(0) channels(3)->�ڷ��� CV_8UC3
//gray2unchanged : depth(0) channels(3)->�ڷ��� CV_8UC3

//����� ���� �� �� �ִ� ��. 
//�̹����� ��ķ� �޾ƿ� �÷� Ÿ���� �����ϴ� �Ϳ� ���� ����ϴ� ���� �ٸ��� ���´�. 
//ȸ�� �̹����� �޾� ������ ä���� 3���� ������ �ִ�. 1���� ����� ���� grayscale�� ����. 

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

	string filename1 = "C:/Users/Raynor/Desktop/openCVEXImage/image1.jpg";
	string filename2 = "C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg";
	Mat color2unchanged = imread(filename1, IMREAD_UNCHANGED);						//���� ������� �б� 				
	Mat gray2unchanged = imread(filename2, IMREAD_UNCHANGED);
	CV_Assert(color2unchanged.data && gray2unchanged.data);

	Rect roi(100, 100, 1, 1);														
	cout << "��� ��ǥ (100,100) ȭ�Ұ�" << endl;
	cout << "color2unchanged" << color2unchanged(roi) << endl;
	cout << "gray2unchanged" << gray2unchanged(roi) << endl << endl;

	print_matInfo("color2unchanged", color2unchanged);
	print_matInfo("gray2unchanged", gray2unchanged);

	imshow("color2unchanged", color2unchanged);
	imshow("gray2unchanged", gray2unchanged);


	waitKey(0);
	return 0;
}


