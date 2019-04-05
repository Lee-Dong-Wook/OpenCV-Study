

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

//pcī�޶� ���ؼ� ������ �Է�, �¿츦 ����� flip_test.avi�� �̸��� ������ ���Ϸ� ����
//������ ���� ũ�� 640 x 480
//�ʵ� ������ �� : 15fps 
//������ �ڵ� : DIVX 

int main() {

	/*	1. �ǽð����� ������ �Է¹޴´�.
		2. ����, �ڵ� ����, ������, ������ ��� ���� �� , cmd�� ����Ѵ�.
		3. �����Ѵ� writer ��ü ���� �� ����
		4. while ������ ���� ������ �ϳ��ϳ��� ��ķ� capture ��ü�� ���� �޴´�.
		5. flip�Լ��� ���� �¿� ���� ��ŰŰ��
		6. writer.write(frame);
		7.���� ���� */

	VideoCapture capture(0);										//������ü ���� �� 0�� ī�޶� ���� 
	CV_Assert(capture.isOpened());									//ī�޶� ���� ���� ó��

	double fps = 15.0;												//�ʴ� ������ �� 
	int	   delay = cvRound(1000.0 / fps);							//�����Ӱ� �����ð� 
	Size   size(320, 160);											//������ ���� �ػ�
	int	   fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');		//���� �ڵ� ����

	capture.set(CAP_PROP_FRAME_WIDTH, size.width);					//�ػ� ����(���� �ػ� ����) 
	capture.set(CAP_PROP_FRAME_HEIGHT, size.height);

	cout << "width x hieght : " << size << endl;
	cout << "VideoWriter::fourcc : " << fourcc << endl;			//������ ���� �ܼ�â ��� 
	cout << "delay : " << delay << endl;
	cout << "fps : " << fps << endl;

	VideoWriter writer;												//������ ���� ���� ��ü 
	writer.open("C:/Users/Raynor/Desktop/openCVEXImage/reverse2.avi", fourcc, fps, size); //���� ���� �� ���� 
	CV_Assert(writer.isOpened());

	while (true) {

		if (waitKey(delay) > 0) break;

		Mat frame, reverse;
		capture >> frame;											//ī�޶� ����ޱ� 
		//flip(frame, reverse, 1);
		writer << reverse;											//�������� ���������� ���� 


		imshow("ī�޶� ���󺸱�", frame);

	}
	return 0;
}

//��� ���� ���� 
//m1(1,2,3,4,5,6);
//m(0,0) = 1    m(0,1) = 2 

	/*int x = mat.rows;
	int y = mat.cols;
	Mat convert(x,y,CV_32FC3);
	convert = mat;*/

//RectŬ���� Ȥ�� mat���� ������� ������ ��ķ� �޾ƿ´�. 
//�� ��, ���� ���� �ľ��Ѵ�. 
//�¿�����̴ϱ� ���� �������� �ʰ� ���� �����Ѵ�. 1���� ��� ���� 1,2,3,4,5,6,7,8,9 �̸� 
//����� 9,8,7,6,5,4,3,2,1 �� ����ϰ� �Ѵ�. 
//2�� for���� �����µ� ù��° for���� �࿡ ���ؼ� 2��° for���� �������ؼ� ������. 
