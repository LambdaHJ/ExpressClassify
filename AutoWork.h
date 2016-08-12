//
// Created by 黄金 on 2016/8/2.
//

#ifndef AUTOCLASSIFY_AUTOWORK_H
#define AUTOCLASSIFY_AUTOWORK_H

#include <zbar.h>
#include <opencv2/core/core.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <tesseract/baseapi.h>

using namespace std;
using namespace cv;
using namespace tesseract;
using namespace zbar;

class AutoWork {

public:
    // tesseract 初始化
    void init(const char *path);
    // 定位面单区域
    Mat locate_express(Mat src);
    // 提取条码
    string extract_bar(Mat *obj);
    // 提取手机号
    string extract_phone(Mat *obj);

private:
    // tesseract 识别程序接口
    TessBaseAPI *api;
    // 识别条码程序
    string recognize_bar(Mat area);
    // 识别手机号程序
    string recognize_num(Mat image, bool isPhone = false);
};


#endif //AUTOCLASSIFY_AUTOWORK_H
