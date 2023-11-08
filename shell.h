#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int _putchar(char c);
int _printstring(char *str);
char *location(char *path, char *arg);
char *get_locate(char *arg);
int _builtincmd(char **arg);



#endif /*SHELL_H*/
