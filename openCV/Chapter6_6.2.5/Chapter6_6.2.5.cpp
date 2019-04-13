#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.5 ���� ��� ���� 

//���ϴ��(constrast)�� ������ �ΰ��� ��(���)�� ��迡�� ���� ������ ���� �� ���̰� �����Ǿ� ��Ÿ���� ����
//���� ���ϴ���� ������ ���� �κа� ��ο� �κ��� ���̰� ũ�� �ʾ� ��ü������ ��Ӱų� ���
//���� ���� ����� ������ ���� �κа� ��ο� �κ��� ���̰� ū ���� -> ��ü������ ������ �Ƿ��غ��δ�

//���ϴ�� ���̷��� ��ο� �κ��� �� ��Ӱ� ���� �κ��� ����� �ؾ��Ѵ�.
//�ݴ�� ��� ���߷��� ��ο� �κа� ���� �κ��� ���̸� ���δ�. 

//���̸� �ø��ų� ���̴� ����� ���� ������ ����
//��� �ø����� 1.0�̻� ���� ���ϰ� ���̷��� 1.0���� ���� ���Ѵ�. 

int main() {
 
	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg",0);	//ȸ���� �����б� 
	CV_Assert(image.data);

	Scalar avg = mean(image) / 2.0;		//���� ���� ȭ�� ����� ���� 
										//��ȯ����� Scalar������ 4���� ���Ҹ� ������ image�� 1ä�� ����̶� 0�� ���Ҹ� ���� ���´�
										//�׷��� �Ʒ��� avg�� avg[0]���� ǥ��. ������ avg�� ���� ����� ������. 
	Mat dst1 = image * 0.5;				//���ϴ�� ����
	Mat dst2 = image * 2.0;				//���ϴ�� ����
	Mat dst3 = image * 0.5 + avg[0];	//���� ��� �̿� ��� ���� 
	Mat dst4 = image * 2.0 - avg[0];	//���� ��� �̿� ��� ���� 

	imshow("image", image);
	imshow("dst1-��񰨼�",			 dst1);
	imshow("dst2-�������",			 dst2);
	imshow("dst3-����̿� ��񰨼�",	 dst3);	// ����� �̿��ϸ� �ڿ������� �����ϴ� 
	imshow("dst4-����̿� �������",	 dst4);

	waitKey();
	return 0;
}