#include "shell.h"

/**
 * my_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @data: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int my_history(info_t *data)
{
	print_list(data->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @data: parameter struct
 * @alias_str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *data, char *alias_str)
{
	char *ptr, c;
	int ret;

	ptr = _strchr(alias_str, '=');
	if (!ptr)
		return (1);
	c = *ptr;
	*ptr = 0;
	ret = delete_node_at_index(&(data->alias),
		get_node_index(data->alias, node_starts_with(data->alias, alias_str, -1)));
	*ptr = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @data: parameter struct
 * @alias_str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *data, char *alias_str)
{
	char *ptr;

	ptr = _strchr(alias_str, '=');
	if (!ptr)
		return (1);
	if (!*++ptr)
		return (unset_alias(data, alias_str));

	unset_alias(data, alias_str);
	return (add_node_end(&(data->alias), alias_str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *alias = NULL;

	if (node)
	{
		ptr = _strchr(node->str, '=');
		for (alias = node->str; alias <= ptr; alias++)
			_putchar(*alias);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * my_alias - mimics the alias builtin (man alias)
 * @data: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int my_alias(info_t *data)
{
	int i = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (data->argc == 1)
	{
		node = data->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; data->argv[i]; i++)
	{
		ptr = _strchr(data->argv[i], '=');
		if (ptr)
			set_alias(data, data->argv[i]);
		else
			print_alias(node_starts_with(data->alias, data->argv[i], '='));
	}

	return (0);
}
