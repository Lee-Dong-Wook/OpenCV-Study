#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.2 ��� ���� �� �α� ���� 

int main() {

	vector<float> v1, v_exp, v_log;				//float ���� ����  
	Matx  <float, 1, 5> m1(1, 2, 3, 5, 10);		//���� �ʱ�ȭ�� ���� Matx ��ü ���� �� �ʱ�ȭ 
	Mat m_exp, m_sqrt, m_pow;				

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	exp(v1, v_exp);								//���Ϳ� ���� ���� ��� 
	exp(m1, m_exp);								//��Ŀ� ���� ���� ��� 
	log(m1, v_log);								//�Է��� ���, ����� ���� 
	sqrt(m1, m_sqrt);							//������ ��� 
	pow(m1, 3, m_pow);							//3 �ŵ� ���� ��� 

	cout << "[m1] = " << m1 << endl << endl;
	cout << "[v_exp] = " << ((Mat)v_exp).reshape(1,1) << endl; //���͸� ��� ��ȯ �� 1ä�� 1�� �����ͷ� �����.
															   //reshape()�� ���� ������ 3�� 1�� 
	cout << "[m_exp] = " << m_exp << endl;
	cout << "[v_log] = " << ((Mat)v_log).reshape(1,1) << endl;	//reshape()�� ���� ������ 5�� 1�� 

	cout << "[m_sqrt] = " << m_sqrt << endl;
	cout << "[m_pow] = " << m_pow << endl;
	waitKey();
	return 0;
}

