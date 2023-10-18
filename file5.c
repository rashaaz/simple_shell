#include "main.h"

/**
 * _exit_me - Handles the exit command.
 * @ff: The structure containing function
 *
 * This function checks if an
 * argument is provided in
 * inter->argv[1]. If an argument is present,
 * it attempts to convert it to an
 * integer using _my_erratoi.
 * If the conversion fails, it sets
 * inter->status to 2, prints an error message
 * indicating an illegal number, and returns 1.
 * If the conversion is successful, it stores the
 * converted integer in inter->_number_err and
 * returns -2, indicating the program
 * should exit with
 * the specified exit code. If no
 * argument
 * is provided, it sets
 * inter->_number_err
 * to -1 and returns -2.
 *
 * Return: 1 on error, -2 on
 * successful exit.
 */
int _exit_me(ff_t *ff)
{
	int check;

	if (ff->argv[1])
	{
		check = _my_erratoi(ff->argv[1]);
		if (check == -1)
		{
			ff->str = 2;
			_error_print_me(ff, "Illegal number: ");
			_aputs_me(ff->argv[1]);
			_aputchar_me('\n');
			return (1);
		}
		ff->_number_err = _my_erratoi(ff->argv[1]);
		return (-2);
	}
	ff->_number_err = -1;
	return (-2);
}
/**
 * chec_cha_me - Check and handle
 * command chaining.
 * @ff: Pointer to an ff_t structure.
 * @bufer: The input buffer.
 * @pp: Pointer to the current
 * position in the buffer.
 * @ii: Current index in the buffer.
 * @le: Length of the buffer.
 */
void chec_cha_me(ff_t *ff, char *bufer, size_t *pp, size_t ii, size_t le)
{
	size_t jj = *pp;

	if (ff->c_b_t == CMD_D)
	{
		if (ff->str)
		{
			bufer[ii] = 0;
			jj = le;
		}
	}
	if (ff->c_b_t == C_R)
	{
		if (!ff->str)
		{
			bufer[ii] = 0;
			jj = le;
		}
	}

	*pp = jj;
}

/**
 * hs_me - Main shell function for
 * reading and executing commands.
 * @ff: Pointer to an ff_t structure.
 * @av: Array of command-line arguments.
 *
 * Return: Returns the status code of
 * the last executed command.
 */
int hs_me(ff_t *ff, char **av)
{
	ssize_t rr = 0;
	int b_ret = 0;

	while (rr != -1 && b_ret != -2)
	{
		cl_in_me(ff);
		if (reactive(ff))
			print_many_characters("$ ");
		_aputchar_me(BUFFER_D);
		rr = _input_me(ff);
		if (rr != -1)
		{
			st_in_me(ff, av);
			b_ret = fi_bui_me(ff);
			if (b_ret == -1)
				fi_cmd_me(ff);
		}
		else if (reactive(ff))
			_putchar('\n');
		fr_in_me(ff, 0);
	}
	w_his(ff);
	fr_in_me(ff, 1);
	if (!reactive(ff) && ff->str)
		exit(ff->str);
	if (b_ret == -2)
	{
		if (ff->_number_err == -1)
			exit(ff->str);
		exit(ff->_number_err);
	}
	return (b_ret);
}
/**
 * cl_in_me - Clear the input
 * variables in the ff_t structure.
 * @ff: Pointer to an ff_t structure.
 */
void cl_in_me(ff_t *ff)
{
	ff->arg = NULL;
	ff->argv = NULL;
	ff->p = NULL;
	ff->argc = 0;
}
/**
 * _concat - Concatenates two strings.
 * @destination: The destination buffer.
 * @source: The source buffer.
 *
 * Return: A pointer to the 'destination'
 * buffer, which now contains the
 * concatenated string.
 */
char *_concat(char *destination, char *source)
{
	char *res = destination;

	while (*destination)
	{
		destination++;
	}
	while (*source)
	{
		*destination++ = *source++;
	}
	*destination = *source;
	return (res);
}
