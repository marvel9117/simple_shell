#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_i 1024
#define MAX_BUFFER_SIZE 250

int _putchar(char c);
int _printstring(char *str);
char *location(char *path, char *arg);
int handleloc(char **cmds);
int _builtincmd(char **arg);


int handle_args(int ac, char **argv, int *file_exec);
void signalhandler(int sinal_num);
char *handle_comment(char *buffer);


/*strings*/
char *_strcat(char *desti, char *src);
int _strcmp(char *str1, char *str2);
int _strcmpd(char *fstring, const char *sub);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strlen(const char *str);
int _strcmps(char *fstring, const char *sub);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strncat(char *dest, const char *src, size_t n);

void free_pp(char **p);
void *_realloc(void *ptr, unsigned int s);
void *_malloc(unsigned int s);
int _arlen(char **n);
void trim_spaces(char **str, char *strim);
char **_arrdup(char **src);

void print_error(char *prog, int *cmdr, char *msg);
int _write(int fd, char *inps, int len);
char *_itoaa(int n);
int num_len(unsigned int num);
int cal_expo(unsigned int base, int power);

char **parse_input(char *cmd_input, char *deli);
int arg_count(char *cmd_input, char *deli);
void error_exit(char *msg);


void handle_dol_replacement(char **cmds);

char *_strtok(char *str, char *deli);
int isdeli(char ch, char *deli);

char *_getenv(char *varname);

#endif /*SHELL_H*/
