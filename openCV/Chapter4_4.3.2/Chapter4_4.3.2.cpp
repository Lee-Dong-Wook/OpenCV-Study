#include <opencv2/opencv.hpp>


using namespace cv;
using namespace std;

//4.3.2 ���ھ��� 
//cv::putText()
//ǥ�� ���ڿ��� ���� ��ǥ�� ���ڿ��� ������ �ϴ����� �����ؾ��Ѵ�. 

int main() {

	Scalar olive(128, 128, 0), violet(221, 160, 221), brown(42, 42, 165);	//���� ���� 
	Point  pt1(20, 100), pt2(20, 200), pt3(20, 250);						//���ڿ� ��ġ ��ǥ 

	Mat image(300, 500, CV_8UC3, Scalar(255, 255, 255));					//3ä�� uchar ��� ���� �� ���(255)�ʱ�ȭ 

	putText(image, "SIMPLEX", Point(20, 30), FONT_HERSHEY_SIMPLEX, 1, Scalar(42, 42, 165));
	putText(image, "DUPLEX" , pt1, FONT_HERSHEY_DUPLEX, 2, olive);
	putText(image, "TRIPLEX", pt2, FONT_HERSHEY_TRIPLEX, 3, violet);
	putText(image, "ITALIC" , pt3, FONT_HERSHEY_PLAIN | FONT_ITALIC, 2, violet);

	imshow("���ھ���", image);
	waitKey(0);	
	return 0;
}


