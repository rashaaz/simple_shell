#include "main.h"

/**
 * fo_cmd_me - Forks and executes
 * external shell commands.
 * @ff: Pointer to an ff_t structure.
 */
void fo_cmd_me(ff_t *ff)
{
	pid_t ch_pid;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (ch_pid == 0)
	{
		if (execve(ff->p, ff->argv, g_envir_m(ff)) == -1)
		{
			fr_in_me(ff, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(ff->str));
		if (WIFEXITED(ff->str))
		{
			ff->str = WEXITSTATUS(ff->str);
			if (ff->str == 126)
				_error_print_me(ff, "Permission denied\n");
		}
	}
}
/**
 * _env_me - Display
 * the environment.
 * @ff: Pointer to an ff_t structure.
 *
 * Return: Always returns 0.
 */
int _env_me(ff_t *ff)
{
	print_l_s(ff->envnow);
	return (0);
}

/**
 * i_buffer - Reads input from the
 * user or a file into a buffer
 * @ff: A pointer to a structure
 * containing file information
 * @buffer: A pointer to a pointer to
 * the input buffer
 * @l: A pointer to the length of the buffer
 * Return: The number of characters
 * read or -1 on failure
 */

ssize_t i_buffer(ff_t *ff, char **buffer, size_t *l)
{
	ssize_t res = 0;
	size_t l_p = 0;

	if (!*l)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, _Handler);
#if USE_G
		res = getline(buffer, &l_p, stdin);
#else
		res = _getline_me(ff, buffer, &l_p);
#endif
		if (res > 0)
		{
			if ((*buffer)[res - 1] == '\n')
			{
				(*buffer)[res - 1] = '\0';
				res--;
			}
			ff->l_f = 1;
			_comment_me(*buffer);
			b_h_l(ff, *buffer, ff->h_count++);
			{
				*l = res;
				ff->c_b = buffer;
			}
		}
	}
	return (res);
}
/**
 * _date - Prints the value of ff->h
 * @ff: A pointer to the ff_t structure
 * Return: Always 0
 */

int _date(ff_t *ff)
{
	print_l(ff->h);
	return (0);
}
/**
 * is_del - Checks if a character is
 * in a given delimiter string.
 * @ch: The character to check.
 * @del: The delimiter string to search in.
 *
 * Return: 1 if the character is found
 * in the delimiter string, 0 otherwise.
 */

int is_del(char ch, char *del)
{
	while (*del)
		if (*del++ == ch)
			return (1);
	return (0);
}
