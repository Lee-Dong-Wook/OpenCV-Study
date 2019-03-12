#include <opencv2/highgui.hpp>

void main() {

	cv::Mat image(300, 400, CV_8UC1, cv::Scalar(0));
	cv::imshow("imageshow",image);
	cv::waitKey(0);
}