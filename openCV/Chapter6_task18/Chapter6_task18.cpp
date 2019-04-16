#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//�÷������� �Է� �޾� YCbCr�÷� �������� ��ȯ�ϰ� �ٽ� ȯ���ϴ� ���α׷� �ۼ� 

Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);


void bgr2Ycbcr(Mat img, Mat &ycbcr);

void Ycbcr2Bgr(Mat img, Mat &bgr);

int main() {

	CV_Assert(image.data);

	Mat openCV_bgr2ycbcr,		//openCV - BGR -> YCbCr
		bgr_img,				//openCV - YCbCr -> BGR
		bgr2ycbcr,				//		   BGR -> YCbCr
		ycbcr2bgr;				//		   YCbCr -> BGR
		

	imshow("Original_BGR_image", image);
	
	cvtColor(image, openCV_bgr2ycbcr, COLOR_BGR2YCrCb);
	imshow("OpenCV_BGR -> YCbCr", openCV_bgr2ycbcr);

	cvtColor(openCV_bgr2ycbcr, bgr_img, COLOR_YCrCb2BGR);
	imshow("OpenCV_YCbCr -> BGR", bgr_img);


	bgr2Ycbcr(image, bgr2ycbcr);
	imshow("BGR -> YCbCr", bgr2ycbcr);

	Ycbcr2Bgr(bgr2ycbcr, ycbcr2bgr);
	imshow("YCbCr -> BGR", ycbcr2bgr);

	
	waitKey(0);
	return 0;
}


void bgr2Ycbcr(Mat img, Mat &ycbcr) {					//�̹��� �� �ȼ��� 1byte BGR, 3ä�� �÷� �����̴�. CV_8UC3
														//ycbcr ����� ���Ǵ� �������� float���̱� ������ 3ä�� float������ �����Ѵ�. 
	ycbcr = Mat(img.size(), CV_32FC3);

	for (int i = 0; i < img.rows; i++) {				//�̹��� ��ü ��ȸ 
		for (int j = 0; j < img.cols; j++) {

			float B		= img.at<Vec3b>(i, j)[0];			//BGR ������ ��Ұ� ���� ������ BGR������ ���Ϳ� ����
			float G		= img.at<Vec3b>(i, j)[1];
			float R		= img.at<Vec3b>(i, j)[2];

			float Y		= 0.299f * R + 0.587f * G + 0.114f * B;		//�ֵ�
			float Cb	= (R - Y) * 0.564f + 128;					//�������� 
			float Cr	= (B - Y) * 0.713f + 128;

			ycbcr.at<Vec3f>(i, j) = Vec3f(Y, Cb, Cr);	//float�� Y, Cb, Cr ���� vector�� ���� ��Ŀ� ���� 
		}
	}
	ycbcr.convertTo(ycbcr, CV_8UC3);					//����� �̹��� ���·� �ϱ� ������ float���� byte������ ��ȯ�Ѵ�. 
}


void Ycbcr2Bgr(Mat img, Mat &bgr) {
														
	bgr = Mat(img.size(), CV_32FC3);

	for (int i = 0; i < img.rows; i++) {				//�̹��� ��ü ��ȸ 
		for (int j = 0; j < img.cols; j++) {

			float Y		= img.at<Vec3b>(i, j)[0];			
			float Cb	= img.at<Vec3b>(i, j)[1];			//Cb, Cr�� ���� ����� ���ϴ�. 
			float Cr	= img.at<Vec3b>(i, j)[2];
		
			float R		= Y + 1.403f*(Cr - 128);
			float G		= Y - 0.714f*(Cb - 128) - 0.344f*(Cb - 128);
			float B		= Y + 1.7773f*(Cb - 128);
			
			

			bgr.at<Vec3f>(i, j) = Vec3f(R, G, B);	//float�� Y, Cb, Cr ���� vector�� ���� ��Ŀ� ���� 
		}
	}
	bgr.convertTo(bgr, CV_8UC3);					//����� �̹��� ���·� �ϱ� ������ float���� byte������ ��ȯ�Ѵ�. 
}
