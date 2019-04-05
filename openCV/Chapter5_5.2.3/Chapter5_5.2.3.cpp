#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.2.3 ���� ä�� �ռ� 
//cv::split() �Լ��� ���� ä�� ����� �и��ϰ�, �ʿ��� ä�θ� �ٽ� cv::merge()�� �ռ��ؾ��Ѵ�.
//cv::mixChannels() �Լ��� ����ϸ� ���ŷο��� ���� �� �ִ�. 

//void mixChannels() ��õ� ä���� �����ֿ� ���� �Է� �迭��(src)�� ���� ��� �迭��(dst)�� �����Ѵ�. 

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

//Mat* src			 �Է� �迭 Ȥ�� ��� ����
//size_t nsrcs       �Է¹迭(src)�� ��� ����  
//Mat* dst           �Է¹迭 Ȥ�� ��� ���� 
//size_t ndsts       ��� �迭(dst)�� ��� ���� 
//int* fromTo        �Է°� ����� ������ �迭 
//					 - ¦�� �ε���([k*2])�� �Է� �迭(src)�� ä�� ��ȣ	
//					 - Ȧ�� �ε���([k*2+1])�� ��� �迭(dst)�� ä�� ��ȣ 
//size_npairs        �������� ���� 

int main() {

	Mat ch0(3, 4, CV_8U, Scalar(10));		//���� ä�� ����, 1ä�� uchar ��� ���� �� �ʱ�ȭ  
	Mat ch1(3, 4, CV_8U, Scalar(20));
	Mat ch2(3, 4, CV_8U, Scalar(30));
	Mat ch_012;

	//Mat vec_012[] = { ch0, ch1, ch2 };�� ���� 
	vector<Mat> vec_012;							//��� ���Ҹ� ���� ���� 
	vec_012.push_back(ch0);							//���Ϳ� ���� ä�� ��� �߰� 
	vec_012.push_back(ch1);
	vec_012.push_back(ch2);
	merge(vec_012, ch_012);							//��� ���ͷ� ���� ä�� ��� �ռ� 

	Mat ch_02(ch_012.size(), CV_8UC2);				//ä�� ch0, ch2�� �����ϴ� ��� 
	Mat ch_1(ch_012.size(), CV_8UC1);				//ä�� ch1�� ���� 
	Mat out[] = { ch_02, ch_1 };					

	int from_to[] = { 0,0,2,1,1,2 };				//�Է� �迭�� ��� �迭�� �������� �ǹ� 
													//�Է� �迭 0�� ä���� ��� �迭 0�� ä�η� ��� 
													//�Է� �迭 2�� ä���� ��� �迭 1�� ä�η� ���
													//�Է� �迭 1�� ä���� ��� �迭 2�� ä�η� ���
											
	mixChannels(&ch_012,1,out,2,from_to,3);			//ä�� �ռ� 

	cout << "[ch_012] = " << endl << ch_012	 << endl << endl;
	cout << "[ch_02] = " << endl << ch_02	 << endl;
	cout << "[ch_1]	= " << endl << ch_1		 << endl;
	waitKey();
	return 0;
}

