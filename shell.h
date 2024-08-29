#ifndef _SHELL_H_
#define _SHELL_H_
#define MAX_WORDS 1024
#define SEPARATOR " \n\t"

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/*Prototypes*/
int main(void);
int son_process(char *line_buffer);
void execvp_function(char **array, char *tmp_line_buffer);
void malloc_error(char *tmp_line_buffer, char **array);
int error_tmp_dup(char *tmp_line_buffer);
#endif /*_SHELL_H_*/
