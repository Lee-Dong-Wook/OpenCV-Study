#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

//4.3.4 Ÿ�� �׸��� 
//RotatedRectŬ������ �߽� ��ǥ, �簢���� ũ�� ȸ�� ������ ��� �����ϱ⿡ RotatedRect Ŭ������ ��ü�� �̿뤷�ؼ� ���� Ÿ���� �׸� �� �ִ�.
//�ٸ� ���۰����� ���ᰢ���� ���� ������ ȣ�� �׸��� ���Ѵ�. 
//RotatedRect Ŭ�������� �簢���� ũ��� Ÿ���� �������� �ƴ϶� ������ �ǹ��Ѵ�. 

int main() {
	
	Scalar orange(0, 165, 255), blue(255, 0, 0), magenta(255, 0, 255);
	Mat image(300, 700, CV_8UC3, Scalar(255, 255, 255));
	
	Point pt1(120, 150), pt2(550, 150);
	circle(image, pt1, 1, Scalar(0), 1);							//Ÿ�� �߽���(1�ȼ� ��) ǥ��
	circle(image, pt2, 1, Scalar(0), 1);

	//Ÿ�� �׸��� 
	ellipse(image, pt1, Size(100, 60), 0, 0, 360, orange, 2);		//pt1���� 100x60ũ�� �������� Ÿ��(0~360��)
	ellipse(image, pt1, Size(100, 60), 0, 30, 270, blue, 4);		//pt1���� 100x60ũ�� �Ķ��� Ÿ��(30~270��)

	////ȣ �׸��� 
	ellipse(image, pt2, Size(100, 60), 30, 0, 360, orange, 2);		//pt1���� 100x60ũ�� �������� Ÿ��(0~360��)
	ellipse(image, pt2, Size(100, 60), 30, -30, 160, blue, 4);		//pt1���� 100x60ũ�� �������� Ÿ��(30~270��)

	
	imshow(" Ÿ�� �� ȣ �׸��� ",image);
	waitKey(0);
	return 0;
}


