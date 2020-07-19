#include "TypeConverter.h"
#include <Assert/Asserts.h>

namespace RRLibs::MMalRR {

MMAL_PARAM_EXPOSUREMETERINGMODE_T TypeConverter::convertMetering(Metering metering) {
    switch (metering) {
        case Metering::AVERAGE:
            return MMAL_PARAM_EXPOSUREMETERINGMODE_AVERAGE;
        case Metering::SPOT:
            return MMAL_PARAM_EXPOSUREMETERINGMODE_SPOT;
        case Metering::BACKLIT:
            return MMAL_PARAM_EXPOSUREMETERINGMODE_BACKLIT;
        case Metering::MATRIX:
            return MMAL_PARAM_EXPOSUREMETERINGMODE_MATRIX;
        default:
            RRLibs::assert_fail("convertMetering problem");
    }
}

MMAL_PARAM_EXPOSUREMODE_T TypeConverter::convertExposure(Exposure exposure) {

    switch (exposure) {
        case Exposure::OFF:
            return MMAL_PARAM_EXPOSUREMODE_OFF;
        case Exposure::AUTO:
            return MMAL_PARAM_EXPOSUREMODE_AUTO;
        case Exposure::NIGHT:
            return MMAL_PARAM_EXPOSUREMODE_NIGHT;
        case Exposure::NIGHTPREVIEW:
            return MMAL_PARAM_EXPOSUREMODE_NIGHTPREVIEW;
        case Exposure::BACKLIGHT:
            return MMAL_PARAM_EXPOSUREMODE_BACKLIGHT;
        case Exposure::SPOTLIGHT:
            return MMAL_PARAM_EXPOSUREMODE_SPOTLIGHT;
        case Exposure::SPORTS:
            return MMAL_PARAM_EXPOSUREMODE_SPORTS;
        case Exposure::SNOW:
            return MMAL_PARAM_EXPOSUREMODE_SNOW;
        case Exposure::BEACH:
            return MMAL_PARAM_EXPOSUREMODE_BEACH;
        case Exposure::VERYLONG:
            return MMAL_PARAM_EXPOSUREMODE_VERYLONG;
        case Exposure::FIXEDFPS:
            return MMAL_PARAM_EXPOSUREMODE_FIXEDFPS;
        case Exposure::ANTISHAKE:
            return MMAL_PARAM_EXPOSUREMODE_ANTISHAKE;
        case Exposure::FIREWORKS:
            return MMAL_PARAM_EXPOSUREMODE_FIREWORKS;
        default:
            RRLibs::assert_fail(__func__);
    }
}

MMAL_PARAM_AWBMODE_T TypeConverter::convertAWB(AWB awb) {
    switch (awb) {
        case AWB::OFF:
            return MMAL_PARAM_AWBMODE_OFF;
        case AWB::AUTO:
            return MMAL_PARAM_AWBMODE_AUTO;
        case AWB::SUNLIGHT:
            return MMAL_PARAM_AWBMODE_SUNLIGHT;
        case AWB::CLOUDY:
            return MMAL_PARAM_AWBMODE_CLOUDY;
        case AWB::SHADE:
            return MMAL_PARAM_AWBMODE_SHADE;
        case AWB::TUNGSTEN:
            return MMAL_PARAM_AWBMODE_TUNGSTEN;
        case AWB::FLUORESCENT:
            return MMAL_PARAM_AWBMODE_FLUORESCENT;
        case AWB::INCANDESCENT:
            return MMAL_PARAM_AWBMODE_INCANDESCENT;
        case AWB::FLASH:
            return MMAL_PARAM_AWBMODE_FLASH;
        case AWB::HORIZON:
            return MMAL_PARAM_AWBMODE_HORIZON;
        default:
            RRLibs::assert_fail(__func__);
    }
}

MMAL_PARAM_IMAGEFX_T TypeConverter::convertImageEffect(Effect imageEffect) {
    switch (imageEffect) {
        case Effect::NONE:
            return MMAL_PARAM_IMAGEFX_NONE;
        case Effect::NEGATIVE:
            return MMAL_PARAM_IMAGEFX_NEGATIVE;
        case Effect::SOLARIZE:
            return MMAL_PARAM_IMAGEFX_SOLARIZE;
        case Effect::SKETCH:
            return MMAL_PARAM_IMAGEFX_SKETCH;
        case Effect::DENOISE:
            return MMAL_PARAM_IMAGEFX_DENOISE;
        case Effect::EMBOSS:
            return MMAL_PARAM_IMAGEFX_EMBOSS;
        case Effect::OILPAINT:
            return MMAL_PARAM_IMAGEFX_OILPAINT;
        case Effect::HATCH:
            return MMAL_PARAM_IMAGEFX_HATCH;
        case Effect::GPEN:
            return MMAL_PARAM_IMAGEFX_GPEN;
        case Effect::PASTEL:
            return MMAL_PARAM_IMAGEFX_PASTEL;
        case Effect::WATERCOLOR:
            return MMAL_PARAM_IMAGEFX_WATERCOLOUR;
        case Effect::FILM:
            return MMAL_PARAM_IMAGEFX_FILM;
        case Effect::BLUR:
            return MMAL_PARAM_IMAGEFX_BLUR;
        case Effect::SATURATION:
            return MMAL_PARAM_IMAGEFX_SATURATION;
        case Effect::COLORSWAP:
            return MMAL_PARAM_IMAGEFX_COLOURSWAP;
        case Effect::WASHEDOUT:
            return MMAL_PARAM_IMAGEFX_WASHEDOUT;
        case Effect::POSTERISE:
            return MMAL_PARAM_IMAGEFX_POSTERISE;
        case Effect::COLORPOINT:
            return MMAL_PARAM_IMAGEFX_COLOURPOINT;
        case Effect::COLORBALANCE:
            return MMAL_PARAM_IMAGEFX_COLOURBALANCE;
        case Effect::CARTOON:
            return MMAL_PARAM_IMAGEFX_CARTOON;
        default:
            RRLibs::assert_fail(__func__);
    }
}


}