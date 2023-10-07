#include "main.h"

/**
 * _with - Checks if the string pointed to
 * by 'ptr1' starts with the substring
 * pointed to by 'ptr2'.
 * @ptr1: The string to search.
 * @ptr2: The substring to find.
 *
 * Return: A pointer to the next
 * character of 'ptr1' after the matching
 * substring or NULL if no match is found.
 */
char *_with(const char *ptr1, const char *ptr2)
{
	while (*ptr2)
	{
		if (*ptr2++ != *ptr1++)
		{
			return (NULL);
		}
	}
	return ((char *)ptr1);
}

/**
 * delete_n - Deletes a node
 * at a specified index
 * @h: A pointer to a
 * pointer to the head of the list
 * @in: The index of the node to be deleted
 * Return: 1 if the node is deleted, 0 otherwise
 */
int delete_n(ll_t **h, unsigned int in)
{
	ll_t *n, *p_n;
	unsigned int j = 0;

	if (!h || !*h)
		return (0);

	if (!in)
	{
		n = *h;
		*h = (*h)->next;
		free(n->uu);
		free(n);
		return (1);
	}
	n = *h;
	while (n)
	{
		if (j == in)
		{
			p_n->next = n->next;
			free(n->uu);
			free(n);
			return (1);
		}
		j++;
		p_n = n;
		n = n->next;
	}
	return (0);
}

/**
 * read_his - Read the history from a file
 * @ff: A pointer to a structure containing file information
 * Return: The number of history lines read or 0 on failure
 */
int read_his(ff_t *ff)
{
	int j, final = 0, linec = 0;
	ssize_t dd, rdl, rz = 0;
	struct stat st;
	char *buffer = NULL, *filen = g_h_f(ff);

	if (!filen)
		return (0);

	dd = open(filen, O_RDONLY);
	free(filen);
	if (dd == -1)
		return (0);
	if (!fstat(dd, &st))
		rz = st.st_size;
	if (rz < 2)
		return (0);
	buffer = malloc(sizeof(char) * (rz + 1));
	if (!buffer)
		return (0);
	rdl = read(dd, buffer, rz);
	buffer[rz] = 0;
	if (rdl <= 0)
		return (free(buffer), 0);
	close(dd);
	for (j = 0; j < rz; j++)
		if (buffer[j] == '\n')
		{
			buffer[j] = 0;
			b_h_l(ff, buffer + final, linec++);
			final = j + 1;
		}
	if (final != j)
		b_h_l(ff, buffer + final, linec++);
	free(buffer);
	ff->h_count = linec;
	while (ff->h_count-- >= H_M)
		delete_n(&(ff->h), 0);
	ren_his(ff);
	return (ff->h_count);
}

/**
 * _putsdd_me - Write a string to
 * the specified file descriptor.
 * @ptr: The string to write.
 * @dd: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */

int _putsdd_me(char *ptr, int dd)
{
	int ii = 0;

	if (!ptr)
		return (0);
	while (*ptr)
	{
		ii += _putdd_me(*ptr++, dd);
	}
	return (ii);
}

/**
 * b_h_l - Add a history line to
 * the linked list
 * @ff: A pointer to a structure
 * containing file information
 * @buffer: The history line to add
 * @linec: The line count
 * for the history entry
 * Return: 0 on success
 */
int b_h_l(ff_t *ff, char *buffer, int linec)
{
	ll_t *n = NULL;

	if (ff->h)
		n = ff->h;
	a_n_end(&n, buffer, linec);

	if (!ff->h)
		ff->h = n;
	return (0);
}
