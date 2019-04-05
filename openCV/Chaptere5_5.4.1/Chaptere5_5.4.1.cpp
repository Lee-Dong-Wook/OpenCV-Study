#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.4.1 ��� ���� �� ���� ���� (������ ����� å�� �ٸ��� �ٽ�Ȯ���غ��ʿ䰡 ����)
//���� �� : �� - �� = ����� 

//�̹����� ������(�ػ�)�� ���� ���� ��� ������ ���� ������ �߻� 
//OpenCV(4.0.1) Error: Sizes of input arguments do not match 
//(The operation is neither 'array op array' 
//(where arrays have the same size and the same number of channels), 
//nor 'array op scalar', nor 'scalar op array') in cv::arithm_op, 
//file c:\build\master_winpack-build-win64-vc15\opencv\modules\core\src\arithm.cpp, line 663

//MatExpr abs() ����� �� ���ҿ� ���� ���밪�� ����Ͽ� ������ ���� ����� MatExpr��ü�� ��ȯ
//void    absdiff() �ι迭�� �� ���� �� ������ ���밪�� ��� src1,src2 �� �ϳ��� ��Į�� ���� �� �� �ִ�. 
int main() {

	Mat image1 = imread("C:/Users/Raynor/Desktop/openCVEXImage/image4.jpg", 0);			// �� 0�� ��ϵ� ���� �ε�
	Mat image2 = imread("C:/Users/Raynor/Desktop/openCVEXImage/image5.jpg", 0);
	CV_Assert(image1.data && image2.data);												//���� ó�� 

	Mat dif_img, abs_dif1, abs_dif2;

	image1.convertTo(image1, CV_16S);													//��� �� ��ȯ(uchar -> short)
	image2.convertTo(image2, CV_16S);

	subtract(image1, image2, dif_img);													//���� ���� 

	Rect roi(10, 10, 7, 3);
	cout << "[dif_img] = " << endl << dif_img(roi) << endl;

	abs_dif1 = abs(dif_img);

	image1.convertTo(image1, CV_8U);													//��� �� ��ȯ(short -> uchar)
	image2.convertTo(image2, CV_8U);
	dif_img.convertTo(dif_img,CV_8U);
	abs_dif1.convertTo(abs_dif1,CV_8U);

	absdiff(image1, image2, abs_dif2);													//���� ���� ��� 

	cout << "[dif_img] = " << endl << dif_img(roi) << endl << endl;
	cout << "[abs_dif1] = " << endl << abs_dif1(roi) << endl << endl;
	cout << "[abs_dif2] = " << endl << abs_dif2(roi) << endl << endl;

	imshow("image1", image1);
	imshow("image2", image2);
	imshow("dif_img", dif_img);
	imshow("abs_dif1", abs_dif1);
	imshow("abs_dif2", abs_dif2);

	waitKey();
	
	return 0;
}

