#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H
#define BUFFER 1024

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/wait.h>

typedef struct builtins
{
	char *option;
	int (*f)(void);
} builtins_t;

char **make_av(char *str);
int _myexit(void);
int _printenv(void);
int execute(char **command);
char clear(void);
char **p_strtok(char* a_str, char delim);
void print_array(char **array);
extern int execle(const char *__path, const char *__arg, ...);
int main(void);
int builtinchecker(char **toks);
int numbuilt(builtins_t builtin[]);

extern char **environ;

#endif
