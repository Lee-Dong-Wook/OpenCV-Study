#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.3.1 ��� ��� ���� 
//���� 
//Rect rect(Point(3, 0), Size(3, 3));				//���ɿ��� ���� 
//mask(rect).setTo(1);							//�簢�� ������ŭ mask ��Ŀ��� �����Ͽ� ���Ұ��� 1�� ���� 

//������ 
//Mat ��ü�� ������ �� �ʱ�ȭ�� ������ �ʴ´ٸ� ����� ���� 205, ������ ���� 0���� �ʱ�ȭ �ȴ�. 
//���ɿ��� ���� �� 0�̸� ���ɿ������� �����ϴ� ��(��Ȯ���� ����)�� �⶧���� mask ���Ұ��� 205�� �ʱ�ȭ�� �Ǿ������� 
//masking�� ���� ���� �ʱ� ������ �ݵ�� ����� �ʱ�ȭ ���־���Ѵ�. Ȥ�� ������ ��������� �Ѵٸ� ��Ȯ�� ����� ���´�. 

int main() {

	Mat m_add1, m_add2, m_sub, m_div1, m_div2;

	Mat m1(3, 6, CV_8UC1, Scalar(10));				//3�� 6�� 1ä�� uchar ��� ���� �� �ʱ�ȭ 
	Mat m2(3, 6, CV_8UC1, Scalar(50));
	Mat mask(m1.size(), CV_8UC1, Scalar(0));					//����ũ ��� - 8bit ���� ä�� 

	Rect rect(Point(2, 0), Size(3, 3));				//���ɿ��� ���� 
	mask(rect).setTo(1);							//�簢�� ������ŭ mask ��Ŀ��� �����Ͽ� ���Ұ��� 1�� ���� 

	add(m1, m2, m_add1);							//��� ����
	add(m1, m2, m_add2, mask);						//���ɿ���(mask 1�� ����)�� ���� ���� 

	divide(m1, m2, m_div1);							//m1���� m2 ������ 
	m1.convertTo(m1, CV_32F);						//����ȯ - �Ҽ��κ� ����, �������� ��� �ڷ��� ��ȯ�� ���� �Ҽ��� ���� 
	m2.convertTo(m2, CV_32F);
	divide(m1, m2, m_div2);

	cout << "[m1] = " << endl << m1 << endl;
	cout << "[m2] = " << endl << m2 << endl;
	cout << "[mask] = " << endl << mask << endl;

	cout << "[m_add1] = " << endl << m_add1 << endl;
	cout << "[m_add2] = " << endl << m_add2 << endl;
	cout << "[m_div1] = " << endl << m_div1 << endl;
	cout << "[m_div2] = " << endl << m_div2 << endl;

	waitKey();
	return 0;
}

