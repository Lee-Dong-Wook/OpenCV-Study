#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;

int main() {

	//RotatedRect Ŭ���� 

	Mat		image(300, 500, CV_8UC1, Scalar(255)); //��ļ���, 300��, 500�� 1ä�� uchar ��� ���� �� ���� 255�� �ʱ�ȭ -> ��� ������  
	Point2f center(250, 150);					   //ȸ���簢���� �߽��� 
	Point2f pts[4];
	Size2f	size(300, 100);						   //ȸ���簢���� ũ�� ���� ����
	RotatedRect rot_rect(center, size, 20);		   //ȸ�� �簢�� ���� 

	Rect bound_rect = rot_rect.boundingRect();	   //ȸ���簢���� 4�� �𼭸��� ��� �����ϴ� �ּ�ũ���� �簢�� ������ ��ȯ�Ѵ�.
	rectangle(image, bound_rect, Scalar(0), 1);	   //1�ȼ� ������ �簢�� �׸���
	circle(image, rot_rect.center, 1, Scalar(0), 2);   //2�ȼ� ������ �� �׸��� circle(image, center, radius, color, pixel)
	rot_rect.points(pts);						   //ȸ���簢�� ������ ��ȯ 

	for (int i = 0; i < 4; i++) {

		circle(image, pts[i], 4, Scalar(0), 1);					 //������ ǥ�� 	
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0), 2); //������ �մ� ���� 	
	}
	
	imwrite("image.jpg",image);
	imshow("ȸ���簢��", image);
	waitKey();
	return 0;
}