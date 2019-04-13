#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.4 ���� ������ �׷� �׸��� 

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


Mat make_palatte(int rows) {										//hue ä�ο� ���� ���� �ȷ�Ʈ ��� ���� 

	Mat hsv(rows, 1, CV_8UC3);										//���� �ȷ�Ʈ ��� ����, ����, ä��, �ֵ��� ������ 3ä�� 

	for (int i = 0; i < rows; i++) {								//�� ����ŭ �ݺ� 
			
		uchar hue = saturate_cast<uchar>((float)i / rows * 180);	//���� ���, ����� �ε���(i)�� hue������ ��� * hue�� 0~180���� ���� ���� *
		hsv.at<Vec3b>(i) = Vec3b(hue, 255, 255);					//HSV �÷� ���� , 3ä�� ȭ�Ұ� ���� 
	}
	 
	cvtColor(hsv, hsv, COLOR_HSV2BGR);								//HSV �÷� -> BGR �÷�
																	//������ HSV�� ������ ����Ϳ� ǥ���ϱ� ���ؼ� BGR�� ǥ�� 
	return hsv;
}

//�������� ������ �׷� �׸���
void draw_histo_hue(Mat hist, Mat &hist_img, Size size = Size(256, 200)) {

	Mat hsv_palatte = make_palatte(hist.rows);						//���� �ȷ�Ʈ ���� make_palatte()�Լ��� ����׷����� �� ��� ������ ��ķ� ��ȯ 

	hist_img = Mat(size, CV_8UC3, Scalar(255, 255, 255));
	float bin = (float)hist_img.cols / hist.rows;					//��� ����,�� ����� �ʺ� 256/200 = 1.28
	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);			//�ּڰ��� 0, �ִ��� �׷��� ������ ����(hist_img.rows)���� ������ ������׷� �󵵰� ����

	for (int i = 0; i < hist.rows; i++) {

		float start_x	= (i * bin);
		float end_x		= (i + 1) * bin;

		Point2f pt1(start_x, 0);
		Point2f pt2(end_x, hist.at<float>(i));

		Scalar color = hsv_palatte.at<Vec3b>(i);					//���� �ȷ�Ʈ ������ 
		
		if (pt2.y > 0) rectangle(hist_img, pt1, pt2, color, -1);	//�ȷ�Ʈ ������ �׸��� 
	}

	flip(hist_img, hist_img, 0);									//���� ������ 	
}

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee3.jpg", 1);	//�÷� ���� �б� 
	CV_Assert(!image.empty());

	Mat HSV_img, HSV_arr[3];
	cvtColor(image, HSV_img, COLOR_BGR2HSV);									//Hue�� ���� ������׷� ����� ���� BGR �÷� -> HSV �÷� 
	split(HSV_img, HSV_arr);													//HSV_img ��� ä�� �и� 
																				//[0] Hue(����), [1] Saturation(ä��), [2] Value(��)	

	Mat hue_hist, hue_hist_img;
	calc_Histo(HSV_arr[0], hue_hist, 18, 180);									//Hue ä�� ������׷� ���
																				//��� ������ 18�� ��~��, 0~179���� ������ ���� �� ���

	draw_histo_hue(hue_hist, hue_hist_img, Size(360, 200));						//������׷� �׷��� 

	imshow("image", image);
	imshow("Hue_hist_img", hue_hist_img);

	waitKey();
	return 0;
}