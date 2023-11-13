#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@k: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int k)
{
	int i, j;
	char *c = dest;

	i = 0;
	while (src[i] != '\0' && i < k - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < k)
	{
		j = i;
		while (j < k)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (c);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@k: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int k)
{
	int i, j;
	char *c = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (c);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
