#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.5.3 ������ ��� ������ ���� ��ǥ ��ȯ 

//cv::sortIdx() 
//����� ���Ҹ� ���� �������� �ʰ� ���ĵ� ������ ���� ��ǥ�� ��ȯ
//�ַ� ����̳� ���Ϳ��� ������ ���� �ƴ� �ٸ� �������� �����ؾ� �� �� ���
//����� �����ϱ��� ���Ұ� ��ġ�ߴ� �ε��� ��ȣ�� ��Ÿ�� 
//flag �ɼ��� cv::sort()�� ���� 

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
//[m_sort_idx1] =
//[1, 2, 3, 4, 0;
//0, 4, 3, 1, 2;
//4, 0, 2, 1, 3]
//
//[m_sort2] =
//[6, 2, 3, 4, 1;
//7, 10, 8, 9, 7;
//11, 12, 15, 14, 10]
//
//[m_sort_idx2] =
//[1, 0, 0, 0, 2;
//2, 1, 2, 1, 1;
//0, 2, 1, 2, 0]

int main() {

	Mat_<uchar> m1(3, 5);		//Matx ��ü�� ���� �ʱ�ȭ 
	m1 << 11, 2, 3, 4, 10,
		6, 10, 15, 9, 7,
		7, 12, 8, 14, 1;

	Mat m_sort1, m_sort2, m_sort_idx1, m_sort_idx2, m_sort_idx3;
															//���ĵ� ������ ������ǥ 	
	cv::sort(m1, m_sort1, SORT_EVERY_ROW);
	cv::sortIdx(m1, m_sort_idx1, SORT_EVERY_ROW);

	cv::sort(m1, m_sort2, SORT_EVERY_COLUMN);				
	cv::sortIdx(m1, m_sort_idx2, SORT_EVERY_COLUMN);	
	
	cout << " [m1] = " << endl << m1 << endl << endl;
	cout << " [m_sort1] = " << endl << m_sort1 << endl << endl;
	cout << " [m_sort_idx1] = " << endl << m_sort_idx1 << endl << endl;

	cout << " [m_sort2] = " << endl << m_sort2 << endl << endl;
	cout << " [m_sort_idx2] = " << endl << m_sort_idx2 << endl << endl;


	return 0;
}

