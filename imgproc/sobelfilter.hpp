#ifndef SOBEL_FILTER_H
#define SOBEL_FILTER_H

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

int apply_sobel_filter()
{
    // First we declare the variables we are going to use
    cv::Mat image, src, src_gray;
    cv::Mat grad;

    // kernel size ksize is the size of the extended Sobel kernel; it must be 1, 3, 5, or 7.
    int ksize = 3;

    // scale optional scale factor for the computed derivative values; by default, no scaling is applied
    int scale = 1;

    // optional delta value that is added to the results prior to storing them in dst.
    int delta = 0;

    // Image depth
    int ddepth = CV_16S;
    
    // Read the image file
    image = cv::imread("./dog.jpg", cv::IMREAD_COLOR );

    // Check if image is loaded fine
    if( image.empty() )
    {
        std::cout << "Could not open or find the image" << std::endl;
        return EXIT_FAILURE;
    }

    // Remove noise by blurring with a Gaussian filter ( kernel size = 3 )
    GaussianBlur(image, src, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);

    // Convert the image to grayscale
    cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);


    cv::Mat grad_x, grad_y;
    cv::Mat abs_grad_x, abs_grad_y;


    Sobel(src_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, cv::BORDER_DEFAULT);
    Sobel(src_gray, grad_y, ddepth, 0, 1, ksize, scale, delta, cv::BORDER_DEFAULT);


    // converting back to CV_8U
    convertScaleAbs(grad_x, abs_grad_x);
    convertScaleAbs(grad_y, abs_grad_y);


    // Gradient
    addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);



    const cv::String window_name = "Sobel Demo - Simple Edge Detector";

    imshow("Original Image", image);

    imshow("Gaussian Blur Image", src);

    imshow(window_name, grad);

    cv::waitKey(0);                     // Wait for any keystroke in the window
    cv::destroyWindow(window_name);     //destroy the created window

    return EXIT_SUCCESS;
}

#endif // SOBEL_FILTER_H
