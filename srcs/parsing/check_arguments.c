
#include "minirt.h"

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

static bool is_file_rt(char *str)
{
  while (*str != '\0')
  {
     if (ft_strncmp(str, ".rt", ft_strlen(str)) == 0)
      return (true);
    str++;
  }
  return (false);
}

bool  check_arguments(int ac, char **av, t_minirt *rt)
{
  int fd;
  int code_error;

  fd = open(av[1], O_RDONLY);
  code_error = 0;
  if (ac != 2)
    return (handle_error(1));
  if (is_map_open(fd) == false)
    return (handle_error(2));
  if (is_file_rt(av[1]) == false)
   return (handle_error(3));
  code_error = parsing(fd, rt);
  if (code_error != 0)
    return (handle_error(code_error));
  return (true);
}
