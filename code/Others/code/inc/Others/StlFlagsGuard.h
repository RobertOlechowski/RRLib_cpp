#pragma once

#include "Common/NonCopyableNotMovable.h"
#include <iomanip>

namespace RRLibs::Common {

class StlFlagsGuard : public Common::NonCopyableNotMovable {
public:
    StlFlagsGuard();

    ~StlFlagsGuard() override;

private:
    std::ios_base::fmtflags m_f;
};

}


