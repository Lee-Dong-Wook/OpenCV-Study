#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.6.3 FileStorage Ŭ������ ��� ������ ���� 
//test.xml ������ �о� picture ����� ������ �������ϵ��� �о� ���̰� 
//�� ������� ä�κ��� ��հ� ǥ�������� �����ͷ� ������ ����. 

//���� ��� 
//fs_r���� xml ���Ͽ� ����� �̹����� �̸��� ������� ����� �����Ѵ�. 
//imshow(node_pic[i], images[i]); �ڵ� �κп��� �����. 3���� �̹����� ����س��� ����, cmd â�� �ƹ��� �޼����� ����. 
//�ش� ������Ʈ ���Ͽ� ���� result.xml�� �����Ǿ����� 0KB�̴�. 
//�̹��� â�� ��� ������ ��μ� CMDâ�� �޼��� ���, result.xml�� ���� 1KB�� imshow(node_pic[i], images[i]); ���� �ڵ尡 ���� 
//������ �� �̹����� ���ؼ� ��հ� ǥ�������� ���Ѵ�. 
//result.xml �� �̹����� ���� ��հ� ǥ�������� ����ȴ�. 

int main(){

	FileStorage fs_r("test.xml",FileStorage::READ);			//test.xml�� ���丮�� ��ü�� �д´�. 
	CV_Assert(fs_r.isOpened());								//����ó�� 

	FileNode node_pic = fs_r["picture"];					//������ ���
	vector<Mat> images;

	string filePath = "C:/Users/Raynor/Desktop/openCVEXImage/";
	for (int i = 0; i < node_pic.size(); i++) {

		//�̹����� ��ķ� �޾ƿ´�. ��������� ��Ʈ������ �ް� xml���Ͽ� ����� ���ϸ��� �޾ƿ� string���� ��ȯ�Ͽ� ��η� �����Ͽ���. 
		Mat tmp = imread(filePath + (string)node_pic[i], IMREAD_UNCHANGED); //���� ���� ������� �б� 
		CV_Assert(tmp.data);
		images.push_back(tmp);
		imshow(node_pic[i], images[i]);
	}

	FileStorage fs_w("result.xml", FileStorage::WRITE);		//���丮�� ��ü ������ 
	CV_Assert(fs_w.isOpened());

	vector<double> mean, dev; 
	for (int i = 0; i < images.size(); i++) {

		string pic_name = ((string)node_pic[i]).substr(0,5);	//string.substr() ���� �̸��� ������ ���� 
		
		meanStdDev(images[i], mean, dev);						//��հ� ǥ�������� ���ͷ� ��ȯ 
		fs_w << pic_name + "_mean" << "[";						//������ ���� ���� 

		for (int j = 0; j < (int)mean.size(); j++) {			//�� ä�� ����� ���ҷ� ���� 
			fs_w << mean[i];									//�����ϳ��� ���� 
		}

		fs_w << "]";
		fs_w << pic_name + "_dev" << dev;						//ǥ�������� ���ͷ� ���� 
	}

	waitKey();													//Ű�Է��� ���� ������ ���������ʴ´�. ���� �� �����ϰ� �ٷ� ���α׷��� ����ȴ�.	
	fs_r.release();

	return 0;

	
}

