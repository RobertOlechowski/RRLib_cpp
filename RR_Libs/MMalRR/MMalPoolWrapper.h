#pragma once

#include "MMALWrapper.h"
#include "MMALWrapperBase.h"



namespace RRLibs::MMalRR {

class MMalPoolWrapper : public MMALWrapperBase {
public:
    explicit MMalPoolWrapper(MMAL_PORT_T* port);

    void queue_to_port();

    ~MMalPoolWrapper() override;

private:
    MMAL_POOL_T* m_video_pool;
    MMAL_PORT_T* m_pool_port;
};

}



