#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.2.1 ä�� �и� �� �ռ� 
//�÷� ������ R,G,B ���� �������� 2���� ������ ���� ���� �迭
//c���� 3������ķ� ������ �Ͱ� �޸� openCV���� ���� ���� 3ä�� Mat ��� pixel-wise ������� ��ȸ�Ѵ�. 
//1pixel�� BGR�� �Ǿ��ְ� 1�� 3���� ǥ���ȴ�. 
//������ ó���� �� �� R,G,B ä���� ���� ��� ó���ϴ� ����̴�. 

int main() {

	Mat ch0(3, 4, CV_8U, Scalar(10));		//���� ä�� ����, 1ä�� uchar ��� ���� �� �ʱ�ȭ  
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));

	Mat bgr_arr[] = { ch0, ch1, ch2 };		//ä�� �迭, ���� ä�� 3���� ���ҷ� ���� �迭  
	Mat bgr;								//ä�� �ռ� ��� 

	merge(bgr_arr, 3, bgr);					//ä�� �ռ�, �Է��� �迭�� ��� �ռ��� ��� ���� �Է� 
	vector<Mat> bgr_vec;
	split(bgr, bgr_vec);					//3ä�� ����� 3�� ���� ����� ���� ���ͷ� �и�  

	cout << "[ch0] = " << endl << ch0 << endl;
	cout << "[ch1] = " << endl << ch1 << endl;
	cout << "[ch2] = " << endl << ch2 << endl;

	cout << "[bgr] = " << endl << bgr << endl;
	cout << "[bgr_vec[0]] = " << endl << bgr_vec[0] << endl;
	cout << "[bgr_vec[1]] = " << endl << bgr_vec[1] << endl;
	cout << "[bgr_vec[2]] = " << endl << bgr_vec[2] << endl;
	waitKey();
	return 0;
}

