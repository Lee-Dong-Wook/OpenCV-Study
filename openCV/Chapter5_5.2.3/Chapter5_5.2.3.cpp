#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.2.3 임의 채널 합성 
//cv::split() 함수로 다중 채널 행렬을 분리하고, 필요한 채널만 다시 cv::merge()로 합성해야한다.
//cv::mixChannels() 함수를 사용하면 번거로움을 없앨 수 있다. 

//void mixChannels() 명시된 채널의 순서쌍에 의해 입력 배열들(src)로 부터 출력 배열들(dst)의 복사한다. 

//void cv::mixChannels(const Mat *	src,
//							 size_t	nsrcs,
//							 Mat * 	dst,
//							 size_t ndsts,
//					   const int * 	fromTo,
//							 size_t npairs)

//void cv::mixChannels(InputArrayOfArrays			src,
//					   InputOutputArrayOfArrays 	dst,
//					   const int * 					fromTo,
//					   size_t 						npairs)

//void cv::mixChannels(InputArrayOfArrays 			src,
//					   InputOutputArrayOfArrays 	dst,
//			     const std::vector< int > & 		fromTo)

//Mat* src			 입력 배열 혹은 행렬 벡터
//size_t nsrcs       입력배열(src)의 행렬 개수  
//Mat* dst           입력배열 혹은 행렬 벡터 
//size_t ndsts       출력 배열(dst)의 행렬 개수 
//int* fromTo        입력과 출력의 순서쌍 배열 
//					 - 짝수 인덱스([k*2])는 입력 배열(src)의 채널 번호	
//					 - 홀수 인덱스([k*2+1])는 출력 배열(dst)의 채널 번호 
//size_npairs        순서상의 개수 

int main() {

	Mat ch0(3, 4, CV_8U, Scalar(10));		//단일 채널 생성, 1채널 uchar 행렬 선언 및 초기화  
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));
	Mat ch_012;

	//Mat vec_012[] = { ch0, ch1, ch2 };도 가능 
	vector<Mat> vec_012;							//행렬 원소를 갖는 벡터 
	vec_012.push_back(ch0);							//벡터에 단일 채널 행렬 추가 
	vec_012.push_back(ch1);
	vec_012.push_back(ch2);
	merge(vec_012, ch_012);							//행렬 벡터로 다중 채널 행렬 합성 

	Mat ch_02(ch_012.size(), CV_8UC2);				//채널 ch0, ch2만 추출하는 행렬 
	Mat ch_1(ch_012.size(), CV_8UC1);				//채널 ch1만 추출 
	Mat out[] = { ch_02, ch_1 };					

	int from_to[] = { 0,0,2,1,1,2 };				//입력 배열과 출력 배열의 순서쌍을 의미 
													//입력 배열 0번 채널이 출력 배열 0번 채널로 출력 
													//입력 배열 2번 채널이 출력 배열 1번 채널로 출력
													//입력 배열 1번 채널이 출력 배열 2번 채널로 출력
											
	mixChannels(&ch_012,1,out,2,from_to,3);			//채널 합성 

	cout << "[ch_012] = " << endl << ch_012	 << endl << endl;
	cout << "[ch_02] = " << endl << ch_02	 << endl;
	cout << "[ch_1]	= " << endl << ch_1		 << endl;
	waitKey();
	return 0;
}

