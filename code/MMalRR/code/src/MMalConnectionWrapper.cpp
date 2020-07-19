#include "MMalRR/MMalConnectionWrapper.h"

#include <MMalRR/MMALWrapper.h>

namespace RRLibs::MMalRR {

MMalConnectionWrapper::MMalConnectionWrapper(MMAL_PORT_T* port_1, MMAL_PORT_T* port_2, uint32 flags) {
    m_out_port = port_1;
    m_in_port = port_2;
    m_connection = RRLibs::MMalRR::MMALWrapper::connection_create(m_out_port, m_in_port, flags);
}

MMalConnectionWrapper::MMalConnectionWrapper(MMALWrapperBase& c1, MMALWrapperBase& c2, uint32 flags) {
    m_out_port = c1.get_output_port();
    m_in_port = c2.get_input_port();
    m_connection = RRLibs::MMalRR::MMALWrapper::connection_create(m_out_port, m_in_port, flags);
}


void MMalConnectionWrapper::enable() {
    RRLibs::MMalRR::MMALWrapper::connection_enable(m_connection);
}


}