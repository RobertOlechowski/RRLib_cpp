#pragma once

#include "Common/Types.h"
#include <type_traits>


namespace RRLibs::Math {

template<typename T>
struct Vec2 {
private:
    using T_s = typename std::make_signed<T>::type;
    using T_u = typename std::make_unsigned<T>::type;

public:
    explicit Vec2<T>() : p1(0), p2(0) {}

    explicit Vec2<T>(T a1, T a2) : p1(a1), p2(a2) {}

    void set(T a1, T a2) {
        p1 = a1;
        p2 = a2;
    };

    void assign_target(T_u& t1, T_u& t2) const {
        t1 = p1;
        t2 = p2;
    };

    void assign_target(T_s& t1, T_s& t2) const {
        t1 = p1;
        t2 = p2;
    };

    union {
        T x;
        T w;
        T p1;
    };

    union {
        T y;
        T h;
        T p2;
    };
};

using Vec2f = Vec2<float>;
using Vec2d = Vec2<double>;
using Vec2u = Vec2<uint>;
using Vec2i = Vec2<int>;

using Vec2u32 = Vec2<uint32>;
using Vec2u64 = Vec2<uint64>;

using Vec2i32 = Vec2<int32>;
using Vec2i64 = Vec2<int64>;

}

