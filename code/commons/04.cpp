#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

//using namespace std;
//using namespace cv;

int main(int argc, char* argv[])
{
	//（1）读取图像
	std::string img_path = "../src/demo.jpg";
	cv::Mat src = cv::imread(img_path, 1);

	//（2）判断图像是否读取成功
	if (!src.data)
	{
		std::cout << "can't read image!" << std::endl;
		return -1;
	}

	//（3）边缘填充
	float border_width = 0.2;
	int top		= (int)(border_width * src.rows);
	int bottom	= (int)(border_width * src.rows);
	int left	= (int)(border_width * src.cols);
	int right	= (int)(border_width * src.cols);
	
	cv::RNG rng;
	cv::Mat img1, img2, img3, img4, img5, img6, img7, img8, img9;
	cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
	
	cv::copyMakeBorder(src, img1, top, bottom, left, right, cv::BORDER_CONSTANT, color);
	cv::copyMakeBorder(src, img2, top, bottom, left, right, cv::BORDER_REPLICATE, color);
	cv::copyMakeBorder(src, img3, top, bottom, left, right, cv::BORDER_REFLECT, color);
	cv::copyMakeBorder(src, img4, top, bottom, left, right, cv::BORDER_WRAP, color);
	cv::copyMakeBorder(src, img5, top, bottom, left, right, cv::BORDER_REFLECT_101, color);
	//cv::copyMakeBorder(src, img6, top, bottom, left, right, cv::BORDER_TRANSPARENT, color);		//不可用
	cv::copyMakeBorder(src, img7, top, bottom, left, right, cv::BORDER_REFLECT101, color);
	cv::copyMakeBorder(src, img8, top, bottom, left, right, cv::BORDER_DEFAULT, color);
	cv::copyMakeBorder(src, img9, top, bottom, left, right, cv::BORDER_ISOLATED, color);

	//（4）显示图像
	cv::imshow("src", src);
	cv::imshow("img1", img1);
	cv::imshow("img2", img2);
	cv::imshow("img3", img3);
	cv::imshow("img4", img4);
	cv::imshow("img5", img5);
	//cv::imshow("img6", img6);		//不可用
	cv::imshow("img7", img7);
	cv::imshow("img8", img8);
	cv::imshow("img9", img9);
	
	cv::waitKey(0);
	return 0;
}