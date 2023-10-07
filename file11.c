#include "main.h"

/**
 * _copyn - Copies up to 'num'
 * characters from 'so' to 'd'.
 * @d: Destination buffer.
 * @so: Source string.
 * @num: Maximum number of characters to copy.
 *
 * Return: Pointer to the destination buffer 'd'.
 */

char *_copyn(char *d, char *so, int num)
{
	int ii, jj;
	char *c = d;

	ii = 0;
	while (so[ii] != '\0' && ii < num - 1)
	{
		d[ii] = so[ii];
		ii++;
	}
	if (ii < num)
	{
		jj = ii;
		while (jj < num)
		{
			d[jj] = '\0';
			jj++;
		}
	}
	return (c);
}
/**
 * rfree_me - Frees a null-terminated
 * array of pointers and the array itself
 * @pop: The array of pointers to be freed
 */

void rfree_me(char **pop)
{
	char **x = pop;

	if (!pop)
		return;
	while (*pop)
		free(*pop++);
	free(x);
}
/**
 * _putdd_me - Write a character to
 * the specified file descriptor.
 * @c: The character to write.
 * @dd: The file descriptor to write to.
 *
 * Return: 1 on success.
 */
int _putdd_me(char c, int dd)
{
	static int ii;
	static char bufer[W_SIZE];

	if (c == BUFFER_D || ii >= W_SIZE)
	{
		write(dd, bufer, ii);
		ii = 0;
	}
	if (c != BUFFER_D)
		bufer[ii++] = c;
	return (1);
}
/**
 * repl_al_me - Replace aliases
 * in the command arguments.
 * @ff: Pointer to an ff_t structure.
 *
 * Return: 1 on success, 0 on failure.
 */
int repl_al_me(ff_t *ff)
{
	int ii;
	ll_t *n;
	char *pp;

	for (ii = 0; ii < 10; ii++)
	{
		n = node_s(ff->a, ff->argv[0], '=');
		if (!n)
			return (0);
		free(ff->argv[0]);
		pp = _chme(n->uu, '=');
		if (!pp)
			return (0);
		pp = _dupl(pp + 1);
		if (!pp)
			return (0);
		ff->argv[0] = pp;
	}
	return (1);
}

/**
 * repl_vars_me - Replace variables in
 * the command arguments.
 * @ff: Pointer to an ff_t structure.
 *
 * Return: 0.
 */
int repl_vars_me(ff_t *ff)
{
	int ii = 0;
	ll_t *n;

	while (ff->argv[ii])
	{
		if (ff->argv[ii][0] != '$' || !ff->argv[ii][1])
			continue;

		if (!_comp(ff->argv[ii], "$?"))
		{
			repl_stri_me(&(ff->argv[ii]),
					_dupl(_convert(ff->str, 10, 0)));
			continue;
		}
		if (!_comp(ff->argv[ii], "$$"))
		{
			repl_stri_me(&(ff->argv[ii]),
					_dupl(_convert(getpid(), 10, 0)));
			continue;
		}
		n = node_s(ff->envnow, &ff->argv[ii][1], '=');
		if (n)
		{
			repl_stri_me(&(ff->argv[ii]),
					_dupl(_chme(n->uu, '=') + 1));
			continue;
		}
		repl_stri_me(&ff->argv[ii], _dupl(""));
		ii++;
	}
	return (0);
}
