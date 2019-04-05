#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.1.1 ���ó���Լ� 
//�̹��� -> ��� -> ó�� 
//RGB���� �и� �� ó��. �Ӽ��� �Ѱ����θ� ���� �� Grayscale�� ó�� �ȴ�. 
//��ǻ�ʹ� RGB�� �ƴ� BGR ������ ó�� �ȴ�. 
//R,G,B 3���� ������ ���� 2���� ��� ���� -> 2���� ��� ���� x 3, �� 3���� �迭�� �ȴ�. 


int main() {

	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/image2.jpg",IMREAD_COLOR);
	CV_Assert(image.data);

	Mat x_axis, y_axis, xy_axis, rep_img, trans_img; 
	flip(image, x_axis, 0);									//x�� ���� ���� ������
	flip(image, y_axis, 1);									//y�� ���� �¿� ������ 
	flip(image, xy_axis,-1);

	repeat(image,1,2,rep_img);								//�ݺ� ���� 
	transpose(image,trans_img);								//��� ��ġ 

	imshow("image", image);
	imshow("x_axis", x_axis);
	imshow("y_axis", y_axis);
	imshow("xy_axis", xy_axis);
	imshow("rep_img", rep_img);
	imshow("trans_img", trans_img);

	waitKey();
	return 0;


}

