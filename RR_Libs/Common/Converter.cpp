#include <stdexcept>
#include "Converter.h"
#include "Asserts.h"

namespace RRLibs::Common {

int Converter::parse_int(const std::string_view& arg) {
    size_t pos2 = 0;
    const int val = std::stoi(arg.data(), &pos2);
    RRLibs::assert_test(pos2 == arg.size(), __func__);
    return val;
}

}
