#include "main.h"

/**
 * p_env_l - Populate the environment linked list.
 * @ff: Pointer to an ff_t structure.
 *
 * Return: Always returns 0.
 */
int p_env_l(ff_t *ff)
{
	ll_t *n = NULL;
	size_t ii;

	for (ii = 0; environ[ii]; ii++)
		a_n_end(&n, environ[ii], 0);
	ff->envnow = n;
	return (0);
}
