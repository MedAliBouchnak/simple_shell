#include "shell.h"

/**
 * list_len - determines length of linked list
 * @p: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *p)
{
	size_t i = 0;

	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @pointerHead: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *pointerHead)
{
	list_t *node = pointerHead;
	size_t i = list_len(pointerHead), j;
	char **strs;
	char *str;

	if (!pointerHead || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @hp: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *hp)
{
	size_t i = 0;

	while (hp)
	{
		_puts(convert_number(hp->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hp->str ? hp->str : "(nil)");
		_puts("\n");
		hp = hp->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @pointerHead: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *pointerHead, list_t *node)
{
	size_t i = 0;

	while (pointerHead)
	{
		if (pointerHead == node)
			return (i);
		pointerHead = pointerHead->next;
		i++;
	}
	return (-1);
}
