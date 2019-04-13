#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.3 ��� ���� ���� ���� ���� ��� ���� 

//������ ȭ�ҿ� Ư���� ��� ���� ���ϸ� ������ �������.
//Ư�� ��� ���� ���� ������ ��ξ� ����. 
//���� ȭ�Ұ� ���� �� �ִ� �ִ�(255)���� ȭ���� ���� ���� ���� ������ ����� ����.

// ** ��ȭ ��� ���� saturate_cast ** 
//    �����÷ο찡 ���� �� ���� 254 + 2 = 256������ 255�� �Ѿ 0���� �ν�.
//    ��������� ��û ���� ������ ���;������� ������ ���������� ������ �ǹ�����.
//    �׷��� �ִ밪�� �Ѿ�� �ִ밪���� ������ ���ѹ�����. 

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg",IMREAD_GRAYSCALE);
	CV_Assert(!image.empty());

	Mat dst1 = image + 100;		//���
	Mat dst2 = image - 100;		//��Ӱ�
	Mat dst3 = 255 - image;		//����

	Mat dst4(image.size(), image.type());	//�̹��� ũ��, �̹����� �Ӽ� �״�� 
	Mat dst5(image.size(), image.type());	
	Mat dst6(image.size(), image.type());
	Mat dst7(image.size(), image.type());
	Mat dst8(image.size(), image.type());
	
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {

			dst5.at<uchar>(i, j) = 255 - image.at<uchar>(i, j); //���Һ� ���� ���� ������ ��ȭ����������� �ʾƵ� �ȴ�. 

			dst4.at<uchar>(i, j) = image.at<uchar>(i, j) + 100;
			dst6.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) + 100);
			
			dst7.at<uchar>(i, j) = image.at<uchar>(i, j) - 100;
			dst8.at<uchar>(i, j) = saturate_cast<uchar>(image.at<uchar>(i, j) - 100);
		}

		imshow("���� ���� image",	image);
		imshow("dst1 +100 ��� ��ȭ��� �ڵ�����",		dst1);		//��� ����� �ڵ����� ��ȭ��� ���� ���� 
		imshow("dst2 -100 ��Ӱ� ��ȭ��� �ڵ�����",	    dst2);      //��� ����� �ڵ����� ��ȭ��� ���� ���� 
		imshow("dst3 �������",		dst3);
		imshow("dst5 �������",     dst5);
		imshow("dst4 +100 ��� ��ȭ��� ������",		    dst4);		//���Һ� ����� ��ȭ ��� ���� ������ 
		imshow("dst6 +100 ��� ��ȭ��� ����",           dst6);
		imshow("dst7 -100 ��Ӱ� ��ȭ��� ������",       dst7);
		imshow("dst8 -100 ��Ӱ� ��ȭ��� ����",         dst8);
	}

	waitKey();
	return 0;
}