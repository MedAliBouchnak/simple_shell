#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @rss: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *rss)
{
	int i = 0;

	if (dest == rss || rss == 0)
		return (dest);
	while (rss[i])
	{
		dest[i] = rss[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	int length = 0;
	char *het;

	if (s == NULL)
		return (NULL);
	while (*s++)
		length++;
	het = malloc(sizeof(char) * (length + 1));
	if (!het)
		return (NULL);
	for (length++; length--;)
		het[length] = *--s;
	return (het);
}

/**
 *_puts - prints an input string
 *@s: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
