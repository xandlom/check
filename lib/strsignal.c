#include "libcompat.h"

#if !HAVE_STRSIGNAL

const char *
strsignal (int sig)
{
  static char signame[40];
  sprintf(signame, "SIG #%d", sig);
  return signame;
}

#endif /* !HAVE_STRSIGNAL */
