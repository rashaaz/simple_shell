#include "main.h"

/**
 * buffer_free_me - Frees a pointer
 * @ss: address the pointer
 *
 * Return: 1 , otherwise 0.
 */
int buffer_free_me(void **ss)
{
	if (ss && *ss)
	{
		free(*ss);
		*ss = NULL;
		return (1);
	}
	return (0);
}

/**
 * print_digit_me - Print an integer
 * to the specified file descriptor.
 * @inp: The input integer.
 * @x: The file descriptor.
 *
 * Return: The number of
 * characters printed.
 */
int print_digit_me(int inp, int x)
{
	int (*__putchar)(char) = _putchar;
	int ii, coun = 0;
	unsigned int sp, now;

	if (x == STDERR_FILENO)
		__putchar = _aputchar_me;
	if (inp < 0)
	{
		sp = -inp;
		__putchar('-');
		coun++;
	}
	else
		sp = inp;
	now = sp;
	for (ii = 1000000000; ii > 1; ii /= 10)
	{
		if (sp / ii)
		{
			__putchar('0' + now / ii);
			coun++;
		}
		now %= ii;
	}
	__putchar('0' + now);
	coun++;

	return (coun);
}

/**
 * s_alias_me - Sets an alias in ff->a
 * @ff: A pointer to the ff_t structure
 * @s: The string representing the alias
 * Return: 1 if an error occurred, 0 otherwise
 */

int s_alias_me(ff_t *ff, char *s)
{
	char *po;

	po = _chme(s, '=');
	if (!po)
		return (1);
	if (!*++po)
		return (u_alias_me(ff, s));

	u_alias_me(ff, s);
	return (a_n_end(&(ff->a), s, 0) == NULL);
}
/**
 * split - Splits a string into
 * words based
 * on delimiter characters.
 * @si: The input string to split.
 * @del: The delimiter string.
 *
 * Return: An array of strings
 * representing the
 * split words, or NULL if failed.
 */

char **split(char *si, char *del)
{
	int ii, jj, r, h, nw = 0;
	char **c;

	if (si == NULL || si[0] == 0)
		return (NULL);
	if (!del)
		del = " ";
	for (ii = 0; si[ii] != '\0'; ii++)
		if (!is_del(si[ii], del) && (is_del(si[ii + 1], del) || !si[ii + 1]))
			nw++;

	if (nw == 0)
		return (NULL);
	c = malloc((1 + nw) * sizeof(char *));
	if (!c)
		return (NULL);
	for (ii = 0, jj = 0; jj < nw; jj++)
	{
		while (is_del(si[ii], del))
			ii++;
		r = 0;
		while (!is_del(si[ii + r], del) && si[ii + r])
			r++;
		c[jj] = malloc((r + 1) * sizeof(char));
		if (!c[jj])
		{
			for (r = 0; r < jj; r++)
				free(c[r]);
			free(c);
			return (NULL);
		}
		for (h = 0; h < r; h++)
			c[jj][h] = si[ii++];
		c[jj][h] = 0;
	}
	c[jj] = NULL;
	return (c);
}
/**
 * print_l - Prints the
 * linked list
 * @hh: A pointer to the
 * head of the linked list
 * Return: The number of nodes in the linked list
 */

size_t print_l(const ll_t *hh)
{
	size_t j = 0;

	while (hh)
	{
		print_many_characters(_convert(hh->numb, 10, 0));
		_putchar(':');
		_putchar(' ');
		print_many_characters(hh->uu ? hh->uu : "(nil)");
		print_many_characters("\n");
		hh = hh->next;
		j++;
	}
	return (j);
}
