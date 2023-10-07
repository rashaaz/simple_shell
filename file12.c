#include "main.h"

/**
 * _chme - Searches for the first
 * occurrence of character 'c' in 'str'.
 * @str: Input string to search.
 * @c: Character to find.
 *
 * Return: Pointer to the first occurrence
 * of 'c' in 'str', or NULL if not found.
 */
char *_chme(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
/**
 * l_l - Calculates the length
 * of a linked list
 * @hh: A pointer to the
 * head of the linked list
 * Return: The length of
 * the linked list
 */
size_t l_l(const ll_t *hh)
{
	size_t j = 0;

	while (hh)
	{
		hh = hh->next;
		j++;
	}
	return (j);
}

/**
 * _getline_me - Reads a line of input from
 * a file or user input into a buffer
 * @ff: A pointer to a structure
 * containing file information
 * @ptr: A pointer to a pointer to the input buffer
 * @lg: A pointer to the length of the buffer
 * Return: The number of characters
 * read or -1 on failure
 */
int _getline_me(ff_t *ff, char **ptr, size_t *lg)
{
	static char buffer[R_SIZE];
	static size_t j, l;
	size_t x;
	ssize_t re = 0, st = 0;
	char *po = NULL, *n_p_r = NULL, *c;

	po = *ptr;
	if (po && lg)
		st = *lg;
	if (j == l)
		j = l = 0;

	re = r_buffer(ff, buffer, &l);
	if (re == -1 || (re == 0 && l == 0))
		return (-1);

	c = _chme(buffer + j, '\n');
	x = c ? 1 + (unsigned int)(c - buffer) : l;
	n_p_r = _realloc_me(po, st, st ? st + x : x + 1);
	if (!n_p_r)
		return (po ? free(po), -1 : -1);

	if (st)
		_concatn(n_p_r, buffer + j, x - j);
	else
		_copyn(n_p_r, buffer + j, x - j + 1);

	st += x - j;
	j = x;
	po = n_p_r;

	if (lg)
		*lg = st;
	*ptr = po;
	return (st);
}
/**
 * _convert - Convert a number to
 * a string representation.
 * @dgit: The number to convert.
 * @b: The base of the conversion.
 * @fla: Conversion flags.
 *
 * Return: The string representation of the number.
 */
char *_convert(long int dgit, int b, int fla)
{
	static char *arr;
	static char buf[50];
	char sn = 0;
	char *ptr;
	unsigned long a = dgit;

	if (!(fla & CONVERT_UN) && dgit < 0)
	{
		a = -dgit;
		sn = '-';

	}
	arr = fla & CONVERT_LOW ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buf[49];
	*ptr = '\0';

	do	{
		*--ptr = arr[a % b];
		a /= b;
	} while (a != 0);

	if (sn)
		*--ptr = sn;
	return (ptr);
}
/**
 * is_ch_me - Check for command
 * chaining symbols.
 * @ff: Pointer to an ff_t structure.
 * @bufer: The input buffer.
 * @pp: Pointer to the current
 * position in the buffer.
 *
 * Return: 1 if a command chaining
 * symbol is found, 0 otherwise.
 */
int is_ch_me(ff_t *ff, char *bufer, size_t *pp)
{
	size_t jj = *pp;

	switch (bufer[jj])
	{
		case '|':
			if (bufer[jj + 1] == '|')
			{
				bufer[jj] = 0;
				jj++;
				ff->c_b_t = C_R;
			}
			else
			{
				return (0);
			}
			break;

		case '&':
			if (bufer[jj + 1] == '&')
			{
				bufer[jj] = 0;
				jj++;
				ff->c_b_t = CMD_D;
			} else
			{
				return (0);
			}
			break;

		case ';':
			bufer[jj] = 0;
			ff->c_b_t = C_CHA;
			break;

		default:
			return (0);
	}

	*pp = jj;
	return (1);
}
