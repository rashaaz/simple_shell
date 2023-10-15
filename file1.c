#include "main.h"
/**
 * _len - Computes the length of a string
 * @c: The input string to measure
 *
 * Return: The length of the string as an integer
 * If the input string is NULL, it returns 0.
 */
int _len(char *c)
{
	int j = 0;

	if (!c)
	{
		return (0);
	}

	for (; *c;)
	{
		j++;
		c++;
	}
	return (j);
}

/**
 * split1 - Splits a string into
 * words based on
 * a single delimiter character.
 * @si: The input string to split.
 * @del: The delimiter character.
 *
 * Return: An array of strings representing
 * the split words, or NULL if failed.
 */

char **split1(char *si, char del)
{
	int ii, jj, r, h, nw = 0;
	char **c;

	if (si == NULL || si[0] == 0)
		return (NULL);
	for (ii = 0; si[ii] != '\0'; ii++)
		if ((si[ii] != del && si[ii + 1] == del) ||
				(si[ii] != del && !si[ii + 1]) || si[ii + 1] == del)
			nw++;
	if (nw == 0)
		return (NULL);
	c = malloc((1 + nw) * sizeof(char *));
	if (!c)
		return (NULL);
	for (ii = 0, jj = 0; jj < nw; jj++)
	{
		while (si[ii] == del && si[ii] != del)
			ii++;
		r = 0;
		while (si[ii + r] != del && si[ii + r] && si[ii + r] != del)
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
 * u_alias_me - Updates an alias in ff->a
 * @ff: A pointer to the ff_t structure
 * @s: The string representing the alias
 * Return: 1 if an error occurred, 0 otherwise
 */
int u_alias_me(ff_t *ff, char *s)
{
	char *po, x;
	int res;

	po = _chme(s, '=');
	if (!po)
		return (1);
	x = *po;
	*po = 0;
	res = delete_n(&(ff->a),
			_node_i(ff->a, node_s(ff->a, s, -1)));
	*po = x;
	return (res);
}
/**
 * _alias_me - Manages aliases in ff->a
 * @ff: A pointer to the ff_t structure
 * Return: Always 0
 */

int _alias_me(ff_t *ff)
{
	int ii = 0;
	char *po = NULL;
	ll_t *n = NULL;

	if (ff->argc == 1)
	{
		n = ff->a;
		while (n)
		{
			p_a(n);
			n = n->next;
		}
		return (0);
	}
	for (ii = 1; ff->argv[ii]; ii++)
	{
		po = _chme(ff->argv[ii], '=');
		if (po)
			s_alias_me(ff, ff->argv[ii]);
		else
			p_a(node_s(ff->a, ff->argv[ii], '='));
	}

	return (0);
}

/**
 * a_n_end - Adds a new node
 * to the end of the list
 * @h: A pointer to a pointer
 * to the head of the list
 * @uu: The string to be
 * stored in the new node
 * @numb: An integer to be
 * stored in the new node
 * Return: A pointer to the new
 * node or NULL on failure
 */
ll_t *a_n_end(ll_t **h, const char *uu, int numb)
{
	ll_t *new_n, *n;

	if (!h)
		return (NULL);

	n = *h;
	new_n = malloc(sizeof(ll_t));
	if (!new_n)
		return (NULL);
	_note((void *)new_n, 0, sizeof(ll_t));
	new_n->numb = numb;
	if (uu)
	{
		new_n->uu = _dupl(uu);
		if (!new_n->uu)
		{
			free(new_n);
			return (NULL);
		}
	}
	if (n)
	{
		while (n->next)
			n = n->next;
		n->next = new_n;
	}
	else
		*h = new_n;
	return (new_n);
}
