
#include "minirt.h"

bool  check_arguments(int ac, char **av)
{
  (void) av;
  if (ac != 2)
    return (handle_error(1));

  return (true);
}
