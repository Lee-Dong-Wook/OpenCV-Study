#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.1.2 Mat::ptr()을 통한 행렬 원소 접근 

// ** 행렬에서 지정된 행에 대한 포인터를 반환. 행단위 처리를 할 때 사용. ** 
//uchar* 혹은 해당 행렬 자료형으로 포인터를 반환 
//uchar*형 행렬에서는 반환자료형을 생략가능, 다른 자료형 행렬은 자료형 명시 

//예시는 행에 대한 포인터를 사용하여 행렬에 접근하여 행렬 원소값을 지정하는 두가지 방법을 다룸. 

//실행결과 
//m1 =
//[0, 1, 2, 3, 4;
// 0, 1, 2, 3, 4;
// 0, 1, 2, 3, 4]
//
//m2 =
//[0, 1, 2, 3, 4;
// 0, 1, 2, 3, 4;
// 0, 1, 2, 3, 4]

int main() {

	Mat m1(3, 5, CV_8UC1);				//uchar형 
	Mat m2(m1.size(), CV_32FC1);		//float형 m1.size()를 통해 3x5를 표현 
	

	for (int i = 0; i < m1.rows; i++) {

		uchar *ptr_m1 = m1.ptr(i);			//* 각 행렬의 i행 첫 주소 반환 * 
		float *ptr_m2 = m2.ptr<float>(i);	//uchar형과 달리 다른 자료형이기에 반환형 명시 
		
		for (int j = 0; j < m1.cols; j++) {

			ptr_m1[j] = j;					// ptr_m1이 행에 대한 포인터로써 배열 첨자로 원소 접근 접근 
			*(ptr_m2 + j) = (float)j;		// 원소 접근 방식을 포인터 형식으로 구성, de-referencing을 하여 포인터가 가리키고 있는 값에 저장 
			
		}
	}

	cout << "m1 = " << endl << m1 << endl << endl; 
	cout << "m2 = " << endl << m2 << endl;
	
	return 0;
}