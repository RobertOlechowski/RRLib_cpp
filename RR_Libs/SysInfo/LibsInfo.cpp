#include "LibsInfo.h"
#include "Common/macros.h"

LibsInfo::LibsInfo() {}

std::string LibsInfo::get_openCV() const noexcept {
#ifndef OPENCV_VERSION
    return "[???]";
#endif
    return STRINGIFY(OPENCV_VERSION);
}


uint LibsInfo::is_opencv2() const noexcept {
    #ifdef WITH_OPENCV2
    return uint(WITH_OPENCV2);
    #endif
    return 0;
}

