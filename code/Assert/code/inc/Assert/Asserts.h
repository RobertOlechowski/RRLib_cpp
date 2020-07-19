#pragma once

#include <Common/Types.h>
#include <experimental/source_location>


namespace RRLibs {
using SourceLocation = std::experimental::source_location;

[[noreturn]] void assert_fail(const char* msg = nullptr, const SourceLocation& location = SourceLocation::current()) noexcept;

void assert_test(bool condition, const char* msg = nullptr, const SourceLocation& location = SourceLocation::current()) noexcept;

void assert_error_code(uint error_code, const char* msg = nullptr, const SourceLocation& location = SourceLocation::current()) noexcept;

}