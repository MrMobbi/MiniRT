
#include "minirt.h"

int main(int ac, char **av)
{
  if (check_arguments(ac, av) == false)
    return (1);
	printf("%zu\n", ft_strlen("coucou mathias"));
	return (0);
}
