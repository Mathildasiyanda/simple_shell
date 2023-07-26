#include "shell.h"

/**
 * clear_info - initializes info_t struct
 * @data: The info_t struct to be cleared
 */
void clear_info(info_t *data)
{
	data->arg = NULL;
	data->args = NULL;
	data->path = NULL;
	data->arg_count = 0;
}

/**
 * set_info - initializes info_t struct
 * @data: The info_t struct to be set
 * @av: Argument vector
 */
void set_info(info_t *data, char **av)
{
	int i = 0;

	data->fname = av[0];
	if (data->arg)
	{
		data->args = strtow(data->arg, " \t");
		if (!data->args)
		{
			data->args = malloc(sizeof(char *) * 2);
			if (data->args)
			{
				data->args[0] = _strdup(data->arg);
				data->args[1] = NULL;
			}
		}
		for (i = 0; data->args && data->args[i]; i++)
			;
		data->arg_count = i;

		replace_alias(data);
		replace_vars(data);
	}
}

/**
 * free_info - frees info_t struct fields
 * @data: The info_t struct to be freed
 * @all: True if freeing all fields
 */
void free_info(info_t *data, int all)
{
	ffree(data->args);
	data->args = NULL;
	data->path = NULL;
	if (all)
	{
		if (!data->cmd_buf)
			free(data->arg);
		if (data->env)
			free_list(&(data->env));
		if (data->history)
			free_list(&(data->history));
		if (data->alias)
			free_list(&(data->alias));
		ffree(data->environ);
		data->environ = NULL;
		bfree((void **)data->cmd_buf);
		if (data->readfd > 2)
			close(data->readfd);
		_putchar(BUF_FLUSH);
	}
}
