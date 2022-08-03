#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H
#define BUFFER 1024

#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * struct builtins - list of builtins
 * @option: bulitin option
 * @f: function for builtin
 * Description: list of builtins with their executable functions
 */

/*Changing default values of enum constants*/
enum builtins_exec_status {
  ExecStatusNoop = 0,
  ExecStatusSuccess = 1,
  ExecStatusExit = -1
};

typedef struct builtins {
  char *option;
  enum builtins_exec_status (*f)(void);
} builtins_t;

void _strcpy(char *str1, char *str2);
int _putchar(char c);
int _strlen(char *s);
char *_getenv(const char *name);
char *_getline(FILE *fp);
int _strcmp(char *s1, char *s2);
char **make_av(char *str);
int _myexit(void);
int _printenv(void);
int execute(char **command);
int main(void);
int builtinchecker(char **toks);
int numbuilt(builtins_t builtin[]);

extern char **environ;

#endif
