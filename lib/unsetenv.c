#include "libcompat.h"

#if !HAVE_UNSETENV

void unsetenv (const char *name CK_ATTRIBUTE_UNUSED)
{
    assert (0);
}

#endif /* !HAVE_UNSETENV */
