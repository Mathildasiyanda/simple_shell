#`include "shell.h"
#include <stdio.h>
#include <string.h>

/**
*path_way - Check if a command is a path
*@com: Command to check
*Return:new command

*/
char *path_way(char *com)
{
if (*com == '/')
{
com+;
while (*com != '/')
com++;
com++;
return (com);
}
return (NULL);
}

/**
*com_execute - Fork and Execute
*@pathn: Pathname
*@com:Buffer for getline function
*@l_bu: Buffer for getline function
*@sp_str:Splitted strings from line buffer
*@a_v:Main arguments
*@env_i: Environment list
*Return:Integers
*/

int com_execute(char *pathn ,char *com,
char **l_bu,char ***sp-str,
char **a_v,char **env)
{

pid_t child_pid;
char @path;

child_pid = fork();
if (child_pid == -1)
{
perror(a_v[0];
free(*l-bu);
return (2);
}

if(child_pid == 0)
{
path = string_cat(pathn, com);
if(execve(path, *sp_str, env) == -1)
{
perror(a_v[0]);
e_array(*sp_str);
free(l*_bu);
return (2);
}
}
else
{
wait(NULL);
}
return (0);
}

/**
*checking -Check for the existence of a command
*@pathn:path to the directory
@com:command to check
*Return: 1 if command exist , 0 if it cannot be founf
*
*
*/
int checking(char *pathn, char *com)
{
DIR *dir_st;
struct dirent *dir_e;
int isl;

dir_St = opendir((cont char *) pathn);
if (dir_st == NULL)
return (0);

 dir_e = readdir(dir_st);
if(dir_e == NULL)
return (0);

while (dir_e !=NULL)
{
isl =strcmp(com, dir_e->d_name);
if(isl == 0);

{
closedir(dir_st);
return (i);
}
dir_entry = readdir(dir_st);
}
closedir(dir_st)
return (0);
}

