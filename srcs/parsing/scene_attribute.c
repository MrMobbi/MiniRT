
#include "minirt.h"

/*
 * Will get the value fot the camera
 * if there is alredy one it will set the duplicate to true and exit
 */

t_c	*get_camera_value(char *line, t_matrice *matrice)
{
	t_c	*camera;
	(void) line;
	if (check_duplicate(2, matrice) == true)
	{
		free(matrice->camera);
		return (NULL);
	}
	matrice->c = true;
	camera = malloc(sizeof(t_c));
	if (!camera)
		handle_error_malloc();
	printf("camera\n");
	return (camera);
}

t_pl	*get_plane_value(char *line)
{
	(void) line;
	printf("plane\n");
	return (NULL);
}
