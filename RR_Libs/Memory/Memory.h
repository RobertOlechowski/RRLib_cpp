#pragma once

#include <Common/Types.h>
#include <cstdio>
#include <utility>


namespace RRLibs {

class Memory {
public:
    static void memory_copy(const void* source, void* destination, size_t size) noexcept {
        __memory_copy_libc(source, destination, size);
    }


private:
    static void __memory_copy_libc(const void* source, void* destination, size_t size) noexcept;

    static void __memory_copy_uint32(const void* source, void* destination, size_t size) noexcept;
};


}


