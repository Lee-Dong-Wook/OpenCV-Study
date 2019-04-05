#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.6.3 equation

//����İ� ���� �������� �ظ� �ٷ� ���ϴ� �Լ� 
//���������� ������ cv::invert(), cv::solve()�� Ǭ��. 

//���������� 
//	 1*x1 +      + 2*x3 = 6     [ 1, 0, 2] [6]
// - 3*x1 + 2*x2 + 6*x3 = 30    [-3, 4, 6] [30]
// - 1*x1 - 2*x2 + 3*x3 = 8     [-1,-2, 3] [8]

int main() {

	Matx33f m1(1, 0, 2, -3, 4, 6, -1, -2, 3);
	Matx31f m2(6, 30, 8);
	Mat		m1_inv1, dst1, dst2;

	invert(m1, m1_inv1, DECOMP_LU);				//�� : 0 ����þ� �ҰŹ����� ����� ���
												//�Է� ����� ������� �����ϴ� ������� 

	dst1 = m1_inv1 * (Mat)m2;				
	solve(m1, m2, dst2, DECOMP_LU);				//���������� Ǯ�� 

	cout << "[m1_inv1] = " << endl << m1_inv1 << endl << endl;
	cout << "[dst1] = " << dst1.t() << endl; 
	cout << "[dst2] = " << dst2.t() << endl; 

	waitKey();
	return 0;


}

