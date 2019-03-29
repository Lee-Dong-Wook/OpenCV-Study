#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//4.6.2 FileStorage 클래스로 파일읽기
//파일은 프로젝트 내에 있어야 바로접근가능하다. 혹은 경로를 명시해야한다. 
int main() {

	FileStorage fs("test.xml", FileStorage::READ);			//읽기모드로 연결 
	CV_Assert(fs.isOpened());

	string name, university, picture;
	int age;
	
	fs["university"] >> university;							//노드 접근 방법, 키값과 스트림(>>)연산자로 읽어온다. 
	fs["name"]		 >> name;
	fs["age"]		 >> age;

	cout << "university : " << university << endl;
	cout << "name : "		<< name		  << endl;
	cout << "age : "		<< age		  << endl;
	
	//콜렉션 노드 가져오기 
	FileNode node_pic	= fs["picture"];					//시퀸스 노드 	
	FileNode node_hd	= fs["hardware"];					//매핑 노드 

	try {													//예외처리	

		if(node_pic.type() != FileNode::SEQ) 				//노트 타입 검사 
			CV_Error(Error::StsError, "시퀸스 노드가 아닙니다.");
		
		if (!node_hd.isMap()) 
			CV_Error(Error::StsError, "매핑 노드가 아닙니다.");		
	}
	catch (Exception &e) { exit(1); }

	cout << "[picture] ";									//시퀸스 노드, 인덱스로 접근 
	cout << (string)node_pic[0] << ", "; 
	cout << (string)node_pic[1] << ", "; 
	cout << (string)node_pic[2] << endl << endl; 

	cout << "[hardware]" << endl;							//매핑노드, 키값으로 접근 
	cout << " cpu " << (int)node_hd["cpu"] << endl;
	cout << " mainboard "<< (int)node_hd["mainboard"] << endl;
	cout << " ram  " << (int)node_hd["ram"] << endl << endl;

	Point			pt;
	Rect			rect;
	Mat				mat; 
	vector<float>	vec;

	fs["vector"]	>>  vec;								//벡터 데이터 접근 
	fs["Point"]		>>  pt;		
	fs["Rect"]		>>  rect;
	fs["Mat"]		>>  mat;								//행렬 데이터 접근 	

	cout << "[vec] = "  << ((Mat)vec).t() << endl;				//벡터를 행렬로 형 변환 후 전치 수행 1행에 출력하기 위해 							
	cout << " pt   = "  << pt			  << endl;
	cout << " rect = "  << rect			  << endl << endl;
	cout << " mat  = "  << endl << mat << endl;
	
	fs.release();

	return 0;
}

