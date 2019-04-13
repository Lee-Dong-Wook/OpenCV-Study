#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

//6.1.3 반복자를 통한 행렬 원소 접근 

//반복자를 사용해서 데이터 요소에 접근
//콜렉션의 각 요소를 조회하기 위한 전문클래스, 콜렉션의 타입이나 내부 구조와 관계없이 동일하게 
//사용 가능하기에 접근 방식을 일반화 할 수 있는 장점 

//MatIterator_ 읽기, 쓰기 가능 
//MatConstIterator_ 읽기만 가능

//실행 결과 
//m1 =
//[1, 2, 3;
// 1, 2, 3;
// 1, 2, 3]

//m2 =
//[1, 2, 3;
// 1, 2, 3;
// 1, 2, 3]

//m3 =
//[0, 1, 2, 0, 2, 4, 0, 3, 6;
// 0, 1, 2, 0, 2, 4, 0, 3, 6;
// 0, 1, 2, 0, 2, 4, 0, 3, 6]

int main() {

	uchar data[] = {

		1, 2, 3,
		1, 2, 3,
		1, 2, 3,
	};

	Mat m1(3, 3, CV_8UC1, data);			// uchar형 배열로 초기화 
	Mat m2(m1.size(), m1.type());			//m1행렬과 같은 크기와 타입
	Mat m3(m1.size(), CV_32FC3);            //m1행렬과 같은 크기와 3채널 float형 

	MatConstIterator_<uchar> it_m1 = m1.begin<uchar>();		//읽기 전용 및 행렬 시작위치로 반복자 선언 
	MatIterator_<uchar>		 it_m2 = m2.begin<uchar>();     //읽기 및 쓰기 
	Mat_<Vec3f>::iterator    it_m3 = m3.begin<Vec3f>();

	for (; it_m1 != m1.end<uchar>(); ++it_m1, ++it_m2, ++it_m3) {

		*it_m2 = *it_m1;	//역참조(de-referencing) 포인터가 가리키고 있는 값 
		
		/*(*it_m3)[0] = *it_m1 * 0.5f;
		  (*it_m3)[1] = *it_m1 * 0.3f;
		  (*it_m3)[2] = *it_m1 * 0.2f;*/

		for (int i = 0; i < m3.channels(); i++) {

			(*it_m3)[i] = *it_m1 * i;
		}
		

		//*it_m1 = *it_m2;	//it_m1은 const형이기 때문에 데이터를 다시쓸 수 없음		
	}

	cout << "m1 = " << endl << m1 << endl;
	cout << "m2 = " << endl << m2 << endl;
	cout << "m3 = " << endl << m3 << endl;

	return 0;
}