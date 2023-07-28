#include "shell.h"

/**
 * _strlen - Gets length of a string
 * @s: String
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int i;


	while (s[i])
	{
		i++;
	}
	return (i);
}

/**
 * _strcmp - Compare two string to check for equality
 * @s1: First string
 * @s2: Second String
 * Return: Difference between their characters
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i, diff, len1, len2;

	i = 0;
	diff = 0;
	len1 = _strlen(s1);
	len2 = _strlen(s2);

	if (len1 != len2)
	{
		diff = len1 - len2;
		return (diff);
	}

	while (s1[i] != '\0')
	{
		if (s1[i] > s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		else if (s1[i] < s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
		i++;
	}
	return (diff);
}
