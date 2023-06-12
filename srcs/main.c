
#include "minirt.h"

int	main(int ac, char **av)
{
	t_minirt	rt;

	if (check_arguments(ac, av, &rt) == false)
		return (1);
	printf("%zu\n", ft_strlen("coucou mathias"));
	return (0);
}
