#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.5.1 ��� �� ��� ���� 

//Scalar sum()		�迭�� �� ä�� ���� ���ҵ��� �� N�� ����Ͽ� ��Į�� ������ ��ȯ 
//Scalar mean()		�迭�� �� ä�� ���� ���ҵ��� ����� ����Ͽ� ��Į������ ��ȯ 
//void meanStdDev() �迭���ҵ��� ��հ� ǥ�������� ��� 
//int countNonZero() 0�̾ƴ� �迭 ���Ҹ� ���� N�� ��ȯ
//void reduce()		����� �� Ȥ�� ��������� �ɼ� ���(rtype)�� ������ �����Ͽ� ���ͷ� ����
//void sort()		����� �� ��, �� �������� ���� 

//���� ��� 
//[sum_value] = [5.24488e+07, 5.24488e+07, 5.24488e+07, 0]		//���ҵ��� ��� �� 
//
//[mean_value1] = [64.7516, 64.7516, 64.7516, 0]				//��ü ���� ���, 3���� ���Ҹ� ��ȯ ������ ���Ҵ� 0 
//
//[mean_value2] = [81.1467, 81.1467, 81.1467, 0]				//���� ���� ���, 3���� ���Ҹ� ��ȯ ������ ���Ҵ� 0 
//
//[mean] = [64.75155925925927;									//��ü ���� ���/ǥ������ 						
//			64.75155925925927;
//			64.75155925925927]

//[stddev] = [49.30256737775272;								
//			  49.30256737775272;
//			  49.30256737775272]
//
//[mean] = [81.14673469387755;									//���� ���� ���� ���/ǥ������
//			81.14673469387755;
//			81.14673469387755]

//[stddev] = [6.529079344967299;
//			  6.529079344967299;
//			  6.529079344967299]

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg", 1); // 1�� �÷� ��� ��� ��, �÷� ���� �ε� 
	CV_Assert(image.data);
	
	Mat mask(image.size(), CV_8U, Scalar(0)), Mean, stddev; 
	
	mask(Rect(20, 40, 70, 70)).setTo(255);				//����ŷ ���� ���� - �ش� ���� ��� 

	Scalar sum_value = sum(image);						//ä�� ���Ұ� �� 
														//�Է� ����� ä�� ���� ���� ������ ���Ҹ� ��ȯ
														//image ����� 3ä�� �����̱� ������ 3�� ���Ұ� ��ȯ�ǰ� ���������Ҵ� 0		
	
	Scalar mean_value1 = mean(image);					//��հ�� 
	Scalar mean_value2 = mean(image, mask);				//��հ��, ����ũ ���� 1�� ������ ��� 

	cout << "[sum_value] = " << sum_value << endl<<endl; 
	cout << "[mean_value1] = " << mean_value1 << endl<<endl; 
	cout << "[mean_value2] = " << mean_value2 << endl<<endl;

	meanStdDev(image, Mean, stddev);					//��հ� ǥ�� ���� ��� ���� 
														//Mean = ���, stddev = ǥ������ 			

	cout << "[mean] = " << Mean << endl;
	cout << "[stddev] = " << stddev << endl << endl;

	meanStdDev(image, Mean, stddev, mask);				//����ũ ������ 1�� ��ġ�� image ��� ���/ǥ������ ���
														//��ȯ ����� �Է� ����� ä�� �� x 1, image����� ä�� ���� 3�̶�
														//3��, 1�� ����� ��� 						
	cout << "[mean] = " << Mean << endl; 
	cout << "[stddev] = " << stddev << endl << endl;

	imshow("image", image);
	imshow("mask", mask);
	
	waitKey();

	return 0;
}

