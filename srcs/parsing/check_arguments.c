
#include "minirt.h"

/*
 * Will check if the file has been opened
 */

static bool	is_map_open(int fd)
{
	if (fd == -1)
	{
		close (fd);
		return (false);
	}
	else
		return (true);
}

/*
 * Will check if the file finish by a ".rt"
 */

static bool	is_file_rt(char *str)
{
	if (ft_strlen(str) < 4)
		return (false);
	if (ft_strncmp(&str[ft_strlen(str) - 3], ".rt", 3) == 0)
		return (true);
	return (false);
}

/*
 * TRUE arguments are valid
 * FALSE arguments are not valid
 */

bool	check_arguments(int ac, char **av, t_minirt *rt)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (ac != 2)
		return (handle_error(1));
	if (is_map_open(fd) == false)
		return (handle_error(2));
	if (is_file_rt(av[1]) == false)
		return (handle_error(3));
	rt->matrice = init_matrice(fd);
	return (true);
}
