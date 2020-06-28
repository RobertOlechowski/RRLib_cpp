#pragma once

namespace RRUtils {

class NonCopyable {
protected:
    NonCopyable() = default;
    virtual ~NonCopyable() = default;

public:
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable& operator=(const NonCopyable &) = delete;
};

class NonCopyableNotMovable : public NonCopyable {
protected:
    NonCopyableNotMovable() = default;
    ~NonCopyableNotMovable() override = default;

public:
    NonCopyableNotMovable(NonCopyableNotMovable &&) = delete;
    NonCopyableNotMovable& operator=(NonCopyableNotMovable &&) = delete;
};


}