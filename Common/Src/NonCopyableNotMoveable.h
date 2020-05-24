#pragma once

namespace Utls {

    class NonCopyableNotMoveable
    {
    protected:
        NonCopyableNotMoveable() {}
        ~NonCopyableNotMoveable() {}
    private:
        NonCopyableNotMoveable(const NonCopyableNotMoveable &) = delete;
        NonCopyableNotMoveable(NonCopyableNotMoveable &&) = delete;

        NonCopyableNotMoveable& operator=(const NonCopyableNotMoveable &) = delete;
        NonCopyableNotMoveable& operator=(NonCopyableNotMoveable &&) = delete;
    };


}