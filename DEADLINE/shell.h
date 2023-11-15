#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define PRINTM(ch) (write(STDOUT_FILENO, ch, _strlen(ch)))

#define BUFFSIZE 1024

extern char **environ;

/*parse_input*/
char **parse_input(char *input);

/*malloc*/
size_t get_block_size(void *ptr);
void *_realloc(void *ptr, unsigned int s);

char *_itoaa(int n);
int cal_expo(unsigned int base, int power);
int num_len(unsigned int num);

void p_error(char *input, int loopcount, char **argv);

/*string*/
int _strlen(const char *str);
unsigned int isdeli(char ch, const char *deli);
char *_strtok(char *str, char *deli);
int _strlen(const char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *desti, char *src);
int handle_path(char **cmd);
char *_strdup(const char *str);

/*finf_path*/
char *_getenv(char *varname);
void *_memset(void *ptr, int value, size_t  n);
char *constructpath(char *exec, char *dir);

#endif /*END_IF*/
