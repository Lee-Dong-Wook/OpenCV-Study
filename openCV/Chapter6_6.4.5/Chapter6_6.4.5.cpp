#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.5 hue ä���� �̿��� ��ü ���� 

//�Է� ������ HSV�÷� �������� ��ȯ�� �� Hue ä���� �̿��� Ư�� ���� ������ ����
//�� ������ ���� ���������� ����ȭ�ϴ� ���� 

Range th(50, 100);								//Ʈ���ٷ� ������ ���� ���� default ��
Mat	  hue;										//���� ä�� �������� ���� 

void onThreshold(int value, void* userdata) {

	Mat result = Mat(hue.size(), CV_8U, Scalar(0));

	//���� ������ ����ȭ ���� 
	for (int i = 0; i < result.rows; i++) {
		for (int j = 0; j < result.cols; j++) {	//���ù����� ���� ���� ���� 

			bool ck =  hue.at<uchar>(i, j) >= th.start && hue.at<uchar>(i, j) < th.end;     //����� �� ȭ�Ұ� ���� ���� ������ ũ��, ���� ���ᰪ���� ������ ��
			result.at<uchar>(i, j) = (ck) ? 255 : 0;										//result ��� ���ҿ� ck�� ���̸� ���255, �����̸� 0���� 
																													
		}
	}

	imshow("result",result);
}

int main() {
   
	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg", 1);			
	CV_Assert(BGR_img.data);

	Mat HSV, hsv[3];
	cvtColor(BGR_img, HSV, COLOR_BGR2HSV);					//�÷� ���� ��ȯ 
	split(HSV,hsv);											//ä�� �и� 
	hsv[0].copyTo(hue);										//hue ��Ŀ� ���� ä�� ���� 

	namedWindow("result", WINDOW_AUTOSIZE);

	createTrackbar("Hue_th1","result", &th.start,255, onThreshold);
	createTrackbar("Hue_th2", "result", &th.end, 255, onThreshold);

	//onThreshold();

	imshow("BGR_img", BGR_img);
	waitKey(0);
	waitKey();
	return 0;
}