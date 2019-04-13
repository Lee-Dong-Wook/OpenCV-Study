#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//5.6.2 cv::transform()을 이용한 회전 변환 

//행렬 곱셈은 컴퓨터 그래픽에서 물체를 회전시키거나 크기를 줄일 때와 같이 변환(transform)을 필요할 때 실제로 사용
//이 예제의 회전 중심점은 윈도우 최상단 왼쪽임을 주의 

//실행 결과 
//rect_pt1[0] = [200, 50]	      rect_pt2[0] = [171, 115]
//rect_pt1[1] = [400, 50]		  rect_pt2[1] = [359, 184]
//rect_pt1[2] = [400, 250]        rect_pt2[2] = [290, 372]
//rect_pt1[3] = [200, 250]        rect_pt2[3] = [102, 303]

int main() {

	vector<Point> rect_pt1, rect_pt2;		//입력좌표와 변환 결과좌표 벡터 
	rect_pt1.push_back(Point(200, 50 ));	//4개의 입력좌표 지정 	
	rect_pt1.push_back(Point(400, 50 ));	
	rect_pt1.push_back(Point(400, 250 ));
	rect_pt1.push_back(Point(200, 250 ));
	
	float theta = 20 * CV_PI / 180;										//라디안 각도 계산

	Matx22f m(cos(theta), -sin(theta), sin(theta), cos(theta));			//2행 2열 회전변환행렬 선언 , 회전각(theta)에 대한 sin(),cos()값을 계산하여 초기화 
																		//theta는 회전 변환 행렬 지정 			
	
	transform(rect_pt1, rect_pt2, m);									//rect1에 m을 곱해 rect2벡터로 반환! 즉, 회전된 좌표를 계산  		
																		//입력벡터(4개 좌표)에 cv::transform()함수로 
																		//회전 변환 행렬 적용하여 회전 변환 수행 
																		//-> 반환 벡터는 회전 변환된 좌푣르 			
	
	//400 x 500 = 400행, 500열 세로 : 400 가로 : 500
	Mat image(400, 500, CV_8UC3, Scalar(255, 255, 255));			//영상 생성 
	
	for (int i = 0; i < 4; i++) {									//4개 좌표 그리기 

		line(image, rect_pt1[i], rect_pt1[(i + 1) % 4], Scalar(0, 0, 0), 1);	//rect1 사각형을 그린다. 두께 1로 검은색 선으로 4개의 좌표에 그림을 그림 
		line(image, rect_pt2[i], rect_pt2[(i + 1) % 4], Scalar(0, 0, 0), 2);	//rect2 회전한 사각형을 그린다. 

		cout << "rect_pt1[" + to_string(i) + "] = " << rect_pt1[i] << "\t" ;
		cout << "rect_pt2[" + to_string(i) + "] = " << rect_pt2[i] << endl;
	}

	imshow("image", image);
	waitKey();
	return 0;


}

