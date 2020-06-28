#include "StlFlagsGuard.h"
#include <iostream>

namespace RRUtils {

StlFlagsGuard::StlFlagsGuard() {
    m_f = std::cout.flags();
}

StlFlagsGuard::~StlFlagsGuard() {
    std::cout.flags(m_f);
}
}
