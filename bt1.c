#include "shell.h"

/**
 * display_history - displays the history list, one command per line,
 *                   preceded with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *
 * Return: Always 0
 */
int display_history(info_t *info)
{
	print_command_list(info->history);
	return (0);
}

/**
 * unset_alias_command - removes an alias from the alias list
 * @info: parameter struct
 * @alias_str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias_command(info_t *info, char *alias_str)
{
	char *equal_sign_pos, temp_char;
	int ret;

	equal_sign_pos = _strchr(alias_str, '=');
	if (!equal_sign_pos)
		return (1);

	temp_char = *equal_sign_pos;
	*equal_sign_pos = '\0';
	ret = delete_alias_node_at_index(&(info->alias),
		get_alias_node_index(info->alias, alias_str, -1));
	*equal_sign_pos = temp_char;
	return (ret);
}

/**
 * set_alias_command - sets an alias in the alias list
 * @info: parameter struct
 * @alias_str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias_command(info_t *info, char *alias_str)
{
	char *equal_sign_pos;

	equal_sign_pos = _strchr(alias_str, '=');
	if (!equal_sign_pos)
		return (1);

	if (!*++equal_sign_pos)
		return (unset_alias_command(info, alias_str));

	unset_alias_command(info, alias_str);
	return (add_alias_node_end(&(info->alias), alias_str, 0) == NULL);
}

/**
 * print_alias_command - prints an alias string
 * @alias_node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias_command(alias_t *alias_node)
{
	char *equal_sign_pos = NULL, *alias_str = NULL;

	if (alias_node)
	{
		equal_sign_pos = _strchr(alias_node->str, '=');
		for (alias_str = alias_node->str; alias_str <= equal_sign_pos; alias_str++)
			_putchar(*alias_str);

		_putchar('\'');
		_puts(equal_sign_pos + 1);
		_puts("'\n");
		return (0);
	}

	return (1);
}

/**
 * alias_command - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 * Return: Always 0
 */
int alias_command(info_t *info)
{
	int i = 0;
	char *equal_sign_pos = NULL;
	alias_t *alias_node = NULL;

	if (info->argc == 1)
	{
		alias_node = info->alias;
		while (alias_node)
		{
			print_alias_command(alias_node);
			alias_node = alias_node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		equal_sign_pos = _strchr(info->argv[i], '=');
		if (equal_sign_pos)
			set_alias_command(info, info->argv[i]);
		else
			print_alias_command(find_alias_node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
