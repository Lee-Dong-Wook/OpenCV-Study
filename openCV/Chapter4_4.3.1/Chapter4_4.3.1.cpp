#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

//4.3.1 ���� �� �簢�� �׸��� 
//cv::line(), cv::rectangle()

int main() {

	Scalar blue(255, 0, 0), red(0, 0, 255), green(0, 255, 0);		//���� ����
	Scalar white = Scalar(255, 255, 255);							//���
	Scalar yellow = Scalar(0, 255, 255);

	Mat image(400, 600, CV_8UC3, white);							//3ä�� uchar ��� ���� �� ���(255) �ʱ�ȭ 
	Point pt1(50, 130), pt2(200, 300), pt3(300, 150), pt4(400, 50); //��ǥ ���� 
	Rect rect(pt3, Size(200, 150));									//�簢�� ���� 300,150 ���� 200x150ũ�� 
	
	line(image, pt1, pt2, red);										//���� �׸��� 
	line(image, pt3, pt4, green, 2, LINE_AA);						//��Ƽ���ϸ��� �� 
	line(image, pt3, pt4, green, 3, LINE_8, 1);						//8���� ���ἱ, 1��Ʈ ����Ʈ 

	rectangle(image,rect,blue,2);									//�簢�� �׸��� 	
	rectangle(image,rect,blue,FILLED,LINE_4,1);						//4���� ���ἱ, 1��Ʈ ����Ʈ 		
	rectangle(image,pt1,pt2,red,3);

	imshow("���� & �簢��", image);
	waitKey(0);
	return 0;
}

