#include "shell.h"

/**
* builder - builds a new string
*@strn: The Base String
*@sta: The starting character
*@end: The last character
*
*Return: The new String;
*/

char *buider(char *strn, unsigned int sta, unsigned int end)
{
char *n_strn;
int i = 0,j;

j = (end_ -sta) + 2;

n_strn = malloc(sizeof(char_ *j);

while (sta <= end )

{
newstr[i] = str[sta];
i++;
sta++;
}

n-strn[i] = '\0';

return (n_strn);
}

/**
*e_array -Free all the memory
*@ar: The array to free
*
*Return: void
*/

void e_array(char **ar)
{
unsigned int i=0;

for (i = 0; ar[i] != NULL; i++)
free(ar[i];

free(ar[i]);

free(ar);
}
