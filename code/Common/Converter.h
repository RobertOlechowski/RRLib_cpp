#pragma once

#include <string>

namespace RRLibs::Common {

class Converter {
public:
    Converter() = delete;

    static int parse_int(const std::string_view& arg);
};

}

