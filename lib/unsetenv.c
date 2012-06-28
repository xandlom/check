#include "libcompat.h"

<<<<<<< HEAD
void
unsetenv (const char *name CK_ATTRIBUTE_UNUSED)
{
  assert (0);
}
=======
#if !HAVE_UNSETENV

void unsetenv (const char *name CK_ATTRIBUTE_UNUSED)
{
    assert (0);
}

#endif /* !HAVE_UNSETENV */
>>>>>>> 5790d291e1ba3510a032cbab7efa25651f15376f
