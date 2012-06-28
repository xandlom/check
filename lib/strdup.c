#include "libcompat.h"

#if !HAVE_STRDUP && !HAVE__STRDUP

char *
strdup (const char *str CK_ATTRIBUTE_UNUSED)
{
  assert (0);
  return NULL;
}

#endif /* #if !HAVE_STRDUP && !HAVE__STRDUP */
