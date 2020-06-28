#pragma once
#include "Common/NonCopyableNotMovable.h"
#include "Common/Types.h"
#include "InfoEnums.h"

#include <string>

class SystemInfo : public RRUtils::NonCopyableNotMovable{
public:
    SystemInfo();

    uint get_bit_mode() const noexcept;
    OsEnum get_os_type() const noexcept;
    std::string get_sys_name() const noexcept;
    std::string get_release() const noexcept;
    std::string get_version() const noexcept;
    std::string get_machine() const noexcept;

    std::string get_current_dir() const noexcept;

private:
    std::string _sys_name;
    std::string _release;
    std::string _version;
    std::string _machine;
};



