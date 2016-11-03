//
// Created by skruzic on 03.11.16..
//

#ifndef STITCH_SIFTFEATURESFINDER_HPP
#define STITCH_SIFTFEATURESFINDER_HPP

#include <opencv2/stitching/detail/matchers.hpp>


#ifdef HAVE_OPENCV_XFEATURES2D

#include "opencv2/xfeatures2d/cuda.hpp"

#endif

namespace cv {
    namespace detail {
        class SiftFeaturesFinder : public FeaturesFinder {
        public:
            SiftFeaturesFinder();
        private:
            void find(InputArray image, ImageFeatures &features);
            void collectGarbage();

            Ptr<FeatureDetector> detector_;
            Ptr<DescriptorExtractor> extractor_;
            Ptr<Feature2D> sift;
        };
    }
}


#endif //STITCH_SIFTFEATURESFINDER_HPP
