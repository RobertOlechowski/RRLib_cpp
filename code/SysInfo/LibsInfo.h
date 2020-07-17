#pragma once

#include "Common/NonCopyableNotMovable.h"
#include "Common/Types.h"
#include "InfoEnums.h"

#include <string>
#include <Version/Version.h>

namespace RRLibs::SysInfo {

class LibsInfo : public Common::NonCopyableNotMovable {
public:
    LibsInfo();

    Version::Version get_openCV() const noexcept;

    Version::Version get_boost_version() const noexcept;

    Version::Version get_libc_version() const noexcept;

    Version::Version get_mmal_version() const noexcept;

    Version::Version get_vcos_version() const noexcept;

    uint get_mmal_minimum() const noexcept;

    uint is_opencv2() const noexcept;

private:

};

}

