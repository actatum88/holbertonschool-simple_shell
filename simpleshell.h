#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

extern int execle (const char *__path, const char *__arg, ...);
int main(int ac, char **av, char **env);

#endif
