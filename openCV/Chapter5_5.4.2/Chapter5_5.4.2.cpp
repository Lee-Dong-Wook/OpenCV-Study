#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.4.2 ��� �ּڰ� �� �ִ� ���� 1

//�� ����� �� ���Ҹ� ��, ū ���̳� ���� ������ ��� ã�´�. 
//�ϳ��� ��� ������ ū ���̳� ���� ���� ���� ��ġ�� �˸� ������׷� �׷��� �׸��⳪ �ٸ� ��Ŀ��� ��� ���� 
//src1�� src2�� ���ؼ� ���߿� ũ�ų� ���� ���� �ش� ���ҿ� ���� 

//cv::max(), cv::min(), cv::minLoc()

int main() {

	uchar data[] = {

		10,200,5,7,9,
		15,35,60,80,170,
		100,2,5,37,70
	};

	Mat m1(3,5,CV_8U,data);
	Mat m2(3,5,CV_8U,Scalar(50));
	Mat m_min, m_max;					//�ּ�, �ִ밪 ��� 
	
	double minVal, maxVal;
	int minIdx[2] = {}, maxIdx[2] = {};	//�ּڰ� ��ǥ, �ִ� ��ǥ 
	
	Point minLoc, maxLoc; 
										
	min(m1, 30, m_min);					//�� ��� ���� �� �ּڰ� ���� 
	max(m1, m2, m_max);					//����� �ִ� ��� 
	
	minMaxIdx(m1, &minVal, &maxVal, minIdx, maxIdx); //m1�� �ּڰ�, �ִ�, �ּڰ� ��ġ, �ִ� ��ġ
	minMaxLoc(m1, 0, 0, &minLoc, &maxLoc);			//m1�� �ּڰ�, �ִ�, �ּڰ� ��ġ, �ִ� ��ġ , Point ��ü�� ����	

	cout << "[m1] = " << endl << m1 << endl << endl;
	cout << "[m_min] = " << endl << m_min << endl << endl;
	cout << "[m_max] = " << endl << m_max << endl << endl;

	cout << "m1 ��� ���� �ּڰ� :  " << endl << minVal << endl << endl;
	cout << "�ּڰ� ��ǥ : " << endl << minIdx[1] << " , " << minIdx[0] << endl << endl;

	cout << "m1 ��� ���� �ִ� : " << endl << maxVal  << endl << endl;
	cout << "�ִ� ��ǥ : " << endl << maxIdx [1] << " , " << maxIdx[0] << endl << endl;

	cout << "m1 �ּڰ� ��ǥ :  " << endl << minLoc << endl << endl;
	cout << "m1 �ִ� ��ǥ : " << endl << maxLoc << endl << endl;
	return 0;
}

