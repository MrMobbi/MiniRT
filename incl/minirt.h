
#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# include "../libs/libmlx/mlx.h"
# include "../libs/libft/libft.h"
# include "../libs/gnl/get_next_line.h"
# include "struct.h"
# include "define.h"

//###########################################//
//		===== PARSING DIRECTORY =====
//###########################################//
//
//	----- Check_Arguments.c -----
bool		check_arguments(int ac, char **av, t_minirt *rt);

//	----- Handle_Error.c -----
bool		handle_error(int error);
void		handle_error_malloc(void);

//	----- Init_Matrice.c -----
t_matrice	*init_matrice(int fd);
void		get_scene_attribute(char *id, char *line, t_matrice *matrice);
bool		check_duplicate(int check, t_matrice *matrice);

//	----- Light_Attribute.c -----
t_l			*get_light_value(char *line, t_matrice *matrice);
t_al		*get_ambient_value(char *line, t_matrice *matrice);

//	----- Object_Attribute.c -----
t_list_cy	*get_cylinder_value(char *line);
t_list_sp	*get_sphere_value(char *line);

//	----- Parsing.c -----
int			parsing(int fd, t_matrice *matrice);

//	----- Scene_Attribute.c -----
t_pl		*get_plane_value(char *line);
t_c			*get_camera_value(char *line, t_matrice *matrice);

#endif
