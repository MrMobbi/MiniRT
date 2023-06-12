
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
//		----- Check_Arguments.c -----
bool	check_arguments(int ac, char **av, t_minirt *rt);

//    ----- Handle_Error.c -----
bool	handle_error(int error);

//    ----- Parsing.c -----
int		parsing(int fd, t_minirt *rt);

#endif
