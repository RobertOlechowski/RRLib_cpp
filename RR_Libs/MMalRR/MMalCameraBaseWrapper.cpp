#include "MMalCameraBaseWrapper.h"
#include "TypeConverter.h"

namespace RRLibs::MMalRR {

using MMALWrapper = RRLibs::MMalRR::MMALWrapper;

static constexpr int MMAL_CAMERA_VIDEO_PORT = 1;

MMalCameraBaseWrapper::MMalCameraBaseWrapper() : MMalComponentBaseWrapper(MMAL_COMPONENT_DEFAULT_CAMERA) {
    m_out_port = m_component->output[MMAL_CAMERA_VIDEO_PORT];
}

void MMalCameraBaseWrapper::set_capture(bool value) {
    MMALWrapper::port_parameter_set_bool(m_out_port, MMAL_PARAMETER_CAPTURE, value);
}

void MMalCameraBaseWrapper::set_ISO(int value) const {
    MMALWrapper::port_parameter_set_uint32(m_component->control, MMAL_PARAMETER_ISO, value);
}

void MMalCameraBaseWrapper::set_sharpness(int value) const {
    MMALWrapper::port_parameter_set_rational(m_component->control, MMAL_PARAMETER_SHARPNESS, value, 100);
}

void MMalCameraBaseWrapper::set_shutter_speed(int value) const {
    MMALWrapper::port_parameter_set_uint32(m_component->control, MMAL_PARAMETER_SHUTTER_SPEED, value);
}

void MMalCameraBaseWrapper::set_video_stabilization(bool value) const {
    MMALWrapper::port_parameter_set_bool(m_component->control, MMAL_PARAMETER_VIDEO_STABILISATION, value);
}

void MMalCameraBaseWrapper::set_BCS(int brightness, int contrast, int saturation) const {
    auto control = m_component->control;
    MMALWrapper::port_parameter_set_rational(control, MMAL_PARAMETER_BRIGHTNESS, brightness, 100);
    MMALWrapper::port_parameter_set_rational(control, MMAL_PARAMETER_CONTRAST, contrast, 100);
    MMALWrapper::port_parameter_set_rational(control, MMAL_PARAMETER_SATURATION, saturation, 100);
}

void MMalCameraBaseWrapper::set_flips(bool flip_h, bool flip_v) const {
    auto param = MMAL_PARAM_MIRROR_NONE;

    if (flip_v)
        param = MMAL_PARAM_MIRROR_VERTICAL;

    if (flip_h)
        param = MMAL_PARAM_MIRROR_HORIZONTAL;

    if (flip_h && flip_v)
        param = MMAL_PARAM_MIRROR_BOTH;

    MMAL_PARAMETER_MIRROR_T mirror = {{MMAL_PARAMETER_MIRROR, sizeof(MMAL_PARAMETER_MIRROR_T)}, param};
    for (int i = 0; i < m_component->output_num; ++i)
        MMALWrapper::port_parameter_set(m_component->output[i], &mirror.hdr);
}

void MMalCameraBaseWrapper::set_AWB(AWB awb_mode_arg, float awb_r, float awb_g) const {
    auto awb_mode = TypeConverter::convertAWB(awb_mode_arg);
    MMAL_PARAMETER_AWBMODE_T param_mode = {{MMAL_PARAMETER_AWB_MODE, sizeof(param_mode)}, awb_mode};
    MMALWrapper::port_parameter_set(m_component->control, &param_mode.hdr);

    MMAL_PARAMETER_AWB_GAINS_T param_rb = {{MMAL_PARAMETER_CUSTOM_AWB_GAINS, sizeof(param_rb)},
                                           {0,                               0},
                                           {0,                               0}};
    param_rb.r_gain.num = (uint) (awb_r * 65536);
    param_rb.b_gain.num = (uint) (awb_g * 65536);
    param_rb.r_gain.den = param_rb.b_gain.den = 65536;
    MMALWrapper::port_parameter_set(m_component->control, &param_rb.hdr);
}

void MMalCameraBaseWrapper::set_image_effect(Effect image_effect) const {
    auto value = TypeConverter::convertImageEffect(image_effect); //m_state.rpc_imageEffect
    MMAL_PARAMETER_IMAGEFX_T imgFX = {{MMAL_PARAMETER_IMAGE_EFFECT, sizeof(imgFX)}, value};
    MMALWrapper::port_parameter_set(m_component->control, &imgFX.hdr);
}

void MMalCameraBaseWrapper::set_metering(Metering value_arg) const {
    auto value = TypeConverter::convertMetering(value_arg);  //m_state.rpc_exposureMeterMode
    MMAL_PARAMETER_EXPOSUREMETERINGMODE_T meter_mode = {{MMAL_PARAMETER_EXP_METERING_MODE, sizeof(meter_mode)}, value};
    MMALWrapper::port_parameter_set(m_component->control, &meter_mode.hdr);
}

void MMalCameraBaseWrapper::set_rotation(Rotation rotation_arg) const {
    int rotation = int(rotation_arg) * 90;
    mmal_port_parameter_set_int32(m_component->output[0], MMAL_PARAMETER_ROTATION, rotation);
    mmal_port_parameter_set_int32(m_component->output[1], MMAL_PARAMETER_ROTATION, rotation);
    mmal_port_parameter_set_int32(m_component->output[2], MMAL_PARAMETER_ROTATION, rotation);
}

void MMalCameraBaseWrapper::set_exposure(Exposure value, uint exposure_compensation) const {
    auto control = m_component->control;
    auto conv_value = TypeConverter::convertExposure(value); //m_state.rpc_exposureMode
    MMAL_PARAMETER_EXPOSUREMODE_T exp_mode = {{MMAL_PARAMETER_EXPOSURE_MODE, sizeof(exp_mode)}, conv_value};
    MMALWrapper::port_parameter_set(control, &exp_mode.hdr);
    MMALWrapper::port_parameter_set_uint32(control, MMAL_PARAMETER_EXPOSURE_COMP,
                                           exposure_compensation); //m_state.exposureCompensation
}

}