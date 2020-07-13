#pragma once

#include "InfoEnums.h"
#include <string>

namespace RRLibs::SysInfo {

const std::string& to_text(CompilerEnum arg) noexcept;

const std::string& to_text(CppVersionsEnum arg) noexcept;

const std::string& to_text(OsEnum arg) noexcept;

const std::string& to_text(CompilationMode arg) noexcept;

}