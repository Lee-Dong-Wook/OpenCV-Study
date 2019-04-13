#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.3.5 ������׷� ��Ʈ��Ī 

//��ϵ����� ������ �����ϰ� �����ϰ� ���̷��� ��ο� �κп��� ���� �κб��� ��� �����Ǿ��Ѵ�.
//�׷��� ���� ������ ������׷��� ���� Ư�� �������� ġ������ �ִ�. 
//������׷� ������ ���� ���� ��� ���� ���� ������ ������ �� �ִ� �˰����� ������׷� ��Ʈ��Ī(histogram stretching)�̴�.

//������׷� ������ �ٲ�ٴ� ���� ���� ���� ȭ�Ұ��� ������ �ٲ�ٴ� ��. ������ ȭ���� ����ǰ� ���� �ȴٴ� ���̴�. 
//��Ʈ��Ī�� �Ϸ��� x�� ������ �󵵰��� �����ϴ� ���� ���� ȭ�Ұ�(low value)�� ���� ���� ȭ�Ұ�(high value)�� �˾ƾ��Ѵ�. 
//���� ���� ���� 0���� ���� ���� ���� ���� 255�� ����

//����
//�� ȭ�Ұ� = (ȭ�� �� - low) * 255/x��ȭ��,  x��ȭ�� = high - low

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


int search_valueIdx(Mat hist, int bias = 0) {							//������׷� �󵵰� �����ϴ� ù,������ ��ġ �˻� 

	for (int i = 0; i < hist.rows; i++) {
		int idx = abs(bias - i);										//�˻� ��ġ (ó�� or ������)
		if (hist.at<float>(idx) > 0) return idx;						//��ġ ��ȯ 	
	}
	return -1;															//��� ���� ��ȯ,��� �󵵰��� 0�϶� 
}

int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", 0);	//��ϵ� ���� �ε� 
	CV_Assert(!image.empty());

	Mat hist, hist_dst, hist_img, hist_dst_img;
	int histsize = 64, ranges = 256;				//��� ���� �� ȭ�ҹ���

	calc_Histo(image, hist, histsize,ranges);

	float bin_width		= (float)ranges / histsize;						//��� �ʺ� 
																		//��� ������ ȭ�� ������ ��� �ʺ� ���
																		//��ް����� ȭ�ҹ����� �ٸ� ��츦 ���� ��޳ʺ�� 1�ȼ��� �ƴ� �� �ִ�.
	int   low_value		= (int)(search_valueIdx(hist, 0) * bin_width);	//���� ȭ�Ұ�
	int   high_value    = (int)(search_valueIdx(hist, hist.rows-1) * bin_width);	//�ְ� ȭ�� ��

	cout << "high_value = " << high_value << endl; 
	cout << "low_value = " << low_value << endl;

	int d_value = high_value - low_value;											//��ȭ�� 
	Mat dst = (image - low_value) * (255.0 / d_value);								//������׷� ��Ʈ��Ī 


	calc_Histo(dst, hist_dst, histsize, ranges);									//������� ������׷� ���� 
	draw_histo(hist, hist_img);														//�������� ������׷� �׸���			
	draw_histo(hist_dst, hist_dst_img);												//������� ������׷� �׸��� 	

	imshow("image", image);
	imshow("hist_img", hist_img);
	imshow("dst_image", dst);
	imshow("hist_dst_img", hist_dst_img);

	waitKey();
	return 0;
}