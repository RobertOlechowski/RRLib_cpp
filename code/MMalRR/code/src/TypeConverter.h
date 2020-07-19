#pragma once


#include "MMalRR/Metering.h"
#include "MMalRR/AWB.h"
#include "MMalRR/Exposure.h"
#include "MMalRR/Effect.h"

#include <interface/mmal/util/mmal_util.h>

namespace RRLibs::MMalRR {

class TypeConverter {
public:
    static MMAL_PARAM_EXPOSUREMETERINGMODE_T convertMetering(Metering metering);

    static MMAL_PARAM_EXPOSUREMODE_T convertExposure(Exposure exposure);

    static MMAL_PARAM_AWBMODE_T convertAWB(AWB awb);

    static MMAL_PARAM_IMAGEFX_T convertImageEffect(Effect imageEffect);
};

}



