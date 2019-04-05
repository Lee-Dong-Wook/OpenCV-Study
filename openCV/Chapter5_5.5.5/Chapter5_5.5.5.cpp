#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.5.5 행렬 감축 연산 

//실행 결과 
//[m1] =
//[11, 2, 3, 4, 10;
//6, 10, 15, 9, 7;
//7, 12, 8, 14, 1]
//
//[m_REDUCE_SUM] =
//[24, 24, 26, 27, 18]
//
//[m_REDUCE_AVG] =
//[6;
//9.4000006;
//8.4000006]
//[m_REDUCE_AVG t()] =
//[6, 9.4000006, 8.4000006]
//
//[m_REDUCE_MAX] =
//[11, 12, 15, 14, 10]
//
//[m_REDUCE_MIN t()] =
//[2;
//6;
//1]
//[m_REDUCE_MIN] =
//[2, 6, 1]


int main() {

	Mat_<float> m1(3, 5);		//Matx 객체로 간편 초기화, cv::reduce()의 입력행렬은 CV_32F나 CV_64F형으로 지정되야한다. 
	m1 << 11, 2, 3, 4, 10,
		6, 10, 15, 9, 7,
		7, 12, 8, 14, 1;

	Mat m_reduce1, m_reduce2, m_reduce3, m_reduce4;

	reduce(m1, m_reduce1, 0, REDUCE_SUM);	//0 - 열방향 감축
	reduce(m1, m_reduce2, 1, REDUCE_AVG);	//1 - 행방향 감축 
	reduce(m1, m_reduce3, 0, REDUCE_MAX);
	reduce(m1, m_reduce4, 1, REDUCE_MIN);

	cout << "[m1] = " << endl << m1 << endl << endl; 
	cout << "[m_REDUCE_SUM] = " << endl << m_reduce1 << endl << endl;
	cout << "[m_REDUCE_AVG] = " << endl << m_reduce2 << endl;
	cout << "[m_REDUCE_AVG t()] = " << endl << m_reduce2.t() << endl << endl;	//1행 출력 위해 행렬 전치 
	cout << "[m_REDUCE_MAX] = " << endl << m_reduce3 << endl << endl;
	cout << "[m_REDUCE_MIN t()] = " << endl << m_reduce4 << endl;
	cout << "[m_REDUCE_MIN] = " << endl << m_reduce4.t() << endl << endl;

	return 0;
}

