#pragma once

#include <Common/Types.h>
#include "mmal_include.h"


namespace RRLibs::MMalRR {

class MMALWrapperBase;

class MMALWrapper {
public:
    MMALWrapper() = delete;

    static MMAL_COMPONENT_T* component_create(const char* name);

    static void component_enable(MMAL_COMPONENT_T* component);

    static void port_parameter_set(MMAL_PORT_T* port, const MMAL_PARAMETER_HEADER_T* param);

    static void port_parameter_set_uint32(MMAL_PORT_T* port, int id, uint32 value);

    static void port_parameter_set_rational(MMAL_PORT_T* port, int id, int num, uint den);

    static void port_parameter_set_bool(MMAL_PORT_T* port, int id, bool value);

    static void port_enable(MMAL_PORT_T* port, MMAL_PORT_BH_CB_T cb);

    static void port_format_commit(MMAL_PORT_T* port);

    static void buffer_header_mem_lock(MMAL_BUFFER_HEADER_T* header);

    static void buffer_header_mem_unlock(MMAL_BUFFER_HEADER_T* header);

    static MMAL_POOL_T* port_pool_create(MMAL_PORT_T* port);

    static MMAL_POOL_T* pool_create(uint headers, uint32 payload_size);

    static MMAL_BUFFER_HEADER_T* queue_get(MMAL_QUEUE_T* queue);

    static void port_send_buffer(MMAL_PORT_T* port, MMAL_BUFFER_HEADER_T* buffer);

    static void queue_to_port(MMAL_QUEUE_T* queue, MMAL_PORT_T* port);


    static MMAL_CONNECTION_T* connection_create(MMAL_PORT_T* port_1, MMAL_PORT_T* port_2, uint32 flags);

    static void connection_enable(MMAL_CONNECTION_T* handle);

    static void vc_init();

    static void set_crop(MMAL_PORT_T* port, MMAL_RECT_T& rect);

    static void set_input_crop(MMAL_PORT_T* port, MMAL_RECT_T& rect);

    static void set_zoom(MMAL_PORT_T* port, float scale_x, float scale_y);

    static void set_resize(MMAL_PORT_T* port, MMAL_PARAMETER_RESIZE_T& resize);

    static void set_FOV(MMAL_PORT_T* port, float h, float w);

};

}

