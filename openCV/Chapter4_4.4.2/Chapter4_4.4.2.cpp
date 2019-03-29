#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.4.2 ����� ���� ���Ϸ� ���� 

//cv::imwrite() ���
//jpg,bmp,png,tif �� ���� ���� ���� ���� ���� 
//params ���ͷ� jpg ������ ȭ���̳� png������ ������� ���� ����
//
//paramValue(default value)
//IMWRITE_JPEG_QUALITY		0~100(95)
//IMWRITE_PNG_COMPRESSION	0~9(3)
//IMWRITE_PXM_BINARY		0 or 1(1)
//
//IMWRITE_JPEG_QUALITY		jpg����ȭ��, ���� ���� ���� ȭ���� ����
//IMWRITE_PNG_COMPRESSION	png ���� ���෹��, ���� ���� ���� ���� �뷮, �� ���� �ð�
//IMWRITE_PXM_BINARY		PPM, PGM ������ ���� ���� ���� 


int main() {

	Mat img8 = imread("C:/Users/Raynor/Desktop/openCVEXImage/image3.jpg",IMREAD_COLOR);	//������ �״�� ������ ���� ���� �ƴ�
																						//������ ������� ��ķ� ���� 
	
	CV_Assert(img8.data);

	vector<int> params_jpg, params_png;

	params_jpg.push_back(IMWRITE_JPEG_QUALITY);											//���� ���� ����, jpg ȭ�� ���� 
	params_jpg.push_back(50);															//100�� �ְ�ȭ��
																						
	params_png.push_back(IMWRITE_PNG_COMPRESSION);										//png ���� ���� ���� 
	params_png.push_back(9);															//9�� �ְ����� 

	imwrite("C:/Users/Raynor/Desktop/openCVEXImage/write_test1.jpg",img8);				//��� �������Ϸ� ���� 
	imwrite("C:/Users/Raynor/Desktop/openCVEXImage/write_test2.jpg", img8,params_jpg);  //����ȭ���� ���� 
	imwrite("C:/Users/Raynor/Desktop/openCVEXImage/write_test3.png", img8, params_png);
	imwrite("C:/Users/Raynor/Desktop/openCVEXImage/write_test4.bmp", img8);				//bmp ���� ���� 

	waitKey(0);
	return 0;
}

