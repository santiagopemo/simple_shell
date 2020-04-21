#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <stddef.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)

/**
 * struct formato - structure for the function slector
 * @z: format to print
 * @fun: function that print the format
 */
typedef struct formato
{
	char *z;
	int (*fun)(int, va_list);
} fmt;

int _dputchar(int fd, char c);
int fun_string(int fd, va_list s);
int fun_per(int fd, va_list c);
int fun_dec(int fd, va_list d);
int fun_uns(int fd, va_list u);
int (*get_func(const char *s))(int, va_list);
int _dprintf(int fd, const char *format, ...);

/**
 * struct env_s - singly linked list with the enviroment
 * @name: name of the variable
 * @value: value of the variable
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct env_s
{
	char *name;
	char *value;
	struct env_s *next;
} env_t;

/**
 * struct vars_s - struc with the program variables
 * @av:array with the arguments
 * @l_buffer: buffer for function getline() with the input
 * @len_buffer: length of the buffer with the input
 * @status: cummand exit status
 * @commands: array whith the command and arguments
 * @num_ins: number of read commnads from getline
 * @env: array with the enviromental variables
 * @commands_tok: array of commands whit ";" delimiter
 * @env_head: pointer to head of a linked list
 */
typedef struct vars_s
{
	char **av;
	char *l_buffer;
	size_t len_buffer;
	int status;
	char **commands;
	size_t num_ins;
	char **env;
	char **commands_tok;
	env_t *env_head;

} vars_t;

/**
 * struct builtins_s - estruc of builtins
 * @name: name of builtin
 * @f: function pointer to builtin functions
 */
typedef struct builtins_s
{
	char *name;
	void (*f)(vars_t *vars);
} builtins_t;

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
unsigned int countWords(char *str, char *delimter);
char **split_string(char *str, char *delimiter);
int is_comand(char *cmd, vars_t *vars);
int execute_command(char *command, vars_t *vars);
char **argvdup(char **argv);
char *_getenv(char *env, char **envi);
char *_strstr(char *haystack, char *needle);
char *whit_path(vars_t *vars);
void free_argv(char **argv);
void (*get_builtin(vars_t *vars))(vars_t *vars);
void my_exit(vars_t *vars);
void printenv(vars_t *vars);
int _atoi(char *s);
void myhandle(int mysignal);
int is_path(vars_t *vars);
int check_current_dir(char *path);
char *get_path(char **env);
char *_uitoa(unsigned int count);
int check_command(char *cmd, vars_t *vars);
int _strcmpr(char *s1, char *s2);
void free_env(char **env);
char *_getenvlist(char *name, env_t *head);

env_t *env_to_list(char **argv);
void _setenv(vars_t *vars);
void _unsetenv(vars_t *vars);
env_t *add_node_end(env_t **head, char *name, char *value);
char **list_to_env(env_t *head);
void free_list(env_t *head);
size_t print_list(env_t *h);
int delete_nodeint_at_index(env_t **head, unsigned int index);
int get_env_index(env_t *head, char *name);
char *_strtok(char *str, char *delim);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void print_command_error(vars_t *vars, char *message);
void _cd(vars_t *vars);
void cd_setenv(char *name, char *value, vars_t *vars);
char *cd_check(char *cwd, vars_t *vars);

#endif
