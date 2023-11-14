#ifndef SHELL_H
#define SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

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

#define PRINTM(ch) (write(STDOUT_FILENO, ch, _strlen(ch)))

#endif /*END_IF*/
