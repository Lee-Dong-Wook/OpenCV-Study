#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

//Ư�� ������ Ÿ������ �����Ͽ� �� â�� ǥ���Ѵ�. 

//����ũ ��� �̿�
//�ٸ� �Լ��� ����ؼ� ���� ���(dst1, dst2, dst3)�� ������ ���� (�� : bitwise_and(), bitwise()_or() ��)
//Ÿ�� ������ �߽ɰ� ũ��� ���Ƿ� �����Ѵ�(�� : 120, 120)

//bitwise..(�Է� �迭 Ȥ�� ��Į��, �Է¹迭 Ȥ�� ��Į��, �Է¹迭�� ���� ũ���� ��¹迭, ����ũ ����(8��Ʈ����ä��) - ����ũ�� ���Ұ� 0�� �ƴ� ��ǥ�� ���  )

//������ Ÿ���κ��� ���� �̹����� �����, �� �� �κ��� ���������� 

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/heeju.jpg",IMREAD_COLOR);
	CV_Assert(image.data);

	Mat imageResize;
	cv::resize(image, imageResize, cv::Size(400,400), 0, 0, INTER_LINEAR);

	//dst3�ʱ�ȭ�ϴ� ���� 
	//�ʱ�ȭ�� ������ ������ 0���� �ʱ�ȭ �� ���� 205�� �ʱ�ȭ �� ���ִ�. 
	//�̸� �����ϱ� ���ؼ� �ʱ�ȭ ��Ű�� ����. 

		//����ũ ����� ���Ұ� 0�� �ƴ� ��ġ�� ����
		//masks����� ������ 255�̱� ������ �ΰ��� ���� �κи� dst ��Ŀ� ���� 


	Mat dst1;
	Mat dst2;
	Mat dst3(imageResize.size(), CV_8UC3, Scalar(0, 0, 0));

	Mat mask(imageResize.size(), CV_8U, Scalar(0));
	Mat black(imageResize.size(), CV_8UC3, Scalar(0));

	imshow("Raw_leehee", imageResize);

	imshow("black", black);

	Point center(150, 150);
	ellipse(mask, center, Size(100,100), 0, 0, 360, Scalar(255), -1);
	imshow("mask", mask);
	
	bitwise_and(imageResize, imageResize,dst1,mask);

	bitwise_or(imageResize,black,dst2,mask);
	
	bitwise_xor(imageResize, black , dst3, mask);
	
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	waitKey();
	return 0;
}


