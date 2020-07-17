#include "Asserts.h"

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <exception>

namespace RRLibs {


[[noreturn]]
static void _assert_fail(const char* msg) noexcept {
    if (msg != nullptr)
        printf("msg = %s\n", msg);
    printf("\n");

    constexpr uint bt_size = 6;

    void* array[bt_size];
    size_t size = backtrace(array, bt_size);
    char** strings = backtrace_symbols(array, size);

    for (size_t i = 0; i < size; i++)
        printf("\t%s\n", strings[i]);
    free(strings);

    printf("\n");
    std::terminate();
}

static void _assert_txt() noexcept {
    printf("================== Assert ==============\n");
}

[[noreturn]]
void assert_fail(const char* msg) noexcept {
    _assert_txt();
    _assert_fail(msg);
}

void assert_test(bool condition, const char* msg) noexcept {
    if (condition)
        return;
    _assert_txt();
    _assert_fail(msg);
}

void assert_error_code(uint error_code, const char* msg) noexcept {
    if (error_code == 0)
        return;
    _assert_txt();
    printf("Error code = %d\n", error_code);
    _assert_fail(msg);
}

}