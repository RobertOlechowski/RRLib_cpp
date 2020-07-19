#include <iostream>
#include <Version/Version.h>

int main() {
    using namespace RRLibs::Version;

    {
        auto ver = Version(1, 2, 3);
        std::cout << ver.to_string() << std::endl;
        std::cout << ver << std::endl;
    }

    {
        auto ver = Version("1.2.3");
        std::cout << ver.to_string() << std::endl;
        std::cout << ver << std::endl;
    }

    return 0;
}