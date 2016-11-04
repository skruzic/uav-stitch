//
// Created by skruzic on 04.11.16..
//

#ifndef STITCH_UTIL_HPP
#define STITCH_UTIL_HPP

#include <opencv2/core.hpp>
#include <opencv2/stitching/detail/matchers.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace cv::detail;

void displayKeypoints(InputArray image, ImageFeatures &features);

void saveKeypoints(InputArray image, ImageFeatures &features, String name="out.jpg");

bool compareKeypoints(KeyPoint first, KeyPoint second);

#endif //STITCH_UTIL_HPP
