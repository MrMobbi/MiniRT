
#include "minirt.h"

/*
 * Will get the value fot the ambient light
 * if there is alredy one it will set the duplicate to true and exit
 */

t_al	*get_ambient_value(char *line, t_matrice *matrice)
{
	(void) line;
	t_al	*ambient;
	if (check_duplicate(1, matrice) == true)
	{
		free(matrice->ambient);
		return (NULL);
	}
	matrice->a = true;
	ambient = malloc(sizeof(t_al));
	if (!ambient)
		handle_error_malloc();
	printf("ambient\n");
	return (NULL);
}

/*
 * Will get the value fot the light
 * if there is alredy one it will set the duplicate to true and exit
 */

t_l	*get_light_value(char *line, t_matrice *matrice)
{
	(void) line;
	t_l	*light;
	if (check_duplicate(3, matrice) == true)
	{
		free(matrice->light);
		return (NULL);
	}
	matrice->l = true;
	light = malloc(sizeof(t_l));
	if (!light)
		handle_error_malloc();
	printf("light\n");
	return (NULL);
}
