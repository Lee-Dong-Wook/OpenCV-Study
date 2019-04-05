#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.5.4 cv::sortldx() 활용한 사각형 크기 정렬 

//실행결과
//---------- - 랜덤 사각형 정보------------ -
//------------------------------------------ -
//rects[0] = [70 x 59 from(130, 157)]
//rects[1] = [189 x 59 from(135, 172)]
//rects[2] = [25 x 110 from(252, 85)]
//rects[3] = [321 x 142 from(10, 4)]
//rects[4] = [102 x 328 from(125, 62)]
//
//크기순 정렬 사각형 정보        크기
//------------------------------------------ -
//[25 x 110 from(252, 85)]       2750
//[70 x 59 from(130, 157)]       4130
//[189 x 59 from(135, 172)]      11151
//[102 x 328 from(125, 62)]      33456
//[321 x 142 from(10, 4)]        45582

int main() {

	Matx<ushort, 5, 4> pts;								//5행, 4열 ushort행렬 선언, 2쌍의 좌표 5개 생성을 위함
	Mat_<int> sizes, sort_idx;							//사각형 크기 벡터와 정렬 인덱스 벡터 	
	vector<Rect> rects;
	randn(pts, Scalar(200), Scalar(100));				//랜덤 값 생성, 임의 사각형 생성, 평균과 표준 편차로 
														//정규분포 값을 생성해 행렬로 반환. (행렬, 평균, 표준편차)

	cout << "-------------------------------------------" << endl;
	cout << "-----------  랜덤 사각형 정보   -------------" << endl;
	cout << "-------------------------------------------" << endl;

	for (int i = 0; i < pts.rows; i++) {

		Point pt1(pts(i, 0), pts(i, 1));				//사각형 시작 좌표 , 한행의 4개 원소로 2개 좌표 생성
		Point pt2(pts(i, 2), pts(i, 3));				//사각형 종료 좌표 , 한행의 4개 원소로 2개 좌표 생성 

		rects.push_back(Rect( pt1, pt2));				//벡터 저장, 2개의 좌표로 사각형 지정 		
		sizes.push_back(rects[i].area());				//사각형 크기 저장 				
		
		cout << format("rects[%d] = ", i) << rects[i] << endl; 
	}

	//정렬 후, 정렬 원소의 원본 인덱스 반환
	sortIdx(sizes, sort_idx, SORT_EVERY_COLUMN);		//열단위 오름차순 정렬 후 원본 좌표 반환 	

	cout << endl << " 크기순 정렬 사각형 정보 \t크기" << endl; 
	cout << "-------------------------------------------" << endl;
	
	for (int i = 0; i < rects.size(); i++) {
		
		int idx = sort_idx(i);
		cout << rects[idx] << "\t" << sizes(idx) << endl; //정렬된 좌표로 사각형 넓이순 출력 
	}

	cout << "-------------------------------------------" << endl;
	return 0;


}

