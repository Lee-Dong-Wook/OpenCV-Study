#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


//�÷����� ������ �Է¹޾� RGB 3�� ä�η� �и�, �� ä���� �÷� �������� ������ ǥ������.
//Red ä�� -> Red, Green ä�� -> Green, Blue ä�� -> Blue �� ǥ�� 

//���� ä�� ����� imshow()�� ����ϸ� ��ϵ� ������ ���, �÷� ������ ����ϸ� 3�� ä���� �ռ��� ����̾���.
//�÷� ������ �и��ϰ� �и��� ���� ä�� ��ĵ��� ��� �ϸ� �ش� ������ ǥ���ϴ� �÷� �������� �ռ�����? 

//merge(), split(), vector�� �̿����� 

int main() {
	
	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/opencvLogo.png",1);		//���, �÷�Ÿ�� ��� p.168 imread()
	Mat bgr[3];
	Mat blue_img, green_img, red_img;
	Mat zero(image.size(), CV_8U, Scalar(0));

	split(image,bgr);
															
	imshow("original image", image);			//�����̹���
	imshow("Blue_image", bgr[0]);				//B ä�� 	
	imshow("Green image", bgr[1]);				//G ä��
	imshow("Red image", bgr[2]);				//R ä��
	imshow("black zero", zero);					//������ ���� 

	vector<Mat> vecB, vecG, vecR;

	vecB.push_back(bgr[0]);						//3ä�η� B�Ӽ��� 
	vecB.push_back(zero);		
	vecB.push_back(zero);

	vecG.push_back(zero);		
	vecG.push_back(bgr[1]);						//3ä�η� Gä�θ�	
	vecG.push_back(zero);

	vecR.push_back(zero);
	vecR.push_back(zero);
	vecR.push_back(bgr[2]);						//3ä�η� Rä�θ� 	

	Mat B, G, R;

	merge(vecB,B);								//vector ��ġ�� 	
	merge(vecG,G);
	merge(vecR,R);

	imshow("Only Blue",		B);
	imshow("Only Green",	G);
	imshow("Only Red",		R);

	waitKey();
	return 0;
}


