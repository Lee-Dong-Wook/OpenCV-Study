#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.3 행렬 크기 및 위상 연산 
//cv::magnitude()와 cv::phase()
//행렬과 벡터를 입력 인수 및 출력인수로 사용가능 
//입력 데이터로 float형 벡터를 사용, 출려 인수에는 벡터와 함께 행렬도 가능 

int main() {

	float data1[] = { 1, 2, 3, 5, 10 };										//실수형 배열 선언 	
	float data2[] = { 2, 5, 7, 2, 9 };

	vector<float> x_vec(data1, data1 + sizeof(data1) / sizeof(float));		//실수형 벡터 초기화 
	vector<float> y_vec(data2, data2 + sizeof(data2) / sizeof(float));

	vector<float> v_mag, v_ang;					//벡터 선언 

	magnitude(x_vec, y_vec, v_mag);				//벡터 입력 -> 벡터 반환, 두 벡터의 원소로 크기를 계산하고 v_mag벡터에 값 반환  
	phase(x_vec, y_vec, v_ang);					//두 벡터의 원소로 각도를 계산하고 v_ang 벡터에 값 반환 

	Mat m_mag, m_ang, x_mat, y_mat;				//행렬 선언
	cartToPolar(x_vec, y_vec, m_mag, m_ang);	//벡터 입력 -> 행렬 반환, 두 벡터의 원소로 크기와 각도를 모드 계산하여 반환.
												//결과 받는 타입은 m_mag  m_ang
	polarToCart(m_mag, m_ang, x_mat, y_mat);	//행렬 입력 -> 벡터 반환 cartToPolar()로 계산된 크기와각도 행렬(m_mag, m_ang)로 각원소의 
												//x,y좌표를 계산하여 반환 

	cout << "[x_vec] = " << ((Mat)x_vec).reshape(1, 1) << endl;
	cout << "[y_vec] = " << ((Mat)y_vec).reshape(1, 1) << endl;
	cout << "[v_mag] = " << ((Mat)v_mag).reshape(1, 1) << endl;
	cout << "[v_ang] = " << ((Mat)v_ang).reshape(1, 1) << endl;

	cout << "[v_mag] = " << m_mag << endl;
	cout << "[v_ang] = " << m_ang << endl;
	cout << "[x_mat] = " << x_mat << endl;
	cout << "[y_mat] = " << y_mat << endl;

	return 0;
}

