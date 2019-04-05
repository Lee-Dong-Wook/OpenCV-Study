#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.5.3 정열된 행렬 원소의 원본 좌표 반환 

//cv::sortIdx() 
//행렬의 원소를 직접 정렬하지 않고 정렬된 원소의 원본 좌표를 반환
//주로 행렬이나 벡터에서 원소의 값이 아닌 다른 기준으로 정렬해야 할 때 사용
//결과는 정렬하기전 원소가 위치했던 인덱스 번호로 나타냄 
//flag 옵션은 cv::sort()와 동일 

//실행결과 
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

	Mat_<uchar> m1(3, 5);		//Matx 객체로 간편 초기화 
	m1 << 11, 2, 3, 4, 10,
		6, 10, 15, 9, 7,
		7, 12, 8, 14, 1;

	Mat m_sort1, m_sort2, m_sort_idx1, m_sort_idx2, m_sort_idx3;
															//정렬된 원소의 원본좌표 	
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

