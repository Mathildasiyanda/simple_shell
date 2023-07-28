/**
 * _strcpy - Copies the characters in src into dest
 * @de_s: Pointer to the string to be copied to
 * @sr_c: Pointer to the source to be copied from
 * Return: the copied string
 */
char *_strcpy(char *de_s, char *sr_c)
{
        unsigned int i;

        i = 0;
        while (sr_c[i])
        {
                de_s[i] = sr_c[i];
                i++;
        }
        de_s[i] = '\0';

        return (de_s);
}

/**
 * _strncpy - Copies the characters in src into dest
 * @dest: Pointer to the string to be copied to
 * @src: Pointer to the source to be copied from
 * @n: the number of bytes to copy
 * Return: the copied string
 */
char *_strncpy(char *dest, char *src, int n)
{
        int i;

        i = 0;
        while (src[i] && i < n)
        {
                dest[i] = src[i];
                i++;
        }
        while (i < n)
        {
                dest[i] = '\0';
                i++;
        }

        return (dest);
}

/**
 * _strsplit - Splits a string into an array using the specified delimiter
 * @strn: The string to split
 * @deli: The delimiter to split
 *
 * Return: NULL-terminated Array of strings
 */
char **_strsplit(char *strn, char deli)
{
        /* Implementation of _strsplit */
}
