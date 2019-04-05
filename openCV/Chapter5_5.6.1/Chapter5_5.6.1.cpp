#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.6.1 행렬 곱 연산 

//cv::gemm() 함수를 이용해서 행렬의 곱셈을 수행한 것이다. cv::gemm() 함수가 아닌 Mat 클래스의 내부 메서드인
//* 연산자 함수를 이용해서 행렬의 곱셈을 바로 수행해도 같은 결과를 만들 수 있다.

// 행렬 연산 결과는 교재 p.263
// 실행 결과 
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

	//Matx 행렬의 선언 및 초기화 
	Matx23f src1(1,2,3,4,5,1);						//2행 3열 Matx 행렬 선언
	Matx23f src2(5,4,2,3,2,1);
	Matx32f src3(5,4,2,3,2,1);						//3행, 2열 Matx 행렬 선언 
	Mat dst1, dst2, dst3;

	double alpha = 1.0, beta = 1.0;

	//행렬 곱 수행 
	//GEMM_1_T = src1을 전치 2 = src2을 전치 3 = src3을 전치
	gemm(src1, src2, alpha, Mat(), beta, dst1, GEMM_1_T); //(입력 행렬1, 2, 행렬곱 가중치, 행렬곱에 더해지는 델타 행렬,
														  //src행렬에 곱해지는 가중치, 출력행렬, 연산 플래그) 
	gemm(src1, src2, alpha, noArray(), beta, dst2, GEMM_2_T);
	gemm(src1, src3, alpha, noArray(), beta, dst3);

	cout << "[src1] = " << endl << src1 << endl;
	cout << "[src2] = " << endl << src2 << endl;
	cout << "[src3] = " << endl << src3 << endl << endl;

	cout << "[dst1] = " << endl << dst1 << endl;	//src1 전치
	cout << "[dst2] = " << endl << dst2 << endl;	//src2 전치	
	cout << "[dst3] = " << endl << dst3 << endl;	//전치 없음 	
	return 0;
}

