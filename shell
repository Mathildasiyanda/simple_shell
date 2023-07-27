#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>



/**
 * struct builtin_s - Builtin function struct
 * @f_na: Name of builtin function
 * @f_call: Function to be called
 */
typedef struct builtin_s
{
	char *f_na;
	void (*f_call)(char **env_i);
} b_f;

typedef void (*buil_fun)(char **env_i);
buil_fun get_b(char *na);
void exiting_fu(char **env_i);
void print_f(char **env_i);
char *builder(char *strn, unsigned int sta, unsigned int end);
void e_array(char **ar);
char *path_way(char *com);
int starting(char **a_v, char **env_i);
int checking(char *pathn, char *com);
int com_execute(char *pathn, char *com,
		    char **l_bu, char ***sp_str,
		    char **a_v, char **env_i);


int _putchar(char c);
unsigned int line_put(char *s);
unsigned int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char **_strsplit(char *strn, char deli);
char *string_cat(char *de_s, char *sr_c);
int chara_counter(char *strn, char c);

#endif
