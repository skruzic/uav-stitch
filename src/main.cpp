#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/stitching.hpp>
#include <SiftFeaturesFinder.hpp>

using namespace std;
using namespace cv;

vector<UMat> loadImages(String path) {
    vector<UMat> images;

    vector<String> files;
    glob(path, files, false);

    for (int i = 0; i < files.size(); ++i) {
        images.push_back(imread(files[i]).getUMat(ACCESS_READ));
    }

    return images;
}

int main(int argc, char *argv[]) {
    String path = argv[1];

    vector<UMat> imgs = loadImages(path);

    Mat matching_mask = Mat::zeros(imgs.size(), imgs.size(), CV_8U);

    for (int i = 0; i < imgs.size() - 1; ++i) {
        matching_mask.at<char>(i, i + 1) = 1;
        matching_mask.at<char>(i + 1, i) = 1;
    }

    UMat matching_mask_;
    matching_mask.copyTo(matching_mask_);

    UMat pano;

    Ptr<Stitcher> st = Stitcher::create(Stitcher::Mode::SCANS, false);
    st->setFeaturesFinder(makePtr<detail::SiftFeaturesFinder>());
    st->setFeaturesMatcher(makePtr<detail::AffineBestOf2NearestMatcher>(false, false, 0.65f));
    //st->setFeaturesMatcher(makePtr<detail::AffineMatcher>());
    st->setMatchingMask(matching_mask_);
    //st->setBundleAdjuster(makePtr<detail::BundleAdjusterAffine>());


    st->stitch(imgs, pano);

    imwrite("result.jpg", pano);

    return 0;
}