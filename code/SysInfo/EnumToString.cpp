#include "EnumToString.h"
#include <Common/Asserts.h>
#include <map>
#include <sstream>

namespace RRLibs::SysInfo {

static const std::map<CompilerEnum, std::string> s_compiler_text_map = {
        {CompilerEnum::Unknown,       std::string("Unknown")},
        {CompilerEnum::Clang,         std::string("Clang")},
        {CompilerEnum::Visual_Studio, std::string("Visual Studio")},
        {CompilerEnum::GCC,           std::string("GCC")},
};

static const std::map<CppVersionsEnum, std::string> s_cpp_version_text_map = {
        {CppVersionsEnum::Unknown, std::string("Unknown")},
        {CppVersionsEnum::Cpp98,   std::string("98")},
        {CppVersionsEnum::Cpp03,   std::string("03")},
        {CppVersionsEnum::Cpp11,   std::string("11")},
        {CppVersionsEnum::Cpp14,   std::string("14")},
        {CppVersionsEnum::Cpp17,   std::string("17")},
        {CppVersionsEnum::cpp20,
                                   std::string("CPP 20")},
};

const std::string& to_text(CompilerEnum arg) noexcept {
    return s_compiler_text_map.at(arg);
}

const std::string& to_text(CppVersionsEnum arg) noexcept {
    return s_cpp_version_text_map.at(arg);
}


static const std::map<OsEnum, std::string> s_os_text_map = {
        {OsEnum::Unknown, std::string("Unknown")},
        {OsEnum::Windows, std::string("Windows")},
        {OsEnum::Linux,   std::string("Linux")},
};

const std::string& to_text(OsEnum arg) noexcept {
    return s_os_text_map.at(arg);
}

static const std::map<CompilationMode, std::string> s_compilation_mode_text_map = {
        {CompilationMode::Unknown,          std::string("Unknown")},
        {CompilationMode::Debug,            std::string("Debug")},
        {CompilationMode::Release,          std::string("Release")},
        {CompilationMode::MinSizeRel,       std::string("MinSizeRel")},
        {CompilationMode::RelWithDebugInfo, std::string("RelWithDebugInfo")},
};

const std::string& to_text(CompilationMode arg) noexcept {
    return s_compilation_mode_text_map.at(arg);
}

}