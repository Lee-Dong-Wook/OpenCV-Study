#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.2.2 ���� ȭ�Ұ� Ȯ�� 

//������ �о� ���ɿ����� ���� �� �� �κ��� ȭ�� ���� Ȯ���Ѵ�. 

int main() {

	//640 x 640 ���� 200, 320���� ���ε� 
	Mat image = imread("C:/Users/Raynor/Desktop/openCVEXImage/leehee.jpg", IMREAD_GRAYSCALE);

	if (image.empty()) {

		cout << "������ ���� ���߽��ϴ�." << endl; 
		exit(1);
	}

	Rect roi1(280, 120, 200, 200);			//���ɿ��� �簢��, �簢���� ������ǥ x, y, �簢���� �ʺ�, ���� 
	Rect roi2(280, 120, 20, 20);
	Mat roi_img1 = image(roi1);			//���ɿ��� ������ ����
	Mat roi_img2 = image(roi2);
	cout << "[roi_img] = " << endl; 

	//cout << image << endl;					  //���� ��� ���� ��� ��� - ����ȭ
	//cout << roi_img << endl;					  //���� ���� ��� ���� ��� ��� - ���� 

	for (int i = 0; i < roi_img2.rows; i++) {	 //���� ���� ��� ���� ��� ��� - ���� 
		for (int j = 0; j < roi_img2.cols; j++) {

			cout.width(5);                        //��� ���� �ʺ� ���� 
			cout << (int)roi_img2.at<uchar>(i, j); //��� ���� ��� ��� 
												  //uchar������ ����ϱ� ������ ���ڳ� Ư�����ڵ��� ��µǹǷ� int�� ����ȯ 							
		}
		cout << endl; 
	}
	imshow(" roi_image1 ���ɿ��� �κ� ", roi_img1);
	imshow(" roi_image2 ���ɿ��� �κ� ", roi_img2);

	rectangle(image, roi1, Scalar(255), 1);			//���ɿ��� �κ��� �簢������ �׸� 

	imshow("image", image); 

	waitKey();
	return 0;
}