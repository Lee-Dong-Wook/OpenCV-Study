#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.6.2 cv::transform()�� �̿��� ȸ�� ��ȯ 

//��� ������ ��ǻ�� �׷��ȿ��� ��ü�� ȸ����Ű�ų� ũ�⸦ ���� ���� ���� ��ȯ(transform)�� �ʿ��� �� ������ ���
//�� ������ ȸ�� �߽����� ������ �ֻ�� �������� ���� 

//���� ��� 
//rect_pt1[0] = [200, 50]	      rect_pt2[0] = [171, 115]
//rect_pt1[1] = [400, 50]		  rect_pt2[1] = [359, 184]
//rect_pt1[2] = [400, 250]        rect_pt2[2] = [290, 372]
//rect_pt1[3] = [200, 250]        rect_pt2[3] = [102, 303]

int main() {

	vector<Point> rect_pt1, rect_pt2;		//�Է���ǥ�� ��ȯ �����ǥ ���� 
	rect_pt1.push_back(Point(200, 50 ));	//4���� �Է���ǥ ���� 	
	rect_pt1.push_back(Point(400, 50 ));	
	rect_pt1.push_back(Point(400, 250 ));
	rect_pt1.push_back(Point(200, 250 ));
	
	float theta = 20 * CV_PI / 180;										//���� ���� ���

	Matx22f m(cos(theta), -sin(theta), sin(theta), cos(theta));			//2�� 2�� ȸ����ȯ��� ���� , ȸ����(theta)�� ���� sin(),cos()���� ����Ͽ� �ʱ�ȭ 
																		//theta�� ȸ�� ��ȯ ��� ���� 			
	
	transform(rect_pt1, rect_pt2, m);									//rect1�� m�� ���� rect2���ͷ� ��ȯ! ��, ȸ���� ��ǥ�� ���  		
																		//�Էº���(4�� ��ǥ)�� cv::transform()�Լ��� 
																		//ȸ�� ��ȯ ��� �����Ͽ� ȸ�� ��ȯ ���� 
																		//-> ��ȯ ���ʹ� ȸ�� ��ȯ�� �¾n�� 			
	
	//400 x 500 = 400��, 500�� ���� : 400 ���� : 500
	Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));			//���� ���� 
	
	for (int i = 0; i < 4; i++) {									//4�� ��ǥ �׸��� 

		line(image, rect_pt1[i], rect_pt1[(i + 1) % 4], Scalar(0, 0, 0), 1);	//rect1 �簢���� �׸���. �β� 1�� ������ ������ 4���� ��ǥ�� �׸��� �׸� 
		line(image, rect_pt2[i], rect_pt2[(i + 1) % 4], Scalar(0, 0, 0), 2);	//rect2 ȸ���� �簢���� �׸���. 

		cout << "rect_pt1[" + to_string(i) + "] = " << rect_pt1[i] << "\t" ;
		cout << "rect_pt2[" + to_string(i) + "] = " << rect_pt2[i] << endl;
	}

	imshow("image", image);
	waitKey();
	return 0;


}

