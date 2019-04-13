#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
	
//4.5.3 ī�޶� ������ ������ ���� ���� 
//������ 
//width x hieght : [640 x 360]
//VideoWriter::fourcc : 808802372
//delay : 33
//fps : 29.97
//
//ī�޶� ����Ǿ� �Կ��ϴ� ���ÿ� �ٷ� ���������Ϸ� ����ȴ�. 

int main() {


	VideoCapture capture(0);										//������ü ���� �� 0�� ī�޶� ���� 
	CV_Assert(capture.isOpened());									//ī�޶� ���� ���� ó�� 

	double fps = 29.97;												//�ʴ� ������ �� 
	int	   delay = cvRound(1000.0 / fps);							//�����Ӱ� �����ð� 
	Size   size(1920,1080);											//������ ���� �ػ�
	int	   fourcc = VideoWriter::fourcc('D','X','5','0');			//���� �ڵ� ���� 

	capture.set(CAP_PROP_FRAME_WIDTH, size.width);					//�ػ� ����(���� �ػ� ���� ) 
	capture.set(CAP_PROP_FRAME_HEIGHT, size.height);
	
	cout << "width x hieght : "			<< size << endl;
	cout << "VideoWriter::fourcc : "	<< fourcc << endl;			//������ ���� �ܼ�â ��� 
	cout << "delay : " << delay			<< endl; 
	cout << "fps : " << fps				<< endl;

	VideoWriter writer;												//������ ���� ���� ��ü 
	writer.open("C:/Users/Raynor/Desktop/openCVEXImage/Sleep dongwook.avi",fourcc,fps,size); //���� ���� �� ���� 
	CV_Assert(writer.isOpened());
	
	while (true) {
		Mat frame;
		capture >> frame;											//ī�޶� ����ޱ� 
		writer << frame;											//�������� ���������� ���� 
		//writer.write(frame);

		imshow("ī�޶� ���󺸱�", frame);
		if (waitKey(delay) > 0) break;
	}
	return 0;
}

