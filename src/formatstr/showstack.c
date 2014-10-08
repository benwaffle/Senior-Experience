#include <stdio.h>

int main() {
   // prints memory at 0x7fff08480110 until a NUL byte is reached
   // need 5 of "%08x", which read 4 bytes each
   // the last %08x holds the address of str, and the next thing read is a copy of str
   char str[] = "\x10\x01\x48\x08\xff\x7f\x00\x00_%08x.%08x.%08x.%08x.%08x|%s|";
   printf("str at %p\n", str);
   printf(str);


}
