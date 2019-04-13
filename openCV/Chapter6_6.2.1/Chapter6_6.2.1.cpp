#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.1 ��ϵ� ���� ���� 

//��鿵��				= Binary image 0,1�� �̷���� ���,������ȭ�� 
//��̳ͽ�, �׷��̽�����  = Gray scale, 0~255���� ������ ȭ��, ����ä�� ������, ��ϵ�, ȸ���� �����̶� �θ� 

int main() {

	Mat image1(50, 512, CV_8UC1, Scalar(0));		//50�� 512��, 50x512 ���� 
	Mat image2(50, 512, CV_8UC1, Scalar(0));

	for (int i = 0; i < image1.rows; i++) {			//��� ��ü ��ȸ 
		for (int j = 0; j < image1.cols; j++) {

			image1.at<uchar>(i, j) = j/2;			//image ���� 512�̱� ������ 255���� ���� ��� �������� 2�� ��������Ѵ�. 
			image2.at<uchar>(i, j) = (j / 20) * 10; //������� 
		}
	}

	imshow("image1", image1);
	imshow("image2", image2);

	waitKey();

	return 0;
}