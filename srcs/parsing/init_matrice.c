
#include "minirt.h"

/*
 * Create a matrice with all the value needed for to run
 * if no value is given should we all set at 0?
 */

t_matrice	*init_matrice(int fd)
{
	t_matrice	*matrice;
	int			code_error;

	code_error = 0;
	matrice = malloc(sizeof(t_matrice));
	if (!matrice)
		handle_error_malloc();
	matrice->a = false;
	matrice->c = false;
	matrice->l = false;
	matrice->duplicate = false;
	code_error = parsing(fd, matrice);
	if (code_error != 0)
	{
		handle_error(code_error);
		exit(1);
	}
	return (matrice);
}

/*
 * Will check the id of the line read to know in wich 
 * function and wich matrice attribute need to be done
 */

void	get_scene_attribute(char *id, char *line, t_matrice *matrice)
{
	if (ft_strncmp(id, AMBIENT, ft_strlen(id)) == 0)
		matrice->ambient = get_ambient_value(line, matrice);
	else if (ft_strncmp(id, LIGHT, ft_strlen(id)) == 0)
		matrice->light = get_light_value(line, matrice);
	else if (ft_strncmp(id, CAMERA, ft_strlen(id)) == 0)
		matrice->camera = get_camera_value(line, matrice);
	else if (ft_strncmp(id, PLANE, ft_strlen(id)) == 0)
		matrice->plane = get_plane_value(line);
	else if (ft_strncmp(id, SPHERE, ft_strlen(id)) == 0)
		matrice->sphere = get_sphere_value(line);
	else if (ft_strncmp(id, CYLINDER, ft_strlen(id)) == 0)
		matrice->cylinder = get_cylinder_value(line);
}

/*
 * Will check if there is a duplicate of the value
 * of certain scene
 */
bool	check_duplicate(int check, t_matrice *matrice)
{
	if (check == 1 && matrice->a == true)
		return (true);
	else if (check == 2 && matrice->c == true)
		return (true);
	else if (check == 3 && matrice->l == true)
		return (true);
	else
	{
		matrice->duplicate = true;
		return (false);
	}
}
