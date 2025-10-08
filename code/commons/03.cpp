#include<opencv2/opencv.hpp>
#include <string>
//using namespace cv;
//using namespace std;

int main(int argc, char* argv[])
{
	//（1）读取图像
	std::string img_path = "../src/demo.jpg";
	cv::Mat img = cv::imread(img_path, 1);

	//（2）判断图像是否读取成功
	if (img.empty())
	{
		std::cout << "can't read image!" << std::endl;
		return -1;
	}

	//（3）空间颜色转换
	cv::Mat img_RGB, img_gray;
	cv::cvtColor(img, img_RGB, cv::COLOR_BGR2RGB);
	cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);

	//（4）显示图像
	cv::imshow("img", img);
	cv::imshow("RGB", img_RGB);
	cv::imshow("gray", img_gray);

	cv::waitKey(0);		//等待用户任意按键后结束暂停功能
	return 0;
}