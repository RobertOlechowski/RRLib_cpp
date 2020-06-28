#include "SystemInfo.h"

#ifdef linux
    #include <sys/utsname.h>
    #include <unistd.h>
#endif

#ifdef WINDOWS
    #include <direct.h>
#endif


static const std::string s_unknown_string = "[????]";

SystemInfo::SystemInfo() {
    _sys_name = s_unknown_string;
    _release = s_unknown_string;
    _version = s_unknown_string;
    _machine = s_unknown_string;

    if (get_os_type() != OsEnum::Linux)
        return;
#ifdef linux
    struct utsname buffer = {0};

    errno = 0;
    if (uname(&buffer) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }
    _sys_name = buffer.sysname;
    _release = buffer.release;
    _version = buffer.version;
    _machine = buffer.machine;
#endif
}

uint SystemInfo::get_bit_mode() const noexcept {
    return 8 * sizeof(int);
}

OsEnum SystemInfo::get_os_type() const noexcept {
#ifdef _WIN32
    return OsEnum::Windows;
#endif
#ifdef linux
    return OsEnum::Linux;
#endif
    return OsEnum::Unknown;
}

std::string SystemInfo::get_sys_name() const noexcept {
    return _sys_name;
}

std::string SystemInfo::get_release() const noexcept {
    return _release;
}

std::string SystemInfo::get_version() const noexcept {
    return _version;
}

std::string SystemInfo::get_machine() const noexcept {
    return _machine;
}

std::string SystemInfo::get_current_dir() const noexcept {
    char buff[FILENAME_MAX];
    getcwd( buff, FILENAME_MAX );
    return buff;
}