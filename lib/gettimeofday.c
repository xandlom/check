#include "libcompat.h"

#if !HAVE_GETTIMEOFDAY

#if _MSC_VER

#if defined(_MSC_VER) || defined(__BORLANDC__)
#define EPOCHFILETIME (116444736000000000i64)
#else
#define EPOCHFILETIME (116444736000000000LL)
#endif

int gettimeofday (struct timeval *tv, void* tz)
{
    union {
        __int64 ns100; /*time since 1 Jan 1601 in 100ns units */
        FILETIME ft;
    } now;

    GetSystemTimeAsFileTime (&now.ft);
    tv->tv_usec = (long) ((now.ns100 / 10LL) % 1000000LL);
    tv->tv_sec = (long) ((now.ns100 - EPOCHFILETIME) / 10000000LL);
    return (0);
}

#endif /* _MSC_VER */

#endif /* !HAVE_GETTIMEOFDAY */
