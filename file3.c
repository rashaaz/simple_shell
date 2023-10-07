#include "main.h"

/**
 * st_in_me - Set input
 * variables in the ff_t structure.
 * @ff: Pointer to an ff_t structure.
 * @av: Array of command-line arguments.
 */

void st_in_me(ff_t *ff, char **av)
{
	int ii = 0;

	ff->newname = av[0];
	if (ff->arg)
	{
		ff->argv = split(ff->arg, " \t");
		if (!ff->argv)
		{

			ff->argv = malloc(sizeof(char *) * 2);
			if (ff->argv)
			{
				ff->argv[0] = _dupl(ff->arg);
				ff->argv[1] = NULL;
			}
		}
		for (ii = 0; ff->argv && ff->argv[ii]; ii++)
			;
		ff->argc = ii;

		repl_al_me(ff);
		repl_vars_me(ff);
	}
}

/**
 * _unsetenvnew_me - Unset an
 * environment variable.
 * @ff: Pointer to an ff_t structure.
 * @vv: The name of the
 * environment variable to unset.
 *
 * Return: 0 on success, or
 * the number
 * of environment variables
 * modified on failure.
 */

int _unsetenvnew_me(ff_t *ff, char *vv)
{
	ll_t *n = ff->envnow;
	size_t ii = 0;
	char *pp;

	if (!n || !vv)
		return (0);

	while (n)
	{
		pp = _with(n->uu, vv);
		if (pp && *pp == '=')
		{
			ff->r_env_ch = delete_n(&(ff->envnow), ii);
			ii = 0;
			n = ff->envnow;
			continue;
		}
		n = n->next;
		ii++;
	}
	return (ff->r_env_ch);
}

/**
 * _error_print_me - Print an
 * error message.
 * @ff: Pointer to an ff_t
 * structure.
 * @es: The error message.
 */
void _error_print_me(ff_t *ff, char *es)
{
	_aputs_me(ff->newname);
	_aputs_me(": ");
	print_digit_me(ff->co, STDERR_FILENO);
	_aputs_me(": ");
	_aputs_me(ff->argv[0]);
	_aputs_me(": ");
	_aputs_me(es);
}

/**
 * free_l - Frees the entire list
 * @h_p: A pointer to a pointer
 * to the head of the list
 */

void free_l(ll_t **h_p)
{
	ll_t *n, *n_n, *h;

	if (!h_p || !*h_p)
		return;
	h = *h_p;
	n = h;
	while (n)
	{
		n_n = n->next;
		free(n->uu);
		free(n);
		n = n_n;
	}
	*h_p = NULL;
}

/**
 * _comp - Performs a lexicographic
 * comparison of two strings.
 * @str1: The first string to compare.
 * @str2: The second string to compare.
 *
 * Return:
 *   - A negative value if str1 is
 * lexicographically less than str2.
 *   - A positive value if str1 is
 * lexicographically greater than str2.
 *   - Zero if str1 is
 * lexicographically equal to str2.
 */
int _comp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		case (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		return (*str1 < *str2 ? -1 : 1);
	}
}
