
#include "minirt.h"

/*
 * Will get the id of the line
 */

static char	*get_id(char *str)
{
	char	*id;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[i] != '\0' && ft_isalpha(str[i]) == 1)
	{
		len++;
		i++;
	}
	i = 0;
	id = ft_calloc(sizeof(char), len + 1);
	if (!id)
		handle_error_malloc();
	while (str[i] != '\0' && ft_isalpha(str[i]) == 1)
	{
		id[i] = str[i];
		i++;
	}
	return (id);
}

/*
 * Will get the id and send it further to get 
 * the value of the line
 */
static void	attribute_value(char *line, t_matrice *matrice)
{
	int		i;
	char	*id;

	(void) matrice;
	i = 0;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	id = get_id(&line[i]);
	printf("%s", &line[i]);
	printf("[%s] <- id\n", id);
	get_scene_attribute(id, line, matrice);
	free(id);
}

int	parsing(int fd, t_matrice *matrice)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		attribute_value(line, matrice);
		if (matrice->duplicate == true)
		{
			free(line);
			return (4);
		}
		free(line);
	}
	return (0);
}
