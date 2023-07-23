#include "shell.h"

/**
 * is_interactive - returns true if the shell is in interactive mode
 * @shell_info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive(info_t *shell_info)
{
	return (isatty(STDIN_FILENO) && shell_info->readfd <= 2);
}

/**
 * is_delimiter - checks if the character is a delimiter
 * @ch: the char to check
 * @delim_str: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delimiter(char ch, char *delim_str)
{
	while (*delim_str)
	{
		if (*delim_str++ == ch)
			return (1);
	}
	return (0);
}

/**
 * is_alpha - checks for an alphabetic character
 * @ch: The character to input
 * Return: 1 if ch is alphabetic, 0 otherwise
 */
int is_alpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in the string, converted number otherwise
 */
int _atoi(char *str)
{
	int i, sign = 1, flag = 0, result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = -result;

	return (result);
}
