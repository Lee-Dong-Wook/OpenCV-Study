#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.4 ��� ��Ʈ ���� 
//���� 8���� ������� �ǰڴ�. 

//0�� balck , black �̿��� ��� ������ 1 
//0 = false, 1 = true 


int main() {

	Mat image1(300, 300, CV_8U, Scalar(0));				//300�� x 300�� ������ ���� ����
	Mat image2(300, 300, CV_8U, Scalar(0));				//300�� x 300�� ������ ���� ����
	Mat image3, image4, image5, image6;
	
	imshow("pre_image1", image1);						
	imshow("Pre_image2", image2);						

	Point center = image1.size() / 2;									//���� �߽���ǥ ��� 
	circle(image1, center, 100, Scalar(255,0,0),-1);						//image1�� ���� �߽����� ���� 100�� ���������� ������� -1�β��� ���׸��� 
	rectangle(image2, Point(0, 0), Point(150, 300), Scalar(255), -1);   //image2�� ���� 0,0����, 150,300������ ���� �簢���� �����
																		//-1 �β��� ������� �簢�� ���� 							

	imshow("circle_image1", image1);
	imshow("rect_image2", image2);

	//��Ʈ ���� (�Է�, �Է�, ��� )
	bitwise_or (image1, image2, image3);								//circle_image1�� rect_image2�� ��Ʈ���� or -> ���Ͽ� true�� ������� 
	bitwise_and(image1, image2, image4);								//circle_image1�� rect_image2�� ��Ʈ���� and -> ���ؼ� true�� ������� 
	bitwise_xor(image1, image2, image5);								//circle_image1�� rect_image2�� ��Ʈ���� xor 
	bitwise_not(image1, image6);										//circle_image1�� ���� 	

	imshow("image1",	  image1);
	imshow("image2",      image2);
	imshow("bitwise_or",  image3);
	imshow("bitwise_and", image4);
	imshow("bitwise_xor", image5);
	imshow("bitwise_not", image6);

	waitKey();
	return 0;
}

