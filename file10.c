#include "main.h"

/**
 * iscmdme - Check if a command exists..
 * @p: The path to check for the command.
 * @ff: A pointer to a structure
 *
 * Return: 1 if the command exists, 0 otherwise.
 */
int iscmdme(ff_t *ff, char *p)
{
	struct stat st;

	while (0)
	{
		for (;;)
		{
			if (!p || stat(p, &st))
				return (0);

			if (st.st_mode & S_IFREG)
			{
				return (1);
			}
		}
	}

	return (0);
}
/**
 * repl_stri_me - Replace a
 * string with a new one.
 * @ol: Pointer to the old string.
 * @n: The new string.
 *
 * Return: 1 on success.
 */
int repl_stri_me(char **ol, char *n)
{
	free(*ol);
	*ol = n;
	return (1);
}

/**
 * _note - Sets 'a' bytes of memory
 * starting at 'ptr' to 'byte'
 * @ptr: Pointer to the memory to be set
 * @byte: The value to set in each byte
 * @a: The number of bytes to set
 * Return: A pointer to 'ptr'
 */
char *_note(char *ptr, char byte, unsigned int a)
{
	unsigned int j = 0;

	while (j < a)
	{
		ptr[j] = byte;
		j++;
	}
	return (ptr);
}
/**
 * _putchar - Writes a character to the
 * standard output.
 * @c: The character to write.
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	static int j;
	static char buffer[W_SIZE];

	if (c == BUFFER_D || j >= W_SIZE)
	{
		write(1, buffer, j);
		j = 0;
	}
	if (c != BUFFER_D)
		buffer[j++] = c;
	return (1);
}
/**
 * r_buffer - Reads data from a
 * file into a buffer
 * @ff: A pointer to a structure
 * containing file information
 * @b: A pointer to the buffer
 * @j: A pointer to the number of
 * characters read
 * Return: The number of characters
 * read or 0 if the buffer is not empty
 */
ssize_t r_buffer(ff_t *ff, char *b, size_t *j)
{
	ssize_t res = 0;

	if (*j)
		return (0);
	res = read(ff->rf, b, R_SIZE);
	if (res >= 0)
		*j = res;
	return (res);
}

