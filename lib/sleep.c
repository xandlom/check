#include "libcompat.h"

#if !HAVE_SLEEP

#if _MSC_VER
#include <windows.h> /* Sleep() */
#endif

unsigned int sleep (unsigned int seconds CK_ATTRIBUTE_UNUSED)
{
#if _MSC_VER
    DWORD millisecs = seconds * 1000;
    Sleep(millisecs);
#else
    assert (0);
#endif
    return 0;
}

#endif /* !HAVE_SLEEP */
