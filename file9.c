#include "main.h"

/**
 * fi_bui_me - Executes
 * built-in shell commands.
 * @ff: Pointer to an ff_t structure.
 *
 * Return: Returns the status
 * code of the executed command.
 */
int fi_bui_me(ff_t *ff)
{
	int ii, b_in_ret = -1;
	bb_table bui[] = {
		{"exit", _exit_me},
		{"env", _env_me},
		{"help", _help_me},
		{"history", _date},
		{"setenv", _mysetenv_me},
		{"unsetenv", _myunsetenv_me},
		{"cd", _cd_me},
		{"alias", _alias_me},
		{NULL, NULL}
	};

	for (ii = 0; bui[ii].ty; ii++)
		if (_comp(ff->argv[0], bui[ii].ty) == 0)
		{
			ff->co++;
			b_in_ret = bui[ii].func(ff);
			break;
		}
	return (b_in_ret);
}
/**
 * _input_me - Reads input from the
 * user or a file and processes it
 * @ff: A pointer to a structure
 * containing file information
 * Return: The number of characters
 * processed or -1 on failure
 */

ssize_t _input_me(ff_t *ff)
{
	static char *buffer;
	static size_t ii, jj, l;
	ssize_t re = 0;
	char **_p = &(ff->arg), *po;

	_putchar(BUFFER_D);
	re = i_buffer(ff, &buffer, &l);
	if (re == -1)
		return (-1);
	if (l)
	{
		jj = ii;
		po = buffer + ii;

		chec_cha_me(ff, buffer, &jj, ii, l);
		while (jj < l)
		{
			if (is_ch_me(ff, buffer, &jj))
				break;
			jj++;
		}

		ii = jj + 1;
		if (ii >= l)
		{
			ii = l = 0;
			ff->c_b_t = CMD_N;
		}

		*_p = po;
		return (_len(po));
	}

	*_p = buffer;
	return (re);
}
/**
 * p_a - Prints an alias
 * @n: A pointer to the ll_t structure
 * Return: Always 0
 */

int p_a(ll_t *n)
{
	char *po = NULL, *ar = NULL;

	if (n)
	{
		po = _chme(n->uu, '=');
		for (ar = n->uu; ar <= po; ar++)
			_putchar(*ar);
		_putchar('\'');
		print_many_characters(po + 1);
		print_many_characters("'\n");
		return (0);
	}
	return (1);
}
/**
 * _concatn - Concatenates up to 'num'
 * characters from 'so' to 'd'.
 * @d: Destination buffer.
 * @so: Source string.
 * @num: Maximum number of
 * characters to concatenate.
 *
 * Return: Pointer to the destination buffer 'd'.
 */

char *_concatn(char *d, char *so, int num)
{
	int ii, jj;
	char *c = d;

	ii = 0;
	jj = 0;
	while (d[ii] != '\0')
		ii++;
	while (so[jj] != '\0' && jj < num)
	{
		d[ii] = so[jj];
		ii++;
		jj++;
	}
	if (jj < num)
		d[ii] = '\0';
	return (c);
}

/**
 * w_his - Write the history to a file
 * @ff: A pointer to a structure
 * containing file information
 * Return: 1 on success, -1 on failure
 */

int w_his(ff_t *ff)
{
	ssize_t dd;
	char *filen = g_h_f(ff);
	ll_t *n = NULL;

	if (!filen)
		return (-1);

	dd = open(filen, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filen);
	if (dd == -1)
		return (-1);
	for (n = ff->h; n; n = n->next)
	{
		_putsdd_me(n->uu, dd);
		_putdd_me('\n', dd);
	}
	_putdd_me(BUFFER_D, dd);
	close(dd);
	return (1);
}
