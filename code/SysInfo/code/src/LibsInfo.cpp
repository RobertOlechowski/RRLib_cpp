#include "SysInfo/LibsInfo.h"

#include <Common/Macros.h>
#include <gnu/libc-version.h>

#if __has_include(<MMalRR/MMalInfo.h>)
#include <MMalRR/MMalInfo.h>
#define have_MMalInfo 1
#endif


namespace RRLibs::SysInfo {

LibsInfo::LibsInfo() {}

Version::Version LibsInfo::get_openCV() const noexcept {
#ifndef OPENCV_VERSION
    return Version::Version();
#endif
    return Version::Version(STRINGIFY(OPENCV_VERSION));
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

Version::Version LibsInfo::get_libcpp_version() const noexcept {
#ifdef __GLIBCXX__
    return Version::Version(_GLIBCXX_RELEASE,0,0, __GLIBCXX__);
#endif
    return Version::Version::ERR();

}

#ifdef have_MMalInfo
static RRLibs::MMalRR::MMalInfo mall_info;
#endif

Version::Version LibsInfo::get_mmal_version() const noexcept {
#ifdef have_MMalInfo
    return mall_info.get_MMal_version();
#endif
    return Version::Version();
}

uint LibsInfo::get_mmal_minimum() const noexcept {
#ifdef have_MMalInfo
    return mall_info.get_MMal_minimum();
#endif
    return 0;
}

Version::Version LibsInfo::get_vcos_version() const noexcept {
#ifdef have_MMalInfo
    return mall_info.get_vcos_version();
#endif
    return Version::Version();
}

}