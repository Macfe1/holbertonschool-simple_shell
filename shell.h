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

/*Prototypes*/
int main(void);
void son_process(char *line_buffer);

#endif /*_SHELL_H_*/
