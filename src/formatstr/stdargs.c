#include <stdio.h>
#include <stdarg.h>

void f(int first, ...) {
    va_list args;
    va_start(args, first);
    va_end(args);
}

int main() {
    f(0,1,2,3,4,5,6,7,8,9,10);
}
