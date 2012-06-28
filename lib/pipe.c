#include "libcompat.h"

#if !HAVE_PIPE && !HAVE__PIPE

int
pipe (int *fildes CK_ATTRIBUTE_UNUSED)
{
  assert (0);
  return 0;
}

#endif /* !HAVE_PIPE && !HAVE__PIPE */
