
#include "minirt.h"

/*
 * return 1 in case of wrong argument
 */

int	main(int ac, char **av)
{
	t_minirt	rt;

	printf("\n");
	if (check_arguments(ac, av, &rt) == false)
		return (1);
	free(rt.matrice);
	return (0);
}
