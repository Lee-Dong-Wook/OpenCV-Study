#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//원점을 변환할 것이 아님, 사각형의 중심점을 원점으로 만들면 된다 
//사각형의 중심점을 원점으로 만드는 것은 '좌표의 평행이동'

//1.변환 행렬이 3x3행렬
//2. 원점으로 평행이동 -> 회전변환 -> 역 평행이동 
//3. 세번의 변환은 각 변환 행렬의 곱으로 나타 낼 수 있음 
//	 전체 변환 행렬 = 이동 변환 행렬 * 회전 변환 행렬 * 이동 변환 행렬 	

//실행 결과
//center row[300]
//
//center col
//[300;
// 150;
// 1]
//
//단위 행렬 + 300, 150[1, 0, 300;
//0, 1, 150;
//0, 0, 1]
//단위 행렬 + -300, -150[1, 0, -300;
//0, 1, -150;
//0, 0, 1]
//rect_pt1[0] = [200, 50, 1]        rect_pt2[0] = [300, 8.57864, 1]
//rect_pt1[1] = [400, 50, 1]        rect_pt2[1] = [441.421, 150, 1]
//rect_pt1[2] = [400, 250, 1]       rect_pt2[2] = [300, 291.421, 1]
//rect_pt1[3] = [200, 250, 1]       rect_pt2[3] = [158.579, 150, 1]

int main() {

	vector<Point3f> rect_pt1, rect_pt2;

	rect_pt1.push_back(Point3f(200, 50, 1));				//rect_pt1벡터에 사각형 꼭지점 좌표를 추가한다.
	rect_pt1.push_back(Point3f(400, 50, 1));
	rect_pt1.push_back(Point3f(400, 250, 1));
	rect_pt1.push_back(Point3f(200, 250, 1));

	//회전 변환 행렬 : 3x3 행렬 
	float theta = 45 * CV_PI / 180;

	Matx33f m;
	m << cos(theta), -sin(theta), 0,
		sin(theta), cos(theta), 0,
		0, 0, 1;

	//평행이동 행렬(단위 행렬) 
	Mat t1 = Mat::eye(3, 3, CV_32F);
	Mat t2 = Mat::eye(3, 3, CV_32F);

	//단위 행렬에 1, 0, 300									//평행이동 
	//			 0, 1, 150
	//		     0, 0,   1		  

	//단위 행렬에 1, 0, -300									//역평행이동 
	//			 0, 1, -150
	//		     0, 0,   1	

	Point3f delta = (rect_pt1[2] - rect_pt1[0]) / 2.0f;		//(400 - 200) / 2.0 = 100.0, (250 - 50) / 2.0 = 100.0 //중간 위치 계산 
	Point3f center = rect_pt1[0] + delta;					//중간 위치 = 200 + 100 , 50 + 100  = (300, 150)

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


	//행렬 곱 수행 
	//GEMM_1_T = src1을 전치 2 = src2을 전치 3 = src3을 전치
	/*gemm(t1, t2, alpha, Mat(), beta, rect_pt2, GEMM_1_T);*/ //(입력 행렬1, 2, 행렬곱 가중치, 행렬곱에 더해지는 델타 행렬,
														  //src행렬에 곱해지는 가중치, 출력행렬, 연산 플래그) 

	double alpha = 1.0;
	double beta = 1.0;

	gemm(t1, m, alpha, Mat(), beta, m);				//행렬은 순서위치에 따라 연산 결과가 달라지기 때문에 순서를 주의 한다. 

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