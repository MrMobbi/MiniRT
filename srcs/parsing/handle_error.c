
#include "minirt.h"

bool	handle_error(int error)
{
	if (error == 1)
		printf("Wrong Number of arguments\n");
	else if (error == 2)
		printf("Maps can't be opened\n");
	else if (error == 3)
		printf("Maps is not a .rt\n");
	return (false);
}
