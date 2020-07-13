#pragma once

#include <MMalRR/MMALWrapperBase.h>
#include <MMalRR/MMALWrapper.h>
#include <MMalRR/Metering.h>
#include <MMalRR/Effect.h>
#include <MMalRR/AWB.h>
#include "Rotation.h"
#include "Exposure.h"
#include "MMalComponentBaseWrapper.h"


namespace RRLibs::MMalRR {

class MMalCameraBaseWrapper : public MMalComponentBaseWrapper {
public:
    explicit MMalCameraBaseWrapper();

    ~MMalCameraBaseWrapper() override = default;

    void set_capture(bool value);

    void set_ISO(int value) const;

    void set_sharpness(int value) const;

    void set_shutter_speed(int value) const;

    void set_video_stabilization(bool value) const;

    void set_BCS(int brightness, int contrast, int saturation) const;

    void set_flips(bool flip_h, bool flip_v) const;

    void set_AWB(AWB awb_mode_arg, float awb_r, float awb_g) const;

    void set_image_effect(Effect image_effect) const;

    void set_metering(Metering value_arg) const;

    void set_rotation(Rotation rotation_arg) const;

    void set_exposure(Exposure value, uint exposure_compensation) const;
};

}



