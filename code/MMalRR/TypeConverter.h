#pragma once

#include "interface/mmal/util/mmal_util.h"
#include "Metering.h"
#include "AWB.h"
#include "Exposure.h"
#include "Effect.h"

namespace RRLibs::MMalRR {

class TypeConverter {
public:
    static MMAL_PARAM_EXPOSUREMETERINGMODE_T convertMetering(Metering metering);

    static MMAL_PARAM_EXPOSUREMODE_T convertExposure(Exposure exposure);

    static MMAL_PARAM_AWBMODE_T convertAWB(AWB awb);

    static MMAL_PARAM_IMAGEFX_T convertImageEffect(Effect imageEffect);
};

}



