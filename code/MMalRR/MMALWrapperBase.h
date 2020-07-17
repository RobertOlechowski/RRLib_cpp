#pragma once

#include "mmal_include.h"
#include <MathRR/Vec2.h>


namespace RRLibs::MMalRR {

class MMALWrapperBase {
public:
    MMALWrapperBase();

    virtual ~MMALWrapperBase();

    virtual void destroy_component();

    virtual void enable();

    virtual void enable_out_port(MMAL_PORT_BH_CB_T cb, MMAL_PORT_USERDATA_T* cb_data);

    MMAL_PORT_T* get_input_port() const;

    MMAL_PORT_T* get_output_port() const;

    MMAL_PORT_T* get_control_port() const;

    MMAL_COMPONENT_T* get_component() const;

protected:

    MMAL_COMPONENT_T* m_component = nullptr;
    MMAL_PORT_T* m_control_port = nullptr;
    MMAL_PORT_T* m_in_port = nullptr;
    MMAL_PORT_T* m_out_port = nullptr;
};

}

