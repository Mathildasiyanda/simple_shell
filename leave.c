#include "shell.h"

/**
 * custom_strncpy - copies a string
 * @destination: the destination string to be copied to
 * @source: the source string
 * @num: the number of characters to be copied
 * Return: the pointer to the destination string
 */
char *custom_strncpy(char *destination, char *source, int num)
{
	int i, j;
	char *s = destination;

	i = 0;
	while (source[i] != '\0' && i < num - 1)
	{
		destination[i] = source[i];
		i++;
	}
	if (i < num)
	{
		j = i;
		while (j < num)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * custom_strncat - concatenates two strings
 * @destination: the first string
 * @source: the second string
 * @num: the number of bytes to be maximally used
 * Return: the pointer to the concatenated string
 */
char *custom_strncat(char *destination, char *source, int num)
{
	int i, j;
	char *s = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (source[j] != '\0' && j < num)
	{
		destination[i] = source[j];
		i++;
		j++;
	}
	if (j < num)
		destination[i] = '\0';
	return (s);
}

/**
 * custom_strchr - locates a character in a string
 * @str: the string to be parsed
 * @character: the character to look for
 * Return: a pointer to the memory area of the character in the string
 */
char *custom_strchr(char *str, char character)
{
	do {
		if (*str == character)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
