#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.5.2 ��� ���� ���� 

//������ 
//[m1] =
//[11, 2, 3, 4, 10;
//6, 10, 15, 9, 7;
//7, 12, 8, 14, 1]
//
//[m_sort1] =
//[2, 3, 4, 10, 11;
//6, 7, 9, 10, 15;
//1, 7, 8, 12, 14]
//
//[m_sort2] =
//[11, 10, 4, 3, 2;
//15, 10, 9, 7, 6;
//14, 12, 8, 7, 1]
//
//[m_sort3] =
//[6, 2, 3, 4, 1;
//7, 10, 8, 9, 7;
//11, 12, 15, 14, 10]
//
//[m_sort4] =
//[11, 12, 15, 14, 10;
//7, 10, 8, 9, 7;
//6, 2, 3, 4, 1]

int main() {

	Mat_<uchar> m1(3, 5);		//Matx ��ü�� ���� �ʱ�ȭ 
	m1 << 11, 2, 3, 4, 10,
		  6,  10,15,9, 7,
		  7,  12, 8,14,1;

	Mat m_sort1, m_sort2, m_sort3, m_sort4;

	//���� sort()�� std::sort()�� cv::sort()�� �� �Լ� ��� �μ��� ���̶����� �� ���ӽ����̽��� ���� ȣ���Ѵ�.
	cv::sort(m1, m_sort1, SORT_EVERY_ROW);						//��� ���� ���� , ����� ���� ����
	cv::sort(m1, m_sort2, SORT_EVERY_ROW + SORT_DESCENDING);	//				  ����� ���� ���� 
	cv::sort(m1, m_sort3, SORT_EVERY_COLUMN);					//				  ������ ���� ���� 
	cv::sort(m1, m_sort4, SORT_EVERY_COLUMN + SORT_DESCENDING);	//				  ������ ���� ����

	cout << " [m1] = " << endl << m1 << endl << endl;
	cout << " [m_sort1] = " << endl << m_sort1 << endl << endl;
	cout << " [m_sort2] = " << endl << m_sort2 << endl << endl;
	cout << " [m_sort3] = " << endl << m_sort3 << endl << endl;
	cout << " [m_sort4] = " << endl << m_sort4 << endl << endl;

	return 0;
}

