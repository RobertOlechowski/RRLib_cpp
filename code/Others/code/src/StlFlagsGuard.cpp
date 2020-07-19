#include "Others/StlFlagsGuard.h"
#include <iostream>

namespace RRLibs::Common {

StlFlagsGuard::StlFlagsGuard() {
    m_f = std::cout.flags();
}

StlFlagsGuard::~StlFlagsGuard() {
    std::cout.flags(m_f);
}
}
