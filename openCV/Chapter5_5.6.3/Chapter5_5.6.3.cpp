#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.6.3 equation

//역행렬과 연립 방정식의 해를 바로 구하는 함수 
//연립방정식 문제를 cv::invert(), cv::solve()로 푼다. 

//연립방적식 
//	 1*x1 +      + 2*x3 = 6     [ 1, 0, 2] [6]
// - 3*x1 + 2*x2 + 6*x3 = 30    [-3, 4, 6] [30]
// - 1*x1 - 2*x2 + 3*x3 = 8     [-1,-2, 3] [8]

int main() {

	Matx33f m1(1, 0, 2, -3, 4, 6, -1, -2, 3);
	Matx31f m2(6, 30, 8);
	Mat		m1_inv1, dst1, dst2;

	invert(m1, m1_inv1, DECOMP_LU);				//값 : 0 가우시안 소거법으로 역행렬 계산
												//입력 행렬은 역행렬이 존재하는 정방행렬 

	dst1 = m1_inv1 * (Mat)m2;				
	solve(m1, m2, dst2, DECOMP_LU);				//연립방정식 풀이 

	cout << "[m1_inv1] = " << endl << m1_inv1 << endl << endl;
	cout << "[dst1] = " << dst1.t() << endl; 
	cout << "[dst2] = " << dst2.t() << endl; 

	waitKey();
	return 0;


}

