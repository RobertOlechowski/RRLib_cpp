#include <Common/Asserts.h>
#include <cstring>
#include "Memory.h"

namespace RRLibs {

void Memory::__memory_copy_libc(const void* source, void* destination, size_t size) noexcept {
    memcmp(destination, source, size);
}

void Memory::__memory_copy_uint32(const void* source, void* destination, size_t size) noexcept {
    using T = uint64;

    const size_t steps = size / sizeof(T);
    T* srcPtr = (T*) source;
    T* dstPtr = (T*) destination;
    T* endPtr = srcPtr + steps;
    while (srcPtr < endPtr) {
        *(dstPtr++) = *(srcPtr++);
        *(dstPtr++) = *(srcPtr++);
        *(dstPtr++) = *(srcPtr++);
        *(dstPtr++) = *(srcPtr++);
    }
}

}
