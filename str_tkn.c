
#include "shell.h"
/**
 * _strtok -  separates strings with delimiters
 * @line:  the pointer to array we receive in getline.
 * @delim:  characters we mark off string in parts.
 * Return:  pointer to the created token
*/
char *_strtok(char *line, char *delim)
{
	int r;
	static char *str;
	char *copystr;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (r = 0; delim[r] != '\0'; r++)
		{
			if (*str == delim[r])
			break;
		}
		if (delim[r] == '\0')
			break;
	}
	copystr = str;
	if (*copystr == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (r = 0; delim[r] != '\0'; r++)
		{
			if (*str == delim[r])
			{
				*str = '\0';
				str++;
				return (copystr);
			}
		}
	}
	return (copystr);
}
