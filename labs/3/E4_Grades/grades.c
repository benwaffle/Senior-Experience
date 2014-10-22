#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 30

char grade = '3';
char Name[BUFSIZE];

void readString(char *s) {
   char buf[BUFSIZE];
   int i = 0; 
   int c;

   while (1) {
      c = fgetc(stdin);
      if ((c == EOF) || (c == '\n')) 
         break;
      buf[i++] = c;
   }
   buf[i] = 0;

   for (i = 0; i < BUFSIZE; i++) 
      s[i] = buf[i];
  
   return;
}

int main(void) {
   mprotect((void*)((unsigned int)Name & 0xfffff000), 1,
            PROT_READ | PROT_WRITE | PROT_EXEC);

   printf("What is your name?\n");
   readString(Name);

   if (strcmp(Name, "George") == 0) 
      grade = '6';

   printf("Thank you, %s.\n", Name);
   printf("I recommend that you get a grade of %c on this assignment.\n", 
          grade);

   exit(0);
}

