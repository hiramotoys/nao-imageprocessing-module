#ifndef CameraSensor_H
#define CameraSensor_H

#include <string>
#include <alproxies/almemoryproxy.h>
#include <alproxies/alvideodeviceproxy.h>
#include <alvision/alvisiondefinitions.h>
#include <alvision/alimage.h>

class CameraSensor{
private:
    AL::ALPtr<AL::ALVideoDeviceProxy> videoProxy;
    AL::ALValue alimagevalue;
public:
    CameraSensor();
    CameraSensor(std::string IP);
    virtual ~CameraSensor();
    virtual void updateImage();
private:
    connectToNao(std::string IP);
};

#endif // ImageWidget_H
