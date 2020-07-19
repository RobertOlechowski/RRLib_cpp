#include "MMalPoolWrapper.h"

namespace RRLibs::MMalRR {

MMalPoolWrapper::MMalPoolWrapper(MMAL_PORT_T* port) {
    port->buffer_size = port->buffer_size_recommended;
    port->buffer_num = port->buffer_num_recommended;

    m_video_pool = MMALWrapper::port_pool_create(port);
    m_pool_port = port;
    for (int q = 0; q < m_video_pool->headers_num; q++)
        MMALWrapper::queue_to_port(m_video_pool->queue, port);
}

MMalPoolWrapper::~MMalPoolWrapper() {
    if (m_video_pool)
        mmal_port_pool_destroy(m_pool_port, m_video_pool);
}

void MMalPoolWrapper::queue_to_port() {
    MMALWrapper::queue_to_port(m_video_pool->queue, m_pool_port);
}

}