#include "libcompat.h"

#if !HAVE_PUTENV && !HAVE__PUTENV

int
putenv (const char *string CK_ATTRIBUTE_UNUSED);
{
  assert (0);
  return 0;
}

#endif /* HAVE_PUTENV */
