#pragma once

#include "MMALWrapperBase.h"

namespace RRLibs::MMalRR {

class MMalComponentBaseWrapper : public MMALWrapperBase {
public:
    explicit MMalComponentBaseWrapper(const char* name);
    ~MMalComponentBaseWrapper() override = default;
};

}

