#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.4.3 ��� �ּڰ� �ִ� ���� 

//������׷����� min,max�� �����ؼ� ������ �������� �������� 
int main(){

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/dark.jpg", IMREAD_GRAYSCALE);
	
	
	double minVal, maxVal;
	minMaxIdx(image, &minVal, &maxVal);														//�̹����� �ּҰ�, �ִ밪 ������ ���� 


	double ratio = (maxVal - minVal) / 255.0;
	Mat dst = (image - minVal) / ratio;

	cout << "�ּڰ� = " << minVal << endl; 
	cout << "�ִ� = " << maxVal << endl;

	//resize(image, dst, Size(900, 700), 0, 0, IMREAD_GRAYSCALE);	//�̹��� ũ�� ���� 
	imshow("image", image);
	imshow("dst", dst);
	waitKey();
	return 0;


}

