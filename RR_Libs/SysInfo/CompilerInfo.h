#pragma once

#include "Common/NonCopyableNotMovable.h"
#include "InfoEnums.h"
#include "BitMode.h"

#include "Version/Version.h"
#include <string>
#include <tuple>

namespace RRLibs::SysInfo {

class CompilerInfo : public Common::NonCopyableNotMovable {
public:
    CompilerInfo() = default;

    CompilerEnum get_compiler() const noexcept;

    CppVersionsEnum get_cpp_version() const noexcept;

    Version::Version get_compiler_version() const noexcept;

    CompilationMode get_compilation_mode() const noexcept;

private:

};

}


