#pragma once

#include <Common/Types.h>

namespace RRLibs {
[[noreturn]] void assert_fail(const char* msg = nullptr) noexcept;

void assert_test(bool condition, const char* msg = nullptr) noexcept;

void assert_error_code(uint error_code, const char* msg = nullptr) noexcept;

}