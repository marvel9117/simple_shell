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
#include <fcntl.h>
#include <signal.h>

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
int handle_path(char **);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strncat(char *dest, const char *src, size_t n);

/*finf_path*/
char *_getenv(char *varname);
void *_memset(void *ptr, int value, size_t  n);
char *constructpath(char *, char *);


/**exec_command*/
int exec_cmd(char **cmd, char *input, int count, char **argv);
void free_both(char **cmd, char *buff);

/*exit*/
void exit_builtin(char **comand, char *buff, char **argv, int loopcount);
int _atoi(char *str);
int _isalpha(int c);

/*handle arg and sig*/
int handle_args(int ac, char **argv, int *file_exec);
void signalhandler(int __attribute__((unused))signal_num);
char *handle_comment(char *buffer);
void handle_dol_replacement(char **cmds);

#endif /*END_IF*/
