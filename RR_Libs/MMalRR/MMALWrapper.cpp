#include "MMALWrapper.h"
#include <Common/Asserts.h>
#include <interface/mmal/vc/mmal_vc_api.h>



namespace RRLibs::MMalRR {

void MMALWrapper::port_parameter_set(MMAL_PORT_T* port, const MMAL_PARAMETER_HEADER_T* param) {
    MMAL_STATUS_T status = mmal_port_parameter_set(port, param);
    RRLibs::assert_error_code(status, __func__);
}

void MMALWrapper::port_enable(MMAL_PORT_T* port, MMAL_PORT_BH_CB_T cb) {
    MMAL_STATUS_T status = mmal_port_enable(port, cb);
    RRLibs::assert_error_code(status, __func__);
}

MMAL_POOL_T* MMALWrapper::pool_create(uint headers, uint32_t payload_size) {
    MMAL_POOL_T* pool = mmal_pool_create(headers, payload_size);
    RRLibs::assert_test(pool, __func__);
    return pool;
}

MMAL_POOL_T* MMALWrapper::port_pool_create(MMAL_PORT_T* port) {
    MMAL_POOL_T* pool = mmal_port_pool_create(port, port->buffer_num, port->buffer_size);
    RRLibs::assert_test(pool, __func__);
    return pool;
}

void MMALWrapper::port_format_commit(MMAL_PORT_T* port) {
    MMAL_STATUS_T status = mmal_port_format_commit(port);
    RRLibs::assert_error_code(status, __func__);
}

MMAL_COMPONENT_T* MMALWrapper::component_create(const char* name) {
    MMAL_COMPONENT_T* component = nullptr;
    MMAL_STATUS_T status = mmal_component_create(name, &component);
    RRLibs::assert_error_code(status, __func__);
    RRLibs::assert_test(component != nullptr, __func__);
    return component;
}

void MMALWrapper::component_enable(MMAL_COMPONENT_T* component) {
    MMAL_STATUS_T status = mmal_component_enable(component);
    RRLibs::assert_error_code(status, __func__);
}

MMAL_BUFFER_HEADER_T* MMALWrapper::queue_get(MMAL_QUEUE_T* queue) {
    MMAL_BUFFER_HEADER_T* new_buffer = mmal_queue_get(queue);
    RRLibs::assert_test(new_buffer, __func__);
    return new_buffer;
}

void MMALWrapper::port_send_buffer(MMAL_PORT_T* port, MMAL_BUFFER_HEADER_T* buffer) {
    MMAL_STATUS_T status = mmal_port_send_buffer(port, buffer);
    RRLibs::assert_error_code(status, __func__);
}

void MMALWrapper::queue_to_port(MMAL_QUEUE_T* queue, MMAL_PORT_T* port) {
    MMAL_BUFFER_HEADER_T* new_buffer = queue_get(queue);
    port_send_buffer(port, new_buffer);
}

void MMALWrapper::port_parameter_set_uint32(MMAL_PORT_T* port, int id, uint32 value) {
    MMAL_STATUS_T status = mmal_port_parameter_set_uint32(port, id, value);
    RRLibs::assert_error_code(status, __func__);
}

void MMALWrapper::port_parameter_set_rational(MMAL_PORT_T* port, int id, int num, uint den) {
    RRLibs::assert_test(den > 0, __func__);
    auto value = (MMAL_RATIONAL_T) {num, (int32_t) den};
    MMAL_STATUS_T status = mmal_port_parameter_set_rational(port, id, value);
    RRLibs::assert_error_code(status, __func__);
}

void MMALWrapper::port_parameter_set_bool(MMAL_PORT_T* port, int id, bool value) {
    MMAL_STATUS_T status = mmal_port_parameter_set_boolean(port, id, value);
    RRLibs::assert_error_code(status, __func__);
}

MMAL_CONNECTION_T* MMALWrapper::connection_create(MMAL_PORT_T* port_1, MMAL_PORT_T* port_2, uint32 flags) {
    MMAL_CONNECTION_T* result = nullptr;

    MMAL_STATUS_T status = mmal_connection_create(&result, port_1, port_2, flags);
    RRLibs::assert_error_code(status, __func__);
    RRLibs::assert_test(result != nullptr, "ptr is empty");


    return result;
}

void MMALWrapper::connection_enable(MMAL_CONNECTION_T* handle) {
    MMAL_STATUS_T status = mmal_connection_enable(handle);
    RRLibs::assert_error_code(status, __func__);
}

void MMALWrapper::buffer_header_mem_lock(MMAL_BUFFER_HEADER_T* header) {
    MMAL_STATUS_T status = mmal_buffer_header_mem_lock(header);
    RRLibs::assert_error_code(status, __func__);
}

void MMALWrapper::buffer_header_mem_unlock(MMAL_BUFFER_HEADER_T* header) {
    mmal_buffer_header_mem_unlock(header);
}

void MMALWrapper::vc_init() {
    MMAL_STATUS_T status = mmal_vc_init();
    RRLibs::assert_error_code(status, __func__);

}

void MMALWrapper::set_crop(MMAL_PORT_T* port, MMAL_RECT_T& rect) {
    MMAL_PARAMETER_CROP_T crop = {{MMAL_PARAMETER_CROP, sizeof(MMAL_PARAMETER_CROP_T)}};
    crop.rect = rect;
    MMALWrapper::port_parameter_set(port, &crop.hdr);
}

void MMALWrapper::set_input_crop(MMAL_PORT_T* port, MMAL_RECT_T& rect) {
    MMAL_PARAMETER_INPUT_CROP_T crop = {{MMAL_PARAMETER_INPUT_CROP, sizeof(MMAL_PARAMETER_INPUT_CROP_T)}};
    crop.rect = rect;
    MMALWrapper::port_parameter_set(port, &crop.hdr);
}

void MMALWrapper::set_zoom(MMAL_PORT_T* port, float scale_x, float scale_y) {
    MMAL_PARAMETER_SCALEFACTOR_T crop = {{MMAL_PARAMETER_ZOOM, sizeof(MMAL_PARAMETER_SCALEFACTOR_T)}};
    crop.scale_x = 65536 * scale_x;
    crop.scale_y = 65536 * scale_y;
    MMALWrapper::port_parameter_set(port, &crop.hdr);
}

void MMALWrapper::set_resize(MMAL_PORT_T* port, MMAL_PARAMETER_RESIZE_T& param) {
    param.hdr = {MMAL_PARAMETER_RESIZE_PARAMS, sizeof(MMAL_PARAMETER_RESIZE_T)};
    MMALWrapper::port_parameter_set(port, &param.hdr);
}

void MMALWrapper::set_FOV(MMAL_PORT_T* port, float h, float w) {
    MMAL_PARAMETER_FIELD_OF_VIEW_T param = {{MMAL_PARAMETER_FIELD_OF_VIEW, sizeof(MMAL_PARAMETER_FIELD_OF_VIEW_T)}};
    param.fov_h.num = h * 1000;
    param.fov_h.den = 1000;
    param.fov_v.num = w * 1000;
    param.fov_v.den = 1000;
    MMALWrapper::port_parameter_set(port, &param.hdr);
}


}
