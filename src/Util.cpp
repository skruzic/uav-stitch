//
// Created by skruzic on 04.11.16..
//

#include "Util.hpp"

void displayKeypoints(InputArray image, ImageFeatures &features) {
    Mat img_keypoints;

    drawKeypoints(image, features.keypoints, img_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

    namedWindow("Keypoints", WINDOW_NORMAL);
    imshow("Keypoints", img_keypoints);

    waitKey(0);
}

void saveKeypoints(InputArray image, ImageFeatures &features, String name) {
    Mat img_keypoints;

    drawKeypoints(image, features.keypoints, img_keypoints, Scalar::all(-1), DrawMatchesFlags::DEFAULT);

    imwrite(name, img_keypoints);
}