#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.1 ���� ������ �׷� ��� 

//������׷��� ���������� ���� "���� ���� ������ ��ġ�� �ʴ� �پ��� ������� ǥ���ϴ� ��"
//� �����Ͱ� �󸶳� �������� ��Ÿ���� ���� ����ǥ�� �׷����� ��Ÿ�� ��
//�������� ���(������ ����), ���� ���� ����(���� ���� ���� ��, �󵵼�)

void calc_histo(Mat image, Mat &hist, int bins, int range_max = 256) {

	hist = Mat(bins, 1, CV_32F, Scalar(0));		//��� �� ��ŭ ���� ���� ������׷� ���� ��� 
												//������׷� ������� 
												//bins ������ ����� ��� ����. ������ ������ ����� float��, 0���� �ʱ�ȭ 	

	float gap = range_max / (float)bins;		//��� ����
												//ȭ�Ұ� ���� 0~range_max, ��� ������ bins 
												// 256.0/256.0 = 1.0
												

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {

			int idx = int(image.at<uchar>(i, j) / gap);			//ȭ�Ұ� ���� ��� ��ġ ���
																//ȭ�� ���� gap���� ������ �� ȭ�Ұ� ���ϴ� ����� ����Ͽ� idx�� ���� 
																//�ش�ȭ��(0~255) / gap(=1)�� �ϴ� �ش�ȭ�Ұ� ������ idx�� ����� 

			hist.at<float>(idx)++;								//�ش� ��޿� �� ����
																//idx�� �ε����� hist��� ���ҿ� ����, �� ���� 1�� ���� 
																//�ش� ȭ�Ұ��� ������ �� ����� ���� �󵵼��� ���� 		
																//256�� 1���� hist ��� 
																//256�� �� ���ԵǴ� idx�� ������ 1�� ���� 	
		}
	}
}

int main() {
	
	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee3.jpg");
	CV_Assert(!image.empty());

	Mat hist;
	calc_histo(image, hist, 256);					//������׷� ���, ���⼭�� �μ��� ��������, ������׷� ���, ��� ��
													//range_max ����� 256���� �ʱ�ȭ �Ǿ����Ƿ� �μ��� ���� ������ 256�̴�. 
	cout << hist.t() << endl;						//������ ����� ��ġ�Ͽ� ���� �׷����� ����  

	imshow("image", image);
	

	waitKey();
	return 0;
}