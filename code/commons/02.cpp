#include<opencv2/opencv.hpp>
#include <string>
//using namespace cv;
//using namespace std;

int main(int argc,char* argv[])
{
	//输入图像（字符串）路径的五种方法：
	//（1）单左斜线法		string imgpath = "C:/Users/pc/Desktop/test.jpg";
	//（2）双右斜线法		string imgpath = "C:\\Users\\pc\\Desktop\\test.jpg";
	//（3）双左斜线法		string imgpath = "C://Users//pc//Desktop//test.jpg";
	//（4）以上三种混合法		string imgpath = "C:/Users//pc\\Desktop//test.jpg";
	//（5）相对路径法		string imgpath = "test.jpg";
	
	//（1）读取图像
	std::string img_path = "../src/demo.jpg";	
	cv::Mat img = cv::imread(img_path, 1);		
				
	//（2）判断图像是否读取成功
	if(img.empty())											
	{
		std::cout << "can't read image!" << std::endl;
		return -1;
	}
    
    //（3）打印图像信息
	std::cout << "宽度："<<img.cols << std::endl;
	std::cout << "高度：" << img.rows << std::endl;
	std::cout << "通道数：" << img.channels() << std::endl;
	std::cout << "字节数：" << img.elemSize() / img.channels()*8 << std::endl;
	unsigned char* pData = img.data;
	std::cout << "数据地址：" << &pData << std::endl;
	//std::cout << "打印矩阵：" << img << std::endl;
	
	//（4）保存与显示图像
	cv::imwrite("../src/save.jpg", img);		//保存图像
	cv::imshow("img", img);									//显示图像
	
	cv::waitKey(0);		//等待用户任意按键后结束暂停功能
	return 0;
}