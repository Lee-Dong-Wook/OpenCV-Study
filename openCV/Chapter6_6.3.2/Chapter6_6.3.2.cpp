#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.2 cv::calcHist() �̿�

//6.3.1�� ������ ������׷��� ���������� opencv�� ������׷����̺귯���� �ִ�. 

  //void calcHist(const Mat *image,		�������� �迭 - CV_8U or CV_32F ������ ũ�Ⱑ ���ƾ���
		//		  int nimage,			�������� ���� 
		//		  const int *channels,  ������׷� ��꿡 ���Ǵ� ���� ��� 
		//		  InputArray mask,      Ư�� ������ ����ϱ� ���� ����ũ ��� - �Է� ����� ���� ũ���� 8��Ʈ �迭 
		//		  OutputArray hist,     ���� ������׷��� ��µǴ� �迭 
		//		  int dims,				������׷��� ���� �� 
		//		  const int *histSize,	�� ������ ������׷� �迭 ũ�� - ���(bin)�� ���� 
		//		  float **ranges,       �� ������ ������׷� ���� 
		//		  bool uniform,			������׷��� ����(uniform)������ ��Ÿ���� �÷���
		//		  bool accumulate);		�����÷��� - ���� �迭���� ���� ������׷��� ���� �� ��� 

void calc_Histo(const Mat& image, Mat &hist, int bins, int range_max = 256) {

	int			 histSize[]		= { bins };						//������׷� ��� ���� 
	float		 range[]		= { 0, (float)range_max };		//0�� ä�� ȭ�� �� ���� 
	int			 channels[]		= { 0, };						//ä�� ��� - ���� ä�� 
	const float* ranges[]	    = { range };					//��� ä�� ȭ�� ���� 

	//��������, ���󰳼�, ä��, ����ũ���, ������, ������, ��ް���, ȭ�ҹ���
	calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);	 //histSize : calcHist��  ���� ä����Ŀ� ���� �� ä���� ��� ������ �迭�� ����
}																		 //ranges   : �� ä���� ������ ��� ��� ä���� ���� ����
																		 //           range[]�迭�� �� ä�ι����� �̰��� �� ���� ä�� �迭�α��� 
																	     //Mat()	: ����ũ��� �������� ������ �⺻ �ڷ����� ���� 		

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee3.jpg");
	CV_Assert(!image.empty());

	Mat hist;
	calc_Histo(image, hist, 256);					//������׷� ���, ���⼭�� �μ��� ��������, ������׷� ���, ��� ��
													//range_max ����� 256���� �ʱ�ȭ �Ǿ����Ƿ� �μ��� ���� ������ 256�̴�. 
	cout << hist.t() << endl;						//������ ����� ��ġ�Ͽ� ���� �׷����� ����  

	imshow("image", image);


	waitKey();
	return 0;
}