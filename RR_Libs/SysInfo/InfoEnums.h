#pragma once

enum class CppVersionsEnum{
    Unknown = -1,
    Cpp98 = 0,
    Cpp03,
    Cpp11,
    Cpp14,
    Cpp17,
    cpp20,
};

enum class CompilerEnum{
    Unknown = -1,
    Clang = 1,
    Visual_Studio,
    GCC,
};

enum class OsEnum{
    Unknown = -1,
    Windows = 1,
    Linux,
};