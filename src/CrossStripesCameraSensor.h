#ifndef CrossStripesCameraSensor_H
#define CrossStripesCameraSensor_H

#include <opencv/cv.h>

class CrossStripesCameraSensor : public CameraSensor{
private:
    cv::Mat image;
public:
    CrossStripesCameraSensor();
    ~CrossStripesCameraSensor();
    void updateImage();
    void detectLines();
    void detectBall();
    void detectNao();
    void detectGoad();
}

#endif // CrossStripesCameraSensor
