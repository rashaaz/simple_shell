#include "main.h"
/**
 * print_l_s - Prints the list
 * @hh: A pointer to the head of the list
 * Return: The number of nodes in the list
 */

size_t print_l_s(const ll_t *hh)
{
	size_t j = 0;

	while (hh)
	{
		print_many_characters(hh->uu ? hh->uu : "(nil)");
		print_many_characters("\n");
		hh = hh->next;
		j++;
	}
	return (j);
}

/**
 * ren_his - Renumber the
 * history entries
 * @ff: A pointer to a structure
 * containing file information
 * Return: The updated history entry count
 */

int ren_his(ff_t *ff)
{
	ll_t *n = ff->h;
	int j = 0;

	while (n)
	{
		n->numb = j++;
		n = n->next;
	}
	return (ff->h_count = j);
}

/**
 * reactive - Checks if the file descriptor
 * is associated with a terminal.
 * @ff: File flag structure.
 *
 * Return: 1 if the file descriptor
 * is associated with a terminal, 0 otherwise.
 */
int reactive(ff_t *ff)
{
	return (isatty(STDIN_FILENO) && ff->rf <= 2);
}

/**
 * _cd_me - Handles the cd
 * (change directory) command.
 * @ff: The structure containing function
 * arguments and environment variables
 *
 * This function attempts to
 * retrieve the current
 * working directory using getcwd and stores it
 * in the b buffer. If getcwd fails, it prints
 * a placeholder error message. If there is no
 * argument in inter->argv[1], it checks
 * if the "HOME" environment
 * variable exists (using
 * _genv_me) and attempts to change the current
 * directory to the value of
 * "HOME" or "PWD" if
 * "HOME" is not found. If the argument is
 * "-", it attempts to change
 * the directory to the
 * previous working directory,
 * which is stored in the
 * "OLDPWD" environment
 * variable. Otherwise,
 * it tries to change the
 * directory to the provided argument.
 * If changing the directory fails,
 * it prints an error message
 * indicating the failure.
 * If the directory change is
 * successful, it
 * updates the "OLDPWD" and
 * "PWD" environment variables
 * and returns 0.
 *
 * Return: 0 on success, 1 on error.
 */
int _cd_me(ff_t *ff)
{
	char *ss, *ptr, b[1024];
	int ch;

	ss = getcwd(b, 1024);
	if (!ss)
		print_many_characters("TODO: >>getcwd failure emsg here<<\n");
	if (!ff->argv[1])
	{
		ptr = _genv_me(ff, "HOME=");
		if (!ptr)
			ch = /* TODO: what is this ? */
			chdir((ptr = _genv_me(ff, "PWD=")) ? ptr : "/");
		else
			ch = chdir(ptr);
	}
	else if (_comp(ff->argv[1], "-") == 0)
	{
		if (!_genv_me(ff, "OLDPWD="))
		{
			print_many_characters(ss);
			_putchar('\n');
			return (1);
		}
		print_many_characters(_genv_me(ff, "OLDPWD=")), _putchar('\n');
		ch = /* TODO: what is this? */
		chdir((ptr = _genv_me(ff, "OLDPWD=")) ? ptr : "/");
	}
	else
		ch = chdir(ff->argv[1]);
	if (ch == -1)
	{
		_error_print_me(ff, "can't cd to ");
		_aputs_me(ff->argv[1]), _aputchar_me('\n');
	}
	else
	{
		_senv_me(ff, "OLDPWD", _genv_me(ff, "PWD="));
		_senv_me(ff, "PWD", getcwd(b, 1024));
	}
	return (0);
}

/**
 * fr_in_me - Free input-related
 * memory in the ff_t structure.
 * @ff: Pointer to an ff_t structure.
 * @a: An integer indicating whether
 * to perform additional freeing.
 */
void fr_in_me(ff_t *ff, int a)
{
	rfree_me(ff->argv);
	ff->argv = NULL;
	ff->p = NULL;
	if (a)
	{
		if (!ff->c_b)
			free(ff->arg);
		if (ff->envnow)
			free_l(&(ff->envnow));
		if (ff->h)
			free_l(&(ff->h));
		if (ff->a)
			free_l(&(ff->a));
		rfree_me(ff->environ);
		ff->environ = NULL;
		buffer_free_me((void **)ff->c_b);
		if (ff->rf > 2)
			close(ff->rf);
		_putchar(BUFFER_D);
	}
}
