#include "main.h"

/**
 * main - Entry point of the program
 * @ac: The number of command-line arguments
 * @av: An array of command-line arguments
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */

int main(int ac, char **av)
{
	ff_t ff[] = { INF_IN };
	int dd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (dd)
			: "r" (dd));

	if (ac == 2)
	{
		dd = open(av[1], O_RDONLY);
		if (dd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_aputs_me(av[0]);
				_aputs_me(": 0: Can't open ");
				_aputs_me(av[1]);
				_aputchar_me('\n');
				_aputchar_me(BUFFER_D);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		ff->rf = dd;
	}
	p_env_l(ff);
	read_his(ff);
	hs_me(ff, av);
	return (EXIT_SUCCESS);
}
