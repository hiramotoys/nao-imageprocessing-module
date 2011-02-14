#ifndef CrossStripesCameraSensor_H
#define CrossStripesCameraSensor_H

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "CameraSensor.h"

class CrossStripesCameraSensor : public CameraSensor{
private:
    cv::Mat image;
public:
    CrossStripesCameraSensor();
    ~CrossStripesCameraSensor();
    void updateImage();
    void update(const char *readfilename, const char *writefilename);
    void detectLines();
    void detectBall();
    void detectNao();
    void detectGoal();
 private:
    bool isGreenToWhite(int r1, int g1, int b1, int r2, int g2, int g3);
    bool isWhiteToGreen(int r1, int g1, int b1, int r2, int g2, int g3);
};

#endif // CrossStripesCameraSensor
