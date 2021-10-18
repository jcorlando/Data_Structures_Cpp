#include <opencv2/opencv.hpp>
#include <iostream>
#include "imageprocessing.hpp"


int main()
{
    // Read the image file
    cv::Mat image = cv::imread("./lena.jpg");

    // Check for failure
    if (image.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        std::cin.get(); //wait for any key press
        return -1;
    }

    cv::String windowName = "Lena JPG"; //Name of the window

    cv::namedWindow(windowName); // Create a window

    cv::imshow(windowName, image); // Show our image inside the created window.

    cv::waitKey(0); // Wait for any keystroke in the window

    cv::destroyWindow(windowName); //destroy the created window

    return 0;
}
