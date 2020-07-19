#include "MMalRR/MMalInfo.h"

#include <interface/mmal/vc/mmal_vc_api.h>

#include <Assert/Asserts.h>

namespace RRLibs::MMalRR {

MMalInfo::MMalInfo()
        : m_has_error(true) {
    MMAL_STATUS_T status = mmal_vc_init();
    m_has_error = (status != MMAL_SUCCESS);
}

Version::Version MMalInfo::get_MMal_version() const {
    if (m_has_error)
        return Version::Version::ERR();
    uint32_t major = 0;
    uint32_t minor = 0;
    uint32_t minimum = 0;
    MMAL_STATUS_T status = mmal_vc_get_version(&major, &minor, &minimum);
    RRLibs::assert_error_code(status, __FUNCTION__);
    return Version::Version(major, minor);
}

uint MMalInfo::get_MMal_minimum() const {
    if (m_has_error)
        return std::numeric_limits<decltype(get_MMal_minimum())>::max();
    uint32_t major = 0;
    uint32_t minor = 0;
    uint32_t minimum = 0;

    MMAL_STATUS_T status = mmal_vc_get_version(&major, &minor, &minimum);
    RRLibs::assert_error_code(status, __FUNCTION__);
    return minimum;
}

Version::Version MMalInfo::get_vcos_version() const {
    //const char *vcos_get_build_hostname( void );
    //const char *vcos_get_build_version( void );
    //const char *vcos_get_build_time( void );
    //const char *vcos_get_build_date( void );
    //const char *vcos_get_build_variant( void );
    return Version::Version::ERR();
    //return Version::Version(std::string(vcos_get_build_version()));
}
}