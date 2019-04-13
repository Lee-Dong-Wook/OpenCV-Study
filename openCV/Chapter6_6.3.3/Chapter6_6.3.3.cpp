#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.3 ������׷� �׷��� �׸��� 

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

	int			 histSize[] = { bins };						//������׷� ��� ���� 
	float		 range[] = { 0, (float)range_max };			//0�� ä�� ȭ�� �� ���� 
	int			 channels[] = { 0, };						//ä�� ��� - ���� ä�� 
	const float* ranges[] = { range };						//��� ä�� ȭ�� ���� 

	//��������, ���󰳼�, ä��, ����ũ���, ������, ������, ��ް���, ȭ�ҹ���
	calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);	 //histSize : calcHist��  ���� ä����Ŀ� ���� �� ä���� ��� ������ �迭�� ����
}																		 //ranges   : �� ä���� ������ ��� ��� ä���� ���� ����
																		 //           range[]�迭�� �� ä�ι����� �̰��� �� ���� ä�� �迭�α��� 
																		 //Mat()	: ����ũ��� �������� ������ �⺻ �ڷ����� ���� 		


void draw_histo(Mat hist, Mat &hist_img, Size size = Size(256, 200)) {

	hist_img	= Mat(size, CV_8U, Scalar(255));				//�׷��� �����̹��� ��� 
	float bin	= (float)hist_img.cols / hist.rows;			//�� ����� �ʺ� 256/200 	= 1.28
	
	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);	//�ּڰ��� 0, �ִ��� �׷��� ������ ����(hist_img.rows)���� ������ ������׷� �󵵰� ����
															 							

	for (int i = 0; i < hist.rows; i++) {

		float	start_x		     = i * bin;					//����,������ǥ ���, start_x�� ���� ��ĭ�� ũ��(bin)�� ���� �ε���i�� ���ϰ�		
		float	end_x		     = (i + 1) * bin;			//end_x�� ��ĭ ���� �ε���(i+1)�� ���Ѵ�. 

		Point2f pt1(start_x, 0);							//���� �簢�� ���� x��ǥ start_x, 0					
		Point2f pt2(end_x, hist.at<float>(i));				//���� �簢�� ���� y��ǥ end_x, �󵵰� 
															//������ǥ�� ������ǥ ������ �Ÿ��� bin = hist_img.cols(�׷����ʺ�) / hist.rows(��ް���)?
																		
		if (pt2.y > 0) {									//�ش� ȭ�Ұ� 1���� �ִٸ� ���� �簢�� �׸���
			rectangle(hist_img, pt1, pt2, Scalar(0), -1);	//�ش���ǥ�� ���θ� ä��� �簢�� �׸��� 
		}
	}
	flip(hist_img, hist_img, 0);							//x�� ���� ���� ������ 
}
int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee3.jpg");
	CV_Assert(!image.empty());

	Mat hist, hist_img;
	calc_Histo(image, hist, 256);					//������׷� ���, ���⼭�� �μ��� ��������, ������׷� ���, ��� ��
													//range_max ����� 256���� �ʱ�ȭ �Ǿ����Ƿ� �μ��� ���� ������ 256�̴�. 
	
	draw_histo(hist, hist_img);

	imshow("image", image);
	imshow("hist_img", hist_img);

	waitKey();
	return 0;
}