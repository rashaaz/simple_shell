#include "main.h"

/**
 * _aputs_me - Print a
 * string to the standard output.
 * @ptr: The string to print.
 */
void _aputs_me(char *ptr)
{
	int ii = 0;

	if (!ptr)
		return;
	while (ptr[ii] != '\0')
	{
		_aputchar_me(ptr[ii]);
		ii++;
	}
}
/**
 * node_s - Searches for a node with
 * a specific prefix and character
 * @n: A pointer to the head of the linked list
 * @pre: The prefix to search for
 * @c: The character
 * to match (-1 to match any character)
 * Return: A pointer to the
 * found node or NULL if not found
 */
ll_t *node_s(ll_t *n, char *pre, char c)
{
	char *po = NULL;

	while (n)
	{
		po = _with(n->uu, pre);
		if (po && ((c == -1) || (*po == c)))
			return (n);
		n = n->next;
	}
	return (NULL);
}
/**
 * _node_i - Find the index of a node in a linked list
 * @h: The head of the linked list
 * @n: The node to find
 *
 * Return: The index of the node if found, or -1 if not found.
 */
ssize_t _node_i(ll_t *h, ll_t *n)
{
	size_t j = 0;

	while (h)
	{
		if (h == n)
			return (j);
		h = h->next;
		j++;
	}
	return (-1);
}
/**
 * dupchars_me - Duplicate characters
 * from a path between two indices.
 * @path: The source path.
 * @bigin: The starting index.
 * @end: The ending index.
 *
 * Return: A newly allocated string
 * containing the duplicated characters.
 */
char *dupchars_me(char *path, int bigin, int end)
{
	static char b[1024];
	int ii = 0, g = 0;

	for (g = 0, ii = bigin; ii < end; ii++)
		if (path[ii] != ':')
			b[g++] = path[ii];
	b[g] = 0;
	return (b);
}
/**
 * _myunsetenv_me - Unset environment variables.
 * @ff: Pointer to an ff_t structure.
 *
 * Return: Always returns 0.
 */
int _myunsetenv_me(ff_t *ff)
{
	int ii;

	if (ff->argc == 1)
	{
		_aputs_me("Too few arguements.\n");
		return (1);
	}
	for (ii = 1; ii <= ff->argc; ii++)
		_unsetenvnew_me(ff, ff->argv[ii]);

	return (0);
}
