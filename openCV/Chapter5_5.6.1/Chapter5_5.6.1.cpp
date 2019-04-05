#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.6.1 ��� �� ���� 

//cv::gemm() �Լ��� �̿��ؼ� ����� ������ ������ ���̴�. cv::gemm() �Լ��� �ƴ� Mat Ŭ������ ���� �޼�����
//* ������ �Լ��� �̿��ؼ� ����� ������ �ٷ� �����ص� ���� ����� ���� �� �ִ�.

// ��� ���� ����� ���� p.263
// ���� ��� 
//[src1] =
//[1, 2, 3;
//4, 5, 1]
//[src2] =
//[5, 4, 2;
//3, 2, 1]
//[src3] =
//[5, 4;
//2, 3;
//2, 1]
//
//[dst1] =
//[17, 12, 6;
//25, 18, 9;
//18, 14, 7]
//[dst2] =
//[19, 10;
//42, 23]
//[dst3] =
//[15, 13;
//32, 32]

int main() {

	//Matx ����� ���� �� �ʱ�ȭ 
	Matx23f src1(1,2,3,4,5,1);						//2�� 3�� Matx ��� ����
	Matx23f src2(5,4,2,3,2,1);
	Matx32f src3(5,4,2,3,2,1);						//3��, 2�� Matx ��� ���� 
	Mat dst1, dst2, dst3;

	double alpha = 1.0, beta = 1.0;

	//��� �� ���� 
	//GEMM_1_T = src1�� ��ġ 2 = src2�� ��ġ 3 = src3�� ��ġ
	gemm(src1, src2, alpha, Mat(), beta, dst1, GEMM_1_T); //(�Է� ���1, 2, ��İ� ����ġ, ��İ��� �������� ��Ÿ ���,
														  //src��Ŀ� �������� ����ġ, ������, ���� �÷���) 
	gemm(src1, src2, alpha, noArray(), beta, dst2, GEMM_2_T);
	gemm(src1, src3, alpha, noArray(), beta, dst3);

	cout << "[src1] = " << endl << src1 << endl;
	cout << "[src2] = " << endl << src2 << endl;
	cout << "[src3] = " << endl << src3 << endl << endl;

	cout << "[dst1] = " << endl << dst1 << endl;	//src1 ��ġ
	cout << "[dst2] = " << endl << dst2 << endl;	//src2 ��ġ	
	cout << "[dst3] = " << endl << dst3 << endl;	//��ġ ���� 	
	return 0;
}

