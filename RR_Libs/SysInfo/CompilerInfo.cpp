#include "CompilerInfo.h"
#include "EnumToString.h"

#include <map>

CompilerEnum CompilerInfo::get_compiler() const noexcept {
#if defined(__clang__)
    return CompilerEnum::Clang;
#endif

#if defined(__GNUC__)
    return CompilerEnum::GCC;
#endif

#if defined(_MSC_VER)
    return CompilerEnum::Visual_Studio;
#endif
return CompilerEnum::Unknown;
}

CppVersionsEnum CompilerInfo::get_cpp_version() const noexcept {
#ifndef __cplusplus
    return CppVersionsEnum::Unknown;
#endif

#if __cplusplus <= 199711L
    return CppVersionsEnum::Cpp98;
#elif __cplusplus <= 201103L
    return CppVersionsEnum::Cpp11;
#elif __cplusplus <= 201402L
    return CppVersionsEnum::Cpp14;
#elif __cplusplus <= 201703L
    return CppVersionsEnum::Cpp17;
#elif __cplusplus <= 202002L
    return CppVersionsEnum::Cpp20;
#else
    return CppVersionsEnum::Unknown;
#endif

}


std::tuple<int, int, int> CompilerInfo::get_compiler_version() const noexcept {
    switch (get_compiler()) {
        case CompilerEnum::GCC:
            return std::make_tuple(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    }
    return std::make_tuple(0,0,0);
}



