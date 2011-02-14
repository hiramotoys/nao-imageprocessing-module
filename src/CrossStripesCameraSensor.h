#ifndef CrossStripesCameraSensor_H
#define CrossStripesCameraSensor_H

#include <opencv/cv.h>
#include "CameraSensor.h"

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
    void detectGoal();
};

#endif // CrossStripesCameraSensor
