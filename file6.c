#include "main.h"

/**
 * _copy - Copies a string.
 * @destination: The destination buffer.
 * @source: The source string.
 *
 * Return: A pointer to the
 * destination buffer.
 */

char *_copy(char *destination, char *source)
{
	int j = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[j])
	{
		destination[j] = source[j];
		j++;
	}
	destination[j] = 0;
	return (destination);
}
/**
 * _realloc_me - Reallocates memory
 * for a block of memory
 * @pot: Pointer to the previously
 * allocated memory block
 * @o_size: The old size of the memory block
 * @n_size: The new size of the memory block
 * Return: A pointer to the reallocated memory
 * block or NULL on failure
 */

void *_realloc_me(void *pot, unsigned int o_size, unsigned int n_size)
{
	char *po;

	if (!pot)
		return (malloc(n_size));
	if (!n_size)
		return (free(pot), NULL);
	if (n_size == o_size)
		return (pot);

	po = malloc(n_size);
	if (!po)
		return (NULL);

	o_size = o_size < n_size ? o_size : n_size;
	while (o_size--)
		po[o_size] = ((char *)pot)[o_size];
	free(pot);
	return (po);
}
/**
 * findpathme - Find a command in the given path.
 * @ff: The structure containing function
 * arguments and environment variables.
 * @pathme: The path to search for the command.
 * @m: The command to find.
 *
 * Return: A pointer to the full path of
 * the command if found, NULL otherwise.
 */
char *findpathme(ff_t *ff, char *pathme, char *m)
{
	int ii = 0, curr = 0;
	char *p;

	if (!pathme)
		return (NULL);
	if ((_len(m) > 2) && _with(m, "./"))
	{
		if (iscmdme(ff, m))
			return (m);
	}
	while (1)
	{
		if (!pathme[ii] || pathme[ii] == ':')
		{
			p = dupchars_me(pathme, curr, ii);
			if (!*p)
				_concat(p, m);
			else
			{
				_concat(p, "/");
				_concat(p, m);
			}
			if (iscmdme(ff, p))
				return (p);
			if (!pathme[ii])
				break;
			curr = ii;
		}
		ii++;
	}
	return (NULL);
}

/**
 * _mysetenv_me - Set the value
 * of an environment variable.
 * @ff: Pointer to an ff_t structure.
 *
 * Return: 0 on success, 1 on failure.
 */
int _mysetenv_me(ff_t *ff)
{
	if (ff->argc != 3)
	{
		_aputs_me("Incorrect number of arguements\n");
		return (1);
	}
	if (_senv_me(ff, ff->argv[1], ff->argv[2]))
		return (0);
	return (1);
}
/**
 * _dupl - Duplicates a string.
 * @s: The input string to
 * duplicate.
 *
 * Return: A pointer to the
 * duplicated string.
 */
char *_dupl(const char *s)
{
	int l = 0;
	char *res;

	if (s == NULL)
		return (NULL);
	while (*s++)
		l++;
	res = malloc(sizeof(char) * (l + 1));
	if (!res)
		return (NULL);
	while (l--)
		res[l] = *--s;
	return (res);
}
