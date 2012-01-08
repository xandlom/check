#include "libcompat.h"

#if !HAVE_FILENO && !HAVE__FILENO

int fileno(FILE *stream CK_ATTRIBUTE_UNUSED)
{
    assert (0);
    return 0;
}

#endif /* !HAVE__FILENO && !HAVE__FILENO */
