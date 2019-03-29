#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.6.2 FileStorage Ŭ������ �����б�
//������ ������Ʈ ���� �־�� �ٷ����ٰ����ϴ�. Ȥ�� ��θ� ����ؾ��Ѵ�. 
int main() {

	FileStorage fs("test.xml", FileStorage::READ);			//�б���� ���� 
	CV_Assert(fs.isOpened());

	string name, university, picture;
	int age;
	
	fs["university"] >> university;							//��� ���� ���, Ű���� ��Ʈ��(>>)�����ڷ� �о�´�. 
	fs["name"]		 >> name;
	fs["age"]		 >> age;

	cout << "university : " << university << endl;
	cout << "name : "		<< name		  << endl;
	cout << "age : "		<< age		  << endl;
	
	//�ݷ��� ��� �������� 
	FileNode node_pic	= fs["picture"];					//������ ��� 	
	FileNode node_hd	= fs["hardware"];					//���� ��� 

	try {													//����ó��	

		if(node_pic.type() != FileNode::SEQ) 				//��Ʈ Ÿ�� �˻� 
			CV_Error(Error::StsError, "������ ��尡 �ƴմϴ�.");
		
		if (!node_hd.isMap()) 
			CV_Error(Error::StsError, "���� ��尡 �ƴմϴ�.");		
	}
	catch (Exception &e) { exit(1); }

	cout << "[picture] ";									//������ ���, �ε����� ���� 
	cout << (string)node_pic[0] << ", "; 
	cout << (string)node_pic[1] << ", "; 
	cout << (string)node_pic[2] << endl << endl; 

	cout << "[hardware]" << endl;							//���γ��, Ű������ ���� 
	cout << " cpu " << (int)node_hd["cpu"] << endl;
	cout << " mainboard "<< (int)node_hd["mainboard"] << endl;
	cout << " ram  " << (int)node_hd["ram"] << endl << endl;

	Point			pt;
	Rect			rect;
	Mat				mat; 
	vector<float>	vec;

	fs["vector"]	>>  vec;								//���� ������ ���� 
	fs["Point"]		>>  pt;		
	fs["Rect"]		>>  rect;
	fs["Mat"]		>>  mat;								//��� ������ ���� 	

	cout << "[vec] = "  << ((Mat)vec).t() << endl;				//���͸� ��ķ� �� ��ȯ �� ��ġ ���� 1�࿡ ����ϱ� ���� 							
	cout << " pt   = "  << pt			  << endl;
	cout << " rect = "  << rect			  << endl << endl;
	cout << " mat  = "  << endl << mat << endl;
	
	fs.release();

	return 0;
}

