#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.4.1 �÷� ������ȯ(BGR -> CMY)

//RGB �÷� ���� - �� 
//���� ����� R(red) G(green) B(blue)
//���ϸ� ���� ���� ������� ���� ȥ�� 
//RGB �÷� ������ ���� ���������� ǥ���ϰ� ����µ� ���Ǵ� �⺻ �÷� �����̴�. 

//CMY(K) �÷� ���� - �� 
//���� ����� C(cyan)û��, M(Magenta)��ȫ, Y(Yello)
//���ϸ� ���� ���� Ź������ ���� ȥ�� 
//RGB�� ����, ���� ������� ��������

//C = 255 - R | R = 255 - C
//M = 255 - G | G = 255 - M 
//Y = 255 - R | B = 255 - Y

//C + M + Y �� �Ѵٰ� ������ ���� ���� �������� �ʴ´�. 
//K(black)�� �߰��Ѵ�. 

//CMY ���� CMYK �÷� �������� �ٲٴ� ���� 
//Black�� �ܼ��� �������� �ƴ� CMY����� �ּҰ�(min)�� ���Ѵ� 

// Black   = min(Cyan, Magetna, Yello)
// Cyan    = Cyan - balck 
// Magenta = Magenta - black
// Yello   = Yello - black 

//������ 
//CMY �÷� ������ ������ RGB�÷� ������ ����� ��������� ����Ϳ� ����ϸ� BGR_img�� ������ ��ó�� ���δ�.
//CMY_img�� ���� ä�η� �и��߱� ������ �� ä���� Gray-Scale�� ���´�
//
//���� �� ��ĵ��� �����ͷ� ��µȴٸ� ���� �κ��� ��ũ�� ��µ��� �ʰ� ���� �� �κ��� ȭ�Ұ� ������ŭ ��ä��(C,M,Y)�� ������ ��µȴ� 


int main() {

	Mat BGR_img = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee2.jpg", IMREAD_COLOR);
	CV_Assert(BGR_img.data);

	Scalar white(255, 255, 255);
	Mat	   CMY_img = white - BGR_img;		//CMYK : ��� �� ��Į�� ���� -> ��� ä���� ��� ȭ�ҿ� ������ ���� 
	Mat    CMY_arr[3];

	split(CMY_img, CMY_arr);

	imshow("BGR_img", BGR_img);
	imshow("CMY_img", CMY_img);
	imshow("CMY_img[0] Y", CMY_arr[0]);		//yello
	imshow("CMY_img[1] M", CMY_arr[1]);		//magenta
	imshow("CMY_img[1] C", CMY_arr[2]);	    //cyan
	

	waitKey();
	return 0;
}