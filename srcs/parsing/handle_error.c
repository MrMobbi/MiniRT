
#include "minirt.h"

bool  handle_error(int error)
{
  if (error == 1)
    printf("Wrong Number of arguments\n");
  return (false);
}
