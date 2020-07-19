#pragma once

#include "MMALWrapperBase.h"
#include <interface/mmal/util/mmal_connection.h>

namespace RRLibs::MMalRR {

class MMalConnectionWrapper {
public:
    MMalConnectionWrapper(MMAL_PORT_T* port_1, MMAL_PORT_T* port_2, uint32 flags);

    MMalConnectionWrapper(MMALWrapperBase& c1, MMALWrapperBase& c2, uint32 flags);

    void enable();

private:
    MMAL_PORT_T* m_in_port = nullptr;
    MMAL_PORT_T* m_out_port = nullptr;
    MMAL_CONNECTION_T* m_connection = nullptr;
};

}



