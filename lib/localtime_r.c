#include "libcompat.h"

#if !HAVE_LOCALTIME_R

struct tm *localtime_r (const time_t *clock, struct tm *result)
{
    struct tm * now = NULL;
#if HAVE_LOCALTIME_S
    localtime_s (now, clock)
#elif HAVE__LOCALTIME64_S
    _localtime64_s (now, clock);
#else
    now = localtime (clock);
#endif /* !HAVE_LOCALTIME_S */

    if (now == NULL)
    {
        return NULL;
    }
    else
    {
        *result = *now;
    }
    return result;
}

#endif /* !HAVE_LOCALTIME_R */
