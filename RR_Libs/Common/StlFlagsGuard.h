#pragma once

#include "NonCopyableNotMovable.h"
#include <iomanip>

namespace RRUtils {

class StlFlagsGuard : public RRUtils::NonCopyableNotMovable {
public:
    StlFlagsGuard();

    ~StlFlagsGuard() override;

private:
    std::ios_base::fmtflags m_f;
};

}


