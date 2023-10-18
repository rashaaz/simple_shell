#include "main.h"

/**
 * l_t_s - Converts a linked
 * list of strings to an array of strings
 * @h: A pointer to the head of the linked list
 * Return: An array of strings or NULL on failure
 */
char **l_t_s(ll_t *h)
{
	ll_t *n = h;
	size_t ii = l_l(h), jj;
	char **ptr;
	char *uu;

	if (!h || !ii)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ii + 1));
	if (!ptr)
		return (NULL);
	ii = 0;
	while (n)
	{
		uu = malloc(_len(n->uu) + 1);
		if (!uu)
		{
			jj = 0;
			while (jj < ii)
			{
				free(ptr[jj]);
				jj++;
			}
			free(ptr);
			return (NULL);
		}

		uu = _copy(uu, n->uu);
		ptr[ii] = uu;
		ii++;
		n = n->next;
	}
	ptr[ii] = NULL;
	return (ptr);
}
/**
 * _Handler - Signal handler
 * function for SIGINT (Ctrl+C)
 * @sig_num: The signal number (unused)
 */
void _Handler(__attribute__((unused))int sig_num)
{
	print_many_characters("\n");
	print_many_characters("$ ");
	_putchar(BUFFER_D);
}
/**
 * _senv_me - Set an
 * environment variable.
 * @ff: Pointer to an ff_t structure.
 * @vv: The name of the environment
 * variable to set.
 * @val: The value to assign to the
 * environment variable.
 *
 * Return: 0 on success, 1 on memory
 * allocation failure.
 */
int _senv_me(ff_t *ff, char *vv, char *val)
{
	char *bufer = NULL;
	ll_t *n;
	char *pp;

	if (!vv || !val)
		return (0);

	bufer = malloc(_len(vv) + _len(val) + 2);
	if (!bufer)
		return (1);
	_copy(bufer, vv);
	_concat(bufer, "=");
	_concat(bufer, val);
	n = ff->envnow;
	while (n)
	{
		pp = _with(n->uu, vv);
		if (pp && *pp == '=')
		{
			free(n->uu);
			n->uu = bufer;
			ff->r_env_ch = 1;
			return (0);
		}
		n = n->next;
	}
	a_n_end(&(ff->envnow), bufer, 0);
	free(bufer);
	ff->r_env_ch = 1;
	return (0);
}
/**
 * _aputchar_me - Write a
 * character to the standard error.
 * @c: The character to write.
 *
 * Return: 1 on success.
 */
int _aputchar_me(char c)
{
	static int ii;
	static char bufer[W_SIZE];

	if (c == BUFFER_D || ii >= W_SIZE)
	{
		write(2, bufer, ii);
		ii = 0;
	}
	if (c != BUFFER_D)
		bufer[ii++] = c;
	return (1);
}
/**
 * _my_erratoi - Convert a string
 * to an integer.
 * @g: The input string.
 *
 * Return: The integer value if conversion
 * is successful, or -1 on error.
 */
int _my_erratoi(char *g)
{
	int ii = 0;
	unsigned long int r = 0;

	if (*g == '+')
		g++;
	while (g[ii] != '\0')
	{
		if (g[ii] >= '0' && g[ii] <= '9')
		{
			r *= 10;
			r += (g[ii] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
		ii++;
	}
	return (r);
}
