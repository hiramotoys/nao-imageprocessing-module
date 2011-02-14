#include <stdio.h>

#include "WrapCrossStripesCameraSensor.h"
#include "../../src/CrossStripesCameraSensor.h"

void imageprocessing(const char *readfilename, const char *writefilemame){
    CrossStripesCameraSensor *cscSensor = new CrossStripesCameraSensor();
    cscSensor->update(readfilename, writefilemame);
    delete cscSensor;
}
