#pragma once
#include "Common/NonCopyableNotMovable.h"
#include "InfoEnums.h"
#include "BitMode.h"

#include <string>
#include <tuple>

class CompilerInfo : public RRUtils::NonCopyableNotMovable {
public:
    CompilerInfo() = default;
    CompilerEnum get_compiler() const noexcept;
    CppVersionsEnum get_cpp_version() const noexcept;
    std::tuple<int, int, int> get_compiler_version() const noexcept;

private:

};



