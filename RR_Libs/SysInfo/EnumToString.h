#pragma once
#include "InfoEnums.h"
#include <string>

const std::string& compiler_to_text(CompilerEnum arg) noexcept;
const std::string& cpp_version_to_text(CppVersionsEnum arg) noexcept;
const std::string& os_to_text(OsEnum arg) noexcept;

const std::string version_to_text(std::tuple<int, int, int> arg) noexcept;