#include "shell.h"
#include <stdio.h>
#include <string.h>

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Arguments from the terminal
 * @env: Environment list
 * Return: Always 0
 */
int main(int argc, char **a_v, char **env_1)
{
	int val;

	if (argc != 1)
	{
		line_put("Usage: ");
		line_put(a_v[0]);
		_putchar('\n');
		return (1);
	}

	while (EOF)
	{
		val = starting(ar_v, env_1);
		if (val == 10)
			return (0);
		if (val)
			return (val);
	}
	return (0);
}

/**
 * starting - Launches the shell prompt
 * @argv: Arguments from the main function
 * @env: Environment list
 * Return: Integers as success or error codes
 */
int starting(char **a_v, char **env_i)
{
size_t n;
ssize_t res;
char *l_bu, *com, **sp_str;
char pathn[] = "/bin/", prompter[] = "#cisfun$ ";
buil_fun bin_function;

n=0;
l_bu = NULL;
if (isatty(0))
	line_put(prompter);
res = getline(&l_bu, &n, stdin);
if (res == -1)
{
free(linebuffer);
return (10);
}
linebuffer[res - 1] = '\0';
sp_str = _strsplit(l_bu, ' ');
com = sp_str[0];
if (path_way(com) != NULL)
com = path_way(com);
bin_function = get_b(com);
if (bin_function)
{
e_array(sp_str);
free(l_bu);
bin_function(env_i);
}
if (checking(pathn, com) == 1)
{com_execute(pathn, com &l_bu,
&sp_str, argv, env);
e_array(sp_str);
}
else
{
printf("%s: command not found\n", a_v[0]);
}
free(l_bu);
return (0);
}

