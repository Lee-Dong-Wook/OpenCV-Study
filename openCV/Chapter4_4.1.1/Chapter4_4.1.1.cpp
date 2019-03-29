#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

	//4.1.1 ������(���� ���â) �̵�
	
	Mat image1(300, 400, CV_8U, Scalar(255));			//������� ���� ����
	Mat image2(300, 400, CV_8U, Scalar(100));			//ȸ������ ���� ����
	string title1 = "whiteâ ����";						//������ �̸� 
	string title2 = "gray â ����";

	namedWindow(title1, WINDOW_AUTOSIZE);				//������ �̸� ����, cv::imshow()�Լ��� �ԷµǴ� 
														//����� ũ�⿡ ���� ����,âũ�� ����Ұ�
	namedWindow(title2, WINDOW_NORMAL);					//â ũ�Ⱑ ���Ƿ� ����, ��� �ڰ� ���콺�� â�� ũ�� ���� ����
	moveWindow(title1, 100, 200);						//������ �̵�(������� ��ġ��) 
	moveWindow(title2, 300, 200);

	imshow(title1, image1);								//��� ���Ҹ� �������� ǥ�� 
	imshow(title2, image2);
	waitKey();											//Ű �̺�Ʈ ��� 
	destroyAllWindows();								//���� ��� ������ ���� 
	
	return 0;
}

