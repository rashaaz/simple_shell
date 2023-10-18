#include "main.h"

/**
 * is_alpha_me - Checks if a character
 * is alphabetic.
 * @ch: The character to check.
 *
 * Return: 1 if the character is
 * alphabetic (a letter), 0 otherwise.
 */

int is_alpha_me(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * g_h_f - Generate the full path to
 * the history file in the user's home directory
 * @ff: A pointer to a structure
 * containing file information
 * Return: A dynamically allocated string
 * containing the file path or NULL on failure
 */

char *g_h_f(ff_t *ff)
{
	char *buffer, *d;

	d = _genv_me(ff, "HOME=");
	if (!d)
		return (NULL);
	buffer = malloc(sizeof(char) * (_len(d) + _len(HI_FI) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_copy(buffer, d);
	_concat(buffer, "/");
	_concat(buffer, HI_FI);
	return (buffer);
}

/**
 * _comment_me - Remove
 * comments from a string.
 * @b: The input string.
 */
void _comment_me(char *b)
{
	int ii;

	for (ii = 0; b[ii] != '\0'; ii++)
		if (b[ii] == '#' && (!ii || b[ii - 1] == ' '))
		{
			b[ii] = '\0';
			break;
		}
}
/**
 * g_envir_m - Get the environment
 * variables as an array of strings.
 * @ff: Pointer to an ff_t structure.
 *
 * Return: An array of strings containing
 * environment variables.
 */
char **g_envir_m(ff_t *ff)
{
	if (!ff->environ || ff->r_env_ch)
	{
		ff->environ = l_t_s(ff->envnow);
		ff->r_env_ch = 0;
	}

	return (ff->environ);
}
/**
 * atoi_me - Converts a string
 * to an integer.
 * @str: The input string to convert.
 *
 * Return: The integer value of the string.
 */

int atoi_me(char *str)
{
	int ii, s = 1, f = 0, o;
	unsigned int r = 0;

	for (ii = 0;  str[ii] != '\0' && f != 2; ii++)
	{
		if (str[ii] == '-')
			s *= -1;

		if (str[ii] >= '0' && str[ii] <= '9')
		{
			f = 1;
			r *= 10;
			r += (str[ii] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (s == -1)
		o = -r;
	else
		o = r;

	return (o);
}
