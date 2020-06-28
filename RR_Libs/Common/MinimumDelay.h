#pragma once

#include "NonCopyableNotMovable.h"
#include "Types.h"

#include <chrono>

namespace RRUtils {

class MinimumDelay : public RRUtils::NonCopyableNotMovable {
public:
    MinimumDelay();

    void reset();

    void wait_for_minimum(std::chrono::milliseconds delay_ms) const;

private:
    std::chrono::system_clock::time_point m_start_time;
};

}
