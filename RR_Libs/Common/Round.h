#pragma once

#include <MathRR/Vec2.h>

namespace RRLibs::Common {

template<class T>
class Round {
public:
    Round() = delete;

    static T Up(T value, uint align) noexcept;

    static Math::Vec2 <T> Up(Math::Vec2 <T> value, const Math::Vec2u& align) noexcept;

    static T Down(T value, uint align) noexcept;

    static Math::Vec2 <T> Down(Math::Vec2 <T> value, const Math::Vec2u& align) noexcept;

private:
    using VecType = Math::Vec2<T>;
};


template<class T>
T Round<T>::Up(T value, uint align) noexcept {
    return Down(value + align - 1, align);
}

template<class T>
T Round<T>::Down(T value, uint align) noexcept {
    return (value & ~(align - 1));
}

template<class T>
Math::Vec2 <T> Round<T>::Up(Math::Vec2 <T> value, const Math::Vec2u& align) noexcept {
    return Math::Vec2<T>(Up(value.p1, align.p1), Up(value.p2, align.p2));
}

template<class T>
Math::Vec2 <T> Round<T>::Down(Math::Vec2 <T> value, const Math::Vec2u& align) noexcept {
    return Math::Vec2<T>(Down(value.p1, align.p1), Down(value.p2, align.p2));
}

}


