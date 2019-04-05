#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;


//���� ���� ������ ��ķ� �о� �鿩�� ����ó��, ���������� xml���Ϸ� ����
//1) ����ũ�⸦ image_size��� �̸����� ����
//2) ������ ���� ��(depth)��� �̸����� ����
//3) ������ ��� ȭ�Ұ����� image_data�� ���� 

int main() {

	Mat mat = imread("C:/Users/Raynor/Desktop/openCVEXImage/mine1.jpg", IMREAD_UNCHANGED);
	CV_Assert(mat.data);	//�������� ���� ó��
	FileStorage fs("test.xml", FileStorage::WRITE);



	fs << "image_size" << mat.size();				//�̹��� �ػ�  
	fs << "depth" << mat.depth();					//�̹��� ���� 
	
	fs << "mat" << "[";
	fs << "image_data " << mat;						//�̹��� ��� 
	fs << "]";
	fs.release();

	return 0;
}








