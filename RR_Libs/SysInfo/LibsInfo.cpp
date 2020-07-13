#include "LibsInfo.h"
#include "Common/macros.h"

#include <gnu/libc-version.h>
#include <MMalRR/MMalInfo.h>

namespace RRLibs::SysInfo {

LibsInfo::LibsInfo() {}

Version::Version LibsInfo::get_openCV() const noexcept {
#ifndef OPENCV_VERSION
    return Version::Version();
#endif
    return Version::Version("1.2");
}


uint LibsInfo::is_opencv2() const noexcept {
#ifdef WITH_OPENCV2
    return uint(WITH_OPENCV2);
#endif
    return 0;
}

Version::Version LibsInfo::get_boost_version() const noexcept {
#ifndef Boost_VERSION_STRING
    return Version::Version();
#endif
    return Version::Version(STRINGIFY(Boost_VERSION_STRING));
}

Version::Version LibsInfo::get_libc_version() const noexcept {
    return Version::Version(gnu_get_libc_version(), gnu_get_libc_release());
}

static RRLibs::MMalRR::MMalInfo mall_info;

Version::Version LibsInfo::get_mmal_version() const noexcept {
    return mall_info.get_MMal_version();
}

uint LibsInfo::get_mmal_minimum() const noexcept {
    return mall_info.get_MMal_minimum();
}

Version::Version LibsInfo::get_vcos_version() const noexcept {
    return mall_info.get_vcos_version();
}

}