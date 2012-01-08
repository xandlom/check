#include "libcompat.h"

#if !HAVE_SETENV

int setenv (const char *name CK_ATTRIBUTE_UNUSED, const char *value CK_ATTRIBUTE_UNUSED, int overwrite CK_ATTRIBUTE_UNUSED)
{
    assert (0);
    return 0;
}

#endif /* !HAVE_SETENV */
