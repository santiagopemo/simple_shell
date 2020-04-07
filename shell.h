#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/*add the struct */

/*add the protoytypes */
int _strcmp(char *s1, char *s2);
void prompt(void);
char *_env(char *env);
char *_strstr(char *haystack, char *needle);

#endif /* SHELL */
