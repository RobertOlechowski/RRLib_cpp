#pragma once

#include <Version/Version.h>

namespace RRLibs::MMalRR {

class MMalInfo {
public:
    MMalInfo();

    Version::Version get_MMal_version() const;

    Version::Version get_vcos_version() const;

    uint get_MMal_minimum() const;

public:
    bool m_has_error;
};

}

