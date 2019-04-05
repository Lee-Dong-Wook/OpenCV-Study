#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.5.2 행렬 원소 정렬 

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

	Mat_<uchar> m1(3, 5);		//Matx 객체로 간편 초기화 
	m1 << 11, 2, 3, 4, 10,
		  6,  10,15,9, 7,
		  7,  12, 8,14,1;

	Mat m_sort1, m_sort2, m_sort3, m_sort4;

	//주의 sort()는 std::sort()와 cv::sort()로 두 함수 모두 인수가 같이때문에 꼭 네임스페이스를 통해 호출한다.
	cv::sort(m1, m_sort1, SORT_EVERY_ROW);						//행렬 원소 정렬 , 행단위 오름 차순
	cv::sort(m1, m_sort2, SORT_EVERY_ROW + SORT_DESCENDING);	//				  행단위 내림 차순 
	cv::sort(m1, m_sort3, SORT_EVERY_COLUMN);					//				  열단위 오름 차순 
	cv::sort(m1, m_sort4, SORT_EVERY_COLUMN + SORT_DESCENDING);	//				  열단위 내림 차순

	cout << " [m1] = " << endl << m1 << endl << endl;
	cout << " [m_sort1] = " << endl << m_sort1 << endl << endl;
	cout << " [m_sort2] = " << endl << m_sort2 << endl << endl;
	cout << " [m_sort3] = " << endl << m_sort3 << endl << endl;
	cout << " [m_sort4] = " << endl << m_sort4 << endl << endl;

	return 0;
}

