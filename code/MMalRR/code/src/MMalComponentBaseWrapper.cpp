#include "MMalRR/MMalComponentBaseWrapper.h"
#include "MMalRR/MMALWrapper.h"

namespace RRLibs::MMalRR {


MMalComponentBaseWrapper::MMalComponentBaseWrapper(const char* name) {
    m_component = MMALWrapper::component_create(name);

    if(m_component->input_num > 0)
        m_in_port = m_component->input[0];

    if(m_component->output_num > 0)
        m_out_port = m_component->output[0];

    m_control_port = m_component->control;
}
}