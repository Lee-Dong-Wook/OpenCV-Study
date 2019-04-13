#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.3 �÷� ���� ��ȯ(BGR -> HSI)

//����(Hue), ä��(Saturation), ��(Intensity value)
//������ ������ 0~360������ ȸ���ϸ� ǥ�� 

//ä���� ���� ������ ����, ����(pure color)�� ����� ȥ�� ������ ���� 0~100���� ��
//�÷� ���������� ä���� ������ ���������� ǥ��, ������ �߽��� 0(���� ���� ����), ���� �ڸ��� 100(���� ���� ����)

//���� ���� ����, ���� ��� ��ο� ���� 
//�÷� ���������� ������ ����, ���� �Ʒ��� 0(Black), ���� ���� 100(White) 

//�Ʒ� ���ô� ���� HSI�� ������ ���� cv::cvtColor()�� ����� ��츦 ���Ѵ� 

//������ 
//����� �����Լ��� cvtColor()���� ���Ǻ�������� ������ ������ ���� ������ ũ�⸸ŭ 2�� for���� �ݺ��Ͽ� 
//acos() �Լ����� �����ϱ� ������ ũ�Ⱑ ū ���� �����ϸ� ��������� ���� �ð��� �ҿ�ȴ�. 


void bgr2hsi(Mat img, Mat &hsi) {				//BGR �÷� -> HSI �÷� 

	hsi = Mat(img.size(), CV_32FC3);			//HSI ��� - 3ä��, float�� 
	
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {

			float B = img.at<Vec3b>(i, j)[0];	
			float G = img.at<Vec3b>(i, j)[1];
			float R = img.at<Vec3b>(i, j)[2];

			float s = 1 - 3 * min(R, min(G, B)) / (R + B + G);		//ä�� ��� 
			float v = (R + G + B) / 3.0f;							//�� ��� 

			float tmp1  = ((R - G) + (R - B)) + 0.5f;
			float tmp2  = sqrt((R - G)*(R - B) + (G - B)*(G - B));
			float angle = acos(tmp1 / tmp2) * (180.0f / CV_PI);		//acos()�� ���ڻ����� �����ִ� �Լ��� ���� ���� ��ȭ�ϱ� ������ 
																	//180 / CV_PI�� ���ص� ������ ��ȯ�Ѵ� 
			
			float h = (B <= G) ? angle : 360 - angle;				//���� ��� 
					
								//3ä�� float������� ,0~1 �������� 0~255�� ���� 
			hsi.at<Vec3f>(i, j) = Vec3f(h / 2, s * 255, v);			//��ȯ��� ���ҿ� ���� 
																	//���� h,s,v ���� ��ȯ��Ŀ� ����, Hue ä���� 0~360���� ���µ�,
																	//uchar���� 0~255�� �����⿡ �������� �������ؼ� 0~180 ������ ����
																	//s ������ 0~1�� ���� ���⿡ 255�� ���ؼ� 0~255������ ���� �Ѵ�. 	
		}
	}
	hsi.convertTo(hsi, CV_8U);
}

int main() {

	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Mat HSI_img, HSV_img, hsi[3], hsv[3];

	bgr2hsi(BGR_img, HSI_img);								//BGR -> HSI ��ȯ 
	cvtColor(BGR_img, HSV_img, COLOR_BGR2HSV);				//OPENCV �Լ� 

	split(HSI_img, hsi);
	split(HSV_img, hsv);


	imshow("BGR_img",			BGR_img);
	imshow("Hue",				hsi[0]);
	imshow("Saturation",		hsi[1]);
	imshow("Intensity",			hsi[2]);
	imshow("openCV Hue",		hsv[0]);
	imshow("openCV Saturation", hsv[1]);
	imshow("openCV Intensity",	hsv[2]);
	
	waitKey();
	return 0;
}