//
// Created by skruzic on 03.11.16..
//

#include "SiftFeaturesFinder.hpp"
#include <opencv2/imgproc.hpp>

#ifdef HAVE_OPENCV_XFEATURES2D

#include "opencv2/xfeatures2d.hpp"

using cv::xfeatures2d::SIFT;
#endif

namespace cv {
    namespace detail {
        SiftFeaturesFinder::SiftFeaturesFinder() {
#ifdef HAVE_OPENCV_XFEATURES2D
            Ptr<SIFT> sdetector_ = SIFT::create(800, 3, 0.03, 10, 1.4142);
            Ptr<SIFT> sextractor_ = SIFT::create(800, 3, 0.03, 10, 1.4142);

            if (!sdetector_ || !sextractor_)
                CV_Error(Error::StsNotImplemented, "OpenCV was build without SIFT support");

            detector_ = sdetector_;
            extractor_ = sextractor_;
#else
            CV_Error(Error::StsNotImplemented, "OpenCV was build without SIFT support");
#endif
        }

        void SiftFeaturesFinder::find(InputArray image, ImageFeatures &features) {
            UMat gray_image;
            CV_Assert((image.type() == CV_8UC3) || (image.type() == CV_8UC1));
            if (image.type() == CV_8UC3) {
                cvtColor(image, gray_image, COLOR_BGR2GRAY);
            } else {
                gray_image = image.getUMat();
            }
            if (!sift) {
                detector_->detect(gray_image, features.keypoints);
                extractor_->compute(gray_image, features.keypoints, features.descriptors);
            } else {
                UMat descriptors;
                sift->detectAndCompute(gray_image, Mat(), features.keypoints, descriptors);
                features.descriptors = descriptors.reshape(1, (int) features.keypoints.size());
            }
        }

        void SiftFeaturesFinder::collectGarbage() {

        }
    }
}