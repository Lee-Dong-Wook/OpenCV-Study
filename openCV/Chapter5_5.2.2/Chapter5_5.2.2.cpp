#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.2.2 �÷� ä�� �и� 
//���������� ���� Blue, Green, Red�� ���ؼ� �����Ѵ�. 
//���� ä�� �����̱� ������ �����쿡 ��ϵ� �������� ��Ÿ����. 


int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/image1.jpg",IMREAD_COLOR);	//�÷� ���� �ε� 
	CV_Assert(image.data);																	//���� ó�� 

	Mat bgr[3];
	split(image, bgr);																		//3ä�� ����� 3�� ���Ҹ� ���� ��� �迭�� �и� 
	

	imshow("image",image);
	imshow("Blue bgr[0]",bgr[0]);
	imshow("Green bgr[1]",bgr[1]);
	imshow("Red bgr[2]",bgr[2]);
	
	waitKey();
	return 0;
}

