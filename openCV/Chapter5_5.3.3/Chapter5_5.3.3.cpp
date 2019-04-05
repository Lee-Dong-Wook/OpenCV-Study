#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.3 ��� ũ�� �� ���� ���� 
//cv::magnitude()�� cv::phase()
//��İ� ���͸� �Է� �μ� �� ����μ��� ��밡�� 
//�Է� �����ͷ� float�� ���͸� ���, ��� �μ����� ���Ϳ� �Բ� ��ĵ� ���� 

int main() {

	float data1[] = { 1, 2, 3, 5, 10 };										//�Ǽ��� �迭 ���� 	
	float data2[] = { 2, 5, 7, 2, 9 };

	vector<float> x_vec(data1, data1 + sizeof(data1) / sizeof(float));		//�Ǽ��� ���� �ʱ�ȭ 
	vector<float> y_vec(data2, data2 + sizeof(data2) / sizeof(float));

	vector<float> v_mag, v_ang;					//���� ���� 

	magnitude(x_vec, y_vec, v_mag);				//���� �Է� -> ���� ��ȯ, �� ������ ���ҷ� ũ�⸦ ����ϰ� v_mag���Ϳ� �� ��ȯ  
	phase(x_vec, y_vec, v_ang);					//�� ������ ���ҷ� ������ ����ϰ� v_ang ���Ϳ� �� ��ȯ 

	Mat m_mag, m_ang, x_mat, y_mat;				//��� ����
	cartToPolar(x_vec, y_vec, m_mag, m_ang);	//���� �Է� -> ��� ��ȯ, �� ������ ���ҷ� ũ��� ������ ��� ����Ͽ� ��ȯ.
												//��� �޴� Ÿ���� m_mag  m_ang
	polarToCart(m_mag, m_ang, x_mat, y_mat);	//��� �Է� -> ���� ��ȯ cartToPolar()�� ���� ũ��Ͱ��� ���(m_mag, m_ang)�� �������� 
												//x,y��ǥ�� ����Ͽ� ��ȯ 

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

