#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	//4.1.2 ������ ũ�� ���� 
	
	Mat image(300, 400, CV_8U, Scalar(255));			//��� ���� ���� ����, 1ä�� uchar ���, 255�� �ʱ�ȭ  
	string title1 = "â ũ�� ���� 1 - AUTOSIZE";			//������ �̸� 
	string title2 = "â ũ�� ���� 2 - NORMAL";			

	namedWindow(title1, WINDOW_AUTOSIZE);				//������ ũ�� ���� �Ұ�, â �̸� ���� 
	namedWindow(title2, WINDOW_NORMAL);					//������ ũ�� ���� ���� 
	
	resizeWindow(title1, 500, 200);						 
	resizeWindow(title2, 500, 200);						//â ũ�� ����	

	imshow(title1, image);								//title1 â�� image ����� �������� ǥ�� 
	imshow(title2, image);
	waitKey();

	return 0;
}

