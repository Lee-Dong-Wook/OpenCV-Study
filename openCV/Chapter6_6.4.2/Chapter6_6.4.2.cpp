#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.2 �÷� ���� ��ȯ(BGR->CMYK)

//�÷������� �а� CMY �÷��������� �ٲٰ� �ٽ� CMYK �÷� �������� ���� 

//���� ���� ���� ������ ��Ӵ�. �� ä�� �� ȭ�ҿ��� ���� ��ο� ���� ���� ������ �и��Ͽ� blackä�η� ���
//������ �κи��� �� ������ ��ũ�� ���, CMYK �÷� ������ ����ϸ� �÷� ��ũ�� ����� �����ȴ� 

int main() {

	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Scalar white(255, 255, 255);
	Mat	   CMY_img = white - BGR_img;		//CMYK : ��� �� ��Į�� ���� -> ��� ä���� ��� ȭ�ҿ� ������ ���� 
	Mat    CMY_arr[3];

	split(CMY_img, CMY_arr);

	Mat black;
	min(CMY_arr[0], CMY_arr[1], black);			//���� �� �ּڰ� ����, ���⼭ BLACK�� ���� ȭ���� �ƴ϶� CMY�� �ּҰ��̴� 
	min(black, CMY_arr[2], black);

	CMY_arr[0] = CMY_arr[0] - black;
	CMY_arr[1] = CMY_arr[1] - black;
	CMY_arr[2] = CMY_arr[2] - black;

	imshow("black", black);
	imshow("CMY_img[0] Y", CMY_arr[0]);		//yello
	imshow("CMY_img[1] M", CMY_arr[1]);		//magenta
	imshow("CMY_img[1] C", CMY_arr[2]);	    //cyan

	/*vector<Mat> vecY, vecM, vecC;
	Mat zero(BGR_img.size(), CV_8U, Scalar(0));

	vecY.push_back(CMY_arr[0]);
	vecY.push_back(zero);
	vecY.push_back(zero);

	vecM.push_back(zero);
	vecM.push_back(CMY_arr[1]);
	vecM.push_back(zero);

	vecC.push_back(zero);
	vecC.push_back(zero);
	vecC.push_back(CMY_arr[2]);

	Mat Y, M, C;

	merge(vecY, Y);
	merge(vecM, M);
	merge(vecC, C);

	imshow("C", Y);
	imshow("M", M);
	imshow("Y", C);*/

	
	

	


	waitKey();
	return 0;
}