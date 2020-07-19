#include <Assert/Asserts.h>

void func4() {RRLibs::assert_test(false);}
void func3() {func4();}
void func2() {func3();}
void func1() {func2();}


int main() {
    func1();
    return 0;
}