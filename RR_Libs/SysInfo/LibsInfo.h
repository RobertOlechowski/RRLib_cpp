#pragma once

#include "Common/NonCopyableNotMovable.h"
#include "Common/Types.h"
#include "InfoEnums.h"

#include <string>

class LibsInfo : public RRUtils::NonCopyableNotMovable{
public:
    LibsInfo();

    std::string get_openCV() const noexcept;
    uint is_opencv2() const noexcept;

private:

};



