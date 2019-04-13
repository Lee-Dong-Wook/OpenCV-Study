#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//������ ��ȯ�� ���� �ƴ�, �簢���� �߽����� �������� ����� �ȴ� 
//�簢���� �߽����� �������� ����� ���� '��ǥ�� �����̵�'

//1.��ȯ ����� 3x3���
//2. �������� �����̵� -> ȸ����ȯ -> �� �����̵� 
//3. ������ ��ȯ�� �� ��ȯ ����� ������ ��Ÿ �� �� ���� 
//	 ��ü ��ȯ ��� = �̵� ��ȯ ��� * ȸ�� ��ȯ ��� * �̵� ��ȯ ��� 	

//���� ���
//center row[300]
//
//center col
//[300;
// 150;
// 1]
//
//���� ��� + 300, 150[1, 0, 300;
//0, 1, 150;
//0, 0, 1]
//���� ��� + -300, -150[1, 0, -300;
//0, 1, -150;
//0, 0, 1]
//rect_pt1[0] = [200, 50, 1]        rect_pt2[0] = [300, 8.57864, 1]
//rect_pt1[1] = [400, 50, 1]        rect_pt2[1] = [441.421, 150, 1]
//rect_pt1[2] = [400, 250, 1]       rect_pt2[2] = [300, 291.421, 1]
//rect_pt1[3] = [200, 250, 1]       rect_pt2[3] = [158.579, 150, 1]

int main() {

	vector<Point3f> rect_pt1, rect_pt2;

	rect_pt1.push_back(Point3f(200, 50, 1));				//rect_pt1���Ϳ� �簢�� ������ ��ǥ�� �߰��Ѵ�.
	rect_pt1.push_back(Point3f(400, 50, 1));
	rect_pt1.push_back(Point3f(400, 250, 1));
	rect_pt1.push_back(Point3f(200, 250, 1));

	//ȸ�� ��ȯ ��� : 3x3 ��� 
	float theta = 45 * CV_PI / 180;

	Matx33f m;
	m << cos(theta), -sin(theta), 0,
		sin(theta), cos(theta), 0,
		0, 0, 1;

	//�����̵� ���(���� ���) 
	Mat t1 = Mat::eye(3, 3, CV_32F);
	Mat t2 = Mat::eye(3, 3, CV_32F);

	//���� ��Ŀ� 1, 0, 300									//�����̵� 
	//			 0, 1, 150
	//		     0, 0,   1		  

	//���� ��Ŀ� 1, 0, -300									//�������̵� 
	//			 0, 1, -150
	//		     0, 0,   1	

	Point3f delta = (rect_pt1[2] - rect_pt1[0]) / 2.0f;		//(400 - 200) / 2.0 = 100.0, (250 - 50) / 2.0 = 100.0 //�߰� ��ġ ��� 
	Point3f center = rect_pt1[0] + delta;					//�߰� ��ġ = 200 + 100 , 50 + 100  = (300, 150)

	Matx33f tx1(3, 3, CV_32F);
	tx1 << 0, 0, 300, 
	       0, 0, 150, 
		   0, 0, 0;
	t1 = t2 + (Mat)tx1;

	Matx33f tx2(3, 3, CV_32F);
	tx2 << 0, 0, -300, 
		   0, 0, -150,
		   0, 0,    0;
	t2 = t2 + (Mat)tx2;


	//��� �� ���� 
	//GEMM_1_T = src1�� ��ġ 2 = src2�� ��ġ 3 = src3�� ��ġ
	/*gemm(t1, t2, alpha, Mat(), beta, rect_pt2, GEMM_1_T);*/ //(�Է� ���1, 2, ��İ� ����ġ, ��İ��� �������� ��Ÿ ���,
														  //src��Ŀ� �������� ����ġ, ������, ���� �÷���) 

	double alpha = 1.0;
	double beta = 1.0;

	gemm(t1, m, alpha, Mat(), beta, m);				//����� ������ġ�� ���� ���� ����� �޶����� ������ ������ ���� �Ѵ�. 

	gemm(m, t2, alpha, Mat(), beta, m);

	transform(rect_pt1, rect_pt2, m);

	Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));

	for (int i = 0; i < 4; i++) {

		Point pt1(rect_pt1[i].x, rect_pt1[i].y);

		Point pt2(rect_pt1[(i + 1) % 4].x, rect_pt1[(i + 1) % 4].y);

		Point pt3(rect_pt2[i].x, rect_pt2[i].y);

		Point pt4(rect_pt2[(i + 1) % 4].x, rect_pt2[(i + 1) % 4].y);

		line(image, pt1, pt2, Scalar(0, 0, 0), 2);
		line(image, pt3, pt4, Scalar(255, 0, 0), 3);

		cout << "rect_pt1[" + to_string(i) + "]=" << rect_pt1[i] << "\t";
		cout << "rect_pt2[" + to_string(i) + "]=" << rect_pt2[i] << endl;
	}

	imshow("image", image);

	waitKey();
	return 0;
}