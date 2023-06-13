
#include "minirt.h"

/*
 * Print message error of parsing and duplicate scene
 */

bool	handle_error(int error)
{
	if (error == 1)
		printf("Wrong Number of arguments\n");
	else if (error == 2)
		printf("Maps can't be opened\n");
	else if (error == 3)
		printf("Maps is not a valid .rt\n");
	else if (error == 4)
		printf("Maps contain a duplicate of a scene\n");
	return (false);
}

/*
 * Print message of error malloc and will exit with 
 * code_error of 2
 */

void	handle_error_malloc(void)
{
	printf("Error of a malloc\n");
	exit(2);
}
