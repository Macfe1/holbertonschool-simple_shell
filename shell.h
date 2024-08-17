#ifndef _SHELL_H_
#define _SHELL_H_

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Prototypes*/
int main(void);
void son_process(char *line_buffer);

#endif /*_SHELL_H_*/
