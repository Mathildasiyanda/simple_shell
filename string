#include "shell.h"

/**
 * string_cat - Concatenate two strings
 * @de_s: String to concatenate to
 * @sr_c: String to be added
 * Return: Concatenate string
 */
char *string_cat(char *de_s, char *sr_c)
{
	char *starter;

	starter = de_s;
	while (*starter != '\0')
	{
		starter++;
	}

	while (*sr_c != '\0')
	{
		*starter = *sr_c;
		sr_c++;
		starter++;
	}

	*starter = '\0';
	return (de_s);
}

