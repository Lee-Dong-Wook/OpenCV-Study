#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.4 ��� �հ� �� ������ ���� ���� �ռ� 

//** ���� �̹��� ũ�Ⱑ ���ƾ� ���డ�� ** 
// �� ������ ��ġ�� ���� �ռ��� �Ǹ� �� ������ ���� ������(difference image)�� �ȴ�. differencial�� ���� ���� ���ȴ�
//�ΰ��� ����� ���ϰ� �Ǹ� saturation_cast �������� ���� 255�� �Ѿ�� ȭ�Ҵ� ������� ��Ÿ�� �ռ������� ���ε��� �ʴ´�.
//�׷��� ������ Ư�� �̹����� ����ġ�� ���ϴ� ����� �ִ�. 

int main() {

	Mat image1 = imread("C:/Users/Raynor/Desktop/openCVEXImage/same1.jpg",IMREAD_GRAYSCALE);
	Mat image2 = imread("C:/Users/Raynor/Desktop/openCVEXImage/same2.jpg", IMREAD_GRAYSCALE);
	
	CV_Assert(!(image1.empty() || image2.empty()));			//���� ó�� 

	double alpha = 0.6, beta = 0.7;							//���� ���� 

	Mat add_img1 = image1 + image2;								//���� �ռ� ��ĵ����� ��ȭ����� �ǹǷ� 255���� ū���� 255�� ���� 
	Mat add_img2 = image1 * 0.5 + image2 * 0.5;					//�� �̹����� 1/2�� ���Ͽ� 255�̳� ������ �ռ� 
	Mat add_img3 = image1 * alpha + image2 * (1 - alpha);		//Ư�� �̹����� �� ū ������ �ش�
	Mat add_img4;

	addWeighted(image1, alpha, image2, beta, 0 , add_img4);		//�� ��Ŀ� �������� ������ �ٸ��� �������� �ϴ�. 
																//alpha�� beta ���� 1���� ũ�� ������ ��ü������ ��� ���´� 
																//5��° ���ڴ� gamma ���̴�. 

	imshow("image1",	 image1);
	imshow("image2",	 image2);
	imshow("add_img1",	 add_img1);
	imshow("add_img2",   add_img2);
	imshow("add_img3",   add_img3);
	imshow("add_img4",   add_img4);
	
	waitKey();
	return 0;
}