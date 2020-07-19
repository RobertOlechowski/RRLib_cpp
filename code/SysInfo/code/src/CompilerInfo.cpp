#include "SysInfo/CompilerInfo.h"
#include "SysInfo/EnumToString.h"

#include <Assert/Asserts.h>
#include <map>

namespace RRLibs::SysInfo {

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


Version::Version CompilerInfo::get_compiler_version() const noexcept {
    switch (get_compiler()) {
        case CompilerEnum::GCC:
            return Version::Version(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__);
    }
    return Version::Version();
}

CompilationMode CompilerInfo::get_compilation_mode() const noexcept {
#ifdef DEBUG
    return CompilationMode::Debug;
#endif

#if defined(RELEASE)
    return CompilationMode::RELEASE;
#endif

#if defined(RELWITHDEBINFO)
    return CompilationMode::RELWITHDEBINFO;
#endif

#if defined(MINSIZEREL)
    return CompilationMode::MINSIZEREL;
#endif
    return CompilationMode::Unknown;
}

}

