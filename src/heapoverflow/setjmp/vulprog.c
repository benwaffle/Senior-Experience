#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <setjmp.h>

#define BUFSIZE 16

static char buf[BUFSIZE];
jmp_buf jmpbuf;

#define DEF_GET_REG(reg) unsigned long get##reg() { __asm__("mov %" #reg ",%rax"); }
DEF_GET_REG(rbx)
DEF_GET_REG(rsi)
DEF_GET_REG(rdi)
DEF_GET_REG(rdx)
DEF_GET_REG(rbp)
DEF_GET_REG(rsp)
DEF_GET_REG(r12)
DEF_GET_REG(r13)
DEF_GET_REG(r14)
DEF_GET_REG(r15)

unsigned long getrip() { __asm__("lea (%rip),%rax"); }

int main(int argc, char **argv) {
	if (argc <= 1) {
		fprintf(stderr, "Usage: %s <string1> <string2>\n", argv[0]);
		exit(-1);
	}

	printf("[vulprog] argv[2] = %p\n", argv[2]);
//	printf("[vulprog] sp = 0x%lx\n\n", getrsp());
	
	if (setjmp(jmpbuf)) { // if > 0, get here from longjmp()
		fprintf(stderr, "error: exploit didn't work\n");
		exit(-1);
	}

#define PR_REG(reg) printf(#reg " = 0x%lx\n", get##reg())
	PR_REG(rbx);
	PR_REG(rbp);
	PR_REG(r12);
	PR_REG(r13);
	PR_REG(r14);
	PR_REG(r15);
	PR_REG(rsp);
	PR_REG(rip);
/*
	PR_REG(rdx);
	PR_REG(rdi);
	PR_REG(rsi);*/

	printf("before:\n");
	int i;
	for (i = 0; i < 8; ++i)
		printf("0x%lx ", jmpbuf[0].__jmpbuf[i]);

	printf("\n");

	strncpy(buf, argv[1], strlen(argv[1]));
	
	printf("after:\n");
	for (i = 0; i < 8; ++i)
		printf("0x%lx ", jmpbuf[0].__jmpbuf[i]);
	printf("\n");	

	return 0;
}
