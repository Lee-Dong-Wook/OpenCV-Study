#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.4.01 �̹��� ���� �б�(��鿵�� �ϱ�)
//����ó���� ȭ�Ұ����� ������ 2���� �迭�� ���� ����.
//���������� �о�鿩 ��Ŀ� ����. ����� ���� �����鿡�� ����� ����. �� ȭ�Ұ����� ��Ÿ���� �̹����� �ʿ��� ������
//���� ������ Ȯ�� �����ؾ��Ѵ�. ó���� ��� ��Ŀ� ���ؼ� ���� ���Ϸ� ������ �� �־���Ѵ�. 

//������ 
//gray2gray = 88			��ϵ� ����(1ä�� ȭ��)
//gray2color = 88, 88, 88   3ä��ȭ�� : ��ϵ� ���󿡼� ��ȯ�ؼ� ������ ���� ���´�. 

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

	string filename = "C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg";			//���� ���� ��ġ ��ϵ�(���)����  
	Mat gray2gray = imread(filename, IMREAD_GRAYSCALE);							//�������� �ε�, ��ϵ� �����б�  
	Mat gray2Color = imread(filename, IMREAD_COLOR);								//�������� �ε�, �÷� ���� �б� 	
	CV_Assert(gray2gray.data && gray2Color.data);									//����ó��,	    ���� ������ ������ ���� �߻�  

	Rect roi(100, 100, 1, 1);														//��� �� �� ȭ�� �簢�� 
	cout << "��� ��ǥ (100,100) ȭ�Ұ�" << endl;
	cout << "gray2gray" << gray2gray(roi) << endl;									//�κ� ��� ���� ��� �̹��� 100,100��ġ grayscale�� ���� ��
	cout << "gray2Color" << gray2Color(roi) << endl << endl;						//�κ� ��� ���� ��� �̹��� 100,100��ġ color�� ���� ������ 

	print_matInfo("gray2gray", gray2gray);											//��� ���� ���
	print_matInfo("gray2Color", gray2Color);

	imshow("gray2gray", gray2gray);													//��� ���� �������� ǥ�� 
	imshow("gray2Color", gray2Color);


	waitKey(0);
	return 0;
}


