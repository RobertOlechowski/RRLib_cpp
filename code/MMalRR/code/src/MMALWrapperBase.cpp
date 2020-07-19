#include "MMalRR/MMALWrapperBase.h"
#include "MMalRR/MMALWrapper.h"

#include <Assert/Asserts.h>
#include <initializer_list>

namespace RRLibs::MMalRR {

using MMALWrapper = RRLibs::MMalRR::MMALWrapper;

MMAL_PORT_T* MMALWrapperBase::get_input_port() const {
    return m_in_port;
}

MMAL_PORT_T* MMALWrapperBase::get_output_port() const {
    return m_out_port;
}

MMAL_COMPONENT_T* MMALWrapperBase::get_component() const {
    return m_component;
}

MMALWrapperBase::MMALWrapperBase() {}

MMALWrapperBase::~MMALWrapperBase() {
    destroy_component();
}

void MMALWrapperBase::destroy_component() {
    auto ports = {m_in_port, m_out_port};
    for (MMAL_PORT_T* item : ports)
        if (item != nullptr && item->is_enabled)
            mmal_port_disable(item);

    if (m_component && m_component->is_enabled)
        mmal_component_disable(m_component);

    if (m_component)
        mmal_component_destroy(m_component);

    m_component = nullptr;
}

void MMALWrapperBase::enable() {
    MMALWrapper::component_enable(m_component);
}

void MMALWrapperBase::enable_out_port(MMAL_PORT_BH_CB_T cb, MMAL_PORT_USERDATA_T* cb_data) {
    m_out_port->userdata = cb_data;
    m_component->control->userdata = cb_data;
    MMALWrapper::port_enable(m_out_port, cb);
}

MMAL_PORT_T* MMALWrapperBase::get_control_port() const {
    RRLibs::assert_test(m_control_port != nullptr, "get_control_port");
    return m_control_port;
}


}