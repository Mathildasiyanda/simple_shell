/**
 * clear_info - initializes info_t struct
 * @info_ptr: struct address
 */
void clear_info(info_t *info_ptr)
{
	info_ptr->arg = NULL;
	info_ptr->argv = NULL;
	info_ptr->path = NULL;
	info_ptr->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @info_ptr: struct address
 * @arg_vector: argument vector
 */
void set_info(info_t *info_ptr, char **arg_vector)
{
	int i = 0;

	info_ptr->fname = arg_vector[0];
	if (info_ptr->arg)
	{
		info_ptr->argv = strtow(info_ptr->arg, " \t");
		if (!info_ptr->argv)
		{
			info_ptr->argv = malloc(sizeof(char *) * 2);
			if (info_ptr->argv)
			{
				info_ptr->argv[0] = _strdup(info_ptr->arg);
				info_ptr->argv[1] = NULL;
			}
		}
		for (i = 0; info_ptr->argv && info_ptr->argv[i]; i++)
			;
		info_ptr->argc = i;

		replace_alias(info_ptr);
		replace_vars(info_ptr);
	}
}

/**
 * free_info - frees info_t struct fields
 * @info_ptr: struct address
 * @free_all: true if freeing all fields
 */
void free_info(info_t *info_ptr, int free_all)
{
	ffree(info_ptr->argv);
	info_ptr->argv = NULL;
	info_ptr->path = NULL;
	if (free_all)
	{
		if (!info_ptr->cmd_buf)
			free(info_ptr->arg);
		if (info_ptr->env)
			free_list(&(info_ptr->env));
		if (info_ptr->history)
			free_list(&(info_ptr->history));
		if (info_ptr->alias)
			free_list(&(info_ptr->alias));
		ffree(info_ptr->environ);
		info_ptr->environ = NULL;
		bfree((void **)info_ptr->cmd_buf);
		if (info_ptr->readfd > 2)
			close(info_ptr->readfd);
		_putchar(BUF_FLUSH);
	}
}
