#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.6 ������׷� ��Ȱȭ 

//����ó������ ������׷��� �ٷ�� ��Ȱȭ�� �ݵ�� ����´�. 
//������׷� ��Ȱȭ�� ������ �ǹ��� "������ �յ�"�̶�� ����� �̿��� ��ϴ�� ������Ų��. 
//������ ������ �� ������ ȭ�� ������ ���� 

//��Ʈ��Ī�� ������ ���� ������ ��Ʈ��Ī �Ͽ� ������ �а� ����. ������ ������ ������ ������ Ư�� �κ�
//���� �������� ġ��ģ ��� ������ ���� ���� �ִ�. 

//�̷����� ������׷� ��Ȱȭ�� ��� 

//��Ȱȭ ����
//1. ������ ������׷� ���
//2. ������׷� �󵵰����� �����󵵼�(������) ���
//3. ���� �󵵼��� ����ȭ(����ȭ ������)
//4. ��� ȭ�Ұ� :�Է�ȭ�� ����ȭ ������ * �ִ� ȭ�Ұ� 

//���� �󵵼� ��� 
//p.322 Ȯ��
//ȭ�Ұ� 2�ΰ�� ȭ�Ұ� 0�� 1�� ���� 1�� 5�� ���� �ڽ��� ���� 6�� �������� ��������� 12�� �ȴ�.
//������ȭ�Ұ�7�� �̸������ �󵵼��� ����, ��� ��ü ȭ�Ұ����� ���� 16

//ȭ���� ���� �󵵼��� ��ü ȭ�Ұ���16���� ������ ����ȭ�Ͽ� ����ȭ �������� ���
//����ȭ�� ���� �߿��� �ִ����� �� ���Ҹ� ������ ���ҵ��� ���� 0~1���� ���� ������ ǥ�� 

//�Է�ȭ�� 2��� ����ȭ �������� �����󵵼� 12 / ��üȭ�� 16 = 0.75
//��Ȱȭ ��� ȭ�� �� = 0.75 * 7 = 5.25 , ��Ȱȭ ��� ���� 5 
//ȭ�Ұ� 2-> 5�� ���� 

//cv::equalizeHist()�̿�� ���� ������ ���� �������� ���� 

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

	hist_img = Mat(size, CV_8U, Scalar(255));				//�׷��� �����̹��� ��� 
	float bin = (float)hist_img.cols / hist.rows;			//�� ����� �ʺ� 256/200 	= 1.28

	normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);	//�ּڰ��� 0, �ִ��� �׷��� ������ ����(hist_img.rows)���� ������ ������׷� �󵵰� ����


	for (int i = 0; i < hist.rows; i++) {

		float	start_x = i * bin;							//����,������ǥ ���, start_x�� ���� ��ĭ�� ũ��(bin)�� ���� �ε���i�� ���ϰ�		
		float	end_x = (i + 1) * bin;						//end_x�� ��ĭ ���� �ε���(i+1)�� ���Ѵ�. 

		Point2f pt1(start_x, 0);							//���� �簢�� ���� x��ǥ start_x, 0					
		Point2f pt2(end_x, hist.at<float>(i));				//���� �簢�� ���� y��ǥ end_x, �󵵰� 
															//������ǥ�� ������ǥ ������ �Ÿ��� bin = hist_img.cols(�׷����ʺ�) / hist.rows(��ް���)?

		if (pt2.y > 0) {									//�ش� ȭ�Ұ� 1���� �ִٸ� ���� �簢�� �׸���
			rectangle(hist_img, pt1, pt2, Scalar(0), -1);	//�ش���ǥ�� ���θ� ä��� �簢�� �׸��� 
		}
	}
	flip(hist_img, hist_img, 0);							//x�� ���� ���� ������ 
}

void create_hist(Mat img, Mat &hist, Mat &hist_img) {

	int histsize = 256, range = 256; 
	
	calc_Histo(img, hist, histsize, range);		
	draw_histo(hist, hist_img);
}

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg", 0);	//��ϵ� ���� �ε� 
	CV_Assert(!image.empty());

	Mat hist, dst1, dst2, hist_img, hist_img1, hist_img2;

	create_hist(image, hist, hist_img);											//������׷� �� �׷��� �׸��� 

	//������׷� �����հ��
	Mat accum_hist = Mat(hist.size(), hist.type(), Scalar(0));
	
	accum_hist.at<float>(0) = hist.at<float>(0);
	for (int i = 1; i < hist.rows; i++) {

		accum_hist.at<float>(i) = accum_hist.at<float>(i-1) + hist.at<float>(i);	//������׷� �� ��� 
	}

	accum_hist /= sum(hist)[0];			//�������� ����ȭ(��ü �󵵼� / ���� ������ = 0~1���� ��)
	accum_hist *= 255;					//����ȭ�� ���� 0~255���� ȭ�Ұ��� �ǰ� ����, ��Ȱȭ�� �ٷ� ������ ���� 
	dst1 = Mat(image.size(), CV_8U);

	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; j++) {				//���� ������ ȭ�� ������ ����ȭ ������ ����� ���Ҹ� ������ ��� ������ ȭ�Ұ��� ���� 
			int idx = image.at<uchar>(i, j);								//����ȭ ������ ����� LookUP���̺�� ����� �� 
			dst1.at<uchar>(i, j) = (uchar)accum_hist.at<float>(idx);		//�Է� ȭ�Ұ����� ������ ��� ���Ұ��� ������ �������� ȭ�ҷ� ����
		}
	}

	//Line 103 ~ 106 �� ������ ��� 
	//normalize(accum_hist, accum_hist, 0, 255, NORM_MINMAX);	//�������� ����ȭ 
	//accum_hist.convertTo(accum_hist, CV_8U);				
	//LUT(image, accum_hist, dst1);							//��� ���̺� ���� 

	equalizeHist(image, dst2);								//openCV ������׷� ��Ȱȭ ���̺귯��
	create_hist(dst1, hist, hist_img1);						//������׷� �� �׷��� �׸��� 
	create_hist(dst2, hist, hist_img2);					

	imshow("image", image);
	imshow("user dst1", dst1);
	imshow("opencv dst2", dst2);
	imshow("hist_img", hist_img);							//���� ������׷�
	imshow("user histo", hist_img1);							//����� ��Ȱȭ
	imshow("opencv histo", hist_img2);						//openCV ��Ȱȭ 
	
	waitKey();
	return 0;
}