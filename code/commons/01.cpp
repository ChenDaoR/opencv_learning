#include <opencv2/opencv.hpp>
#include <iostream>


int main()
{
    //读取图像
    cv::Mat pic = cv::imread("../src/demo.jpg" , cv::IMREAD_COLOR);
    
    cv::imshow("demo",pic);
    cv::waitKey(0);    

    return 0;
}