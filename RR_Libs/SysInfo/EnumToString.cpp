#include "EnumToString.h"
#include <map>
#include <sstream>

static const std::map<CompilerEnum, std::string> s_compiler_text_map = {
        {CompilerEnum::Unknown, std::string("Unknown")},
        {CompilerEnum::Clang, std::string("Clang")},
        {CompilerEnum::Visual_Studio, std::string("Visual Studio")},
        {CompilerEnum::GCC, std::string("GCC")},
};

static const std::map<CppVersionsEnum, std::string> s_cpp_version_text_map = {
        {CppVersionsEnum::Unknown, std::string("Unknown")},
        {CppVersionsEnum::Cpp98, std::string("98")},
        {CppVersionsEnum::Cpp03, std::string("03")},
        {CppVersionsEnum::Cpp11, std::string("11")},
        {CppVersionsEnum::Cpp14, std::string("14")},
        {CppVersionsEnum::Cpp17, std::string("17")},
        {CppVersionsEnum::cpp20,
                                   std::string("CPP 20")},
};

const std::string& compiler_to_text(CompilerEnum arg) noexcept {
    return s_compiler_text_map.at(arg);
}

const std::string& cpp_version_to_text(CppVersionsEnum arg) noexcept {
    return s_cpp_version_text_map.at(arg);
}

const std::string version_to_text(std::tuple<int, int, int> arg) noexcept {
    std::ostringstream stringStream;
    stringStream << "[";
    stringStream << std::get<0>(arg) << ".";
    stringStream << std::get<1>(arg) << ".";
    stringStream << std::get<2>(arg);
    stringStream << "]";
    return stringStream.str();
}

static const std::map<OsEnum, std::string> s_os_text_map = {
        {OsEnum::Unknown, std::string("Unknown")},
        {OsEnum::Windows, std::string("Windows")},
        {OsEnum::Linux, std::string("Linux")},
};

const std::string& os_to_text(OsEnum arg) noexcept {
    return s_os_text_map.at(arg);
}