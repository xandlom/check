#ifndef LIBCOMPAT_H
#define LIBCOMPAT_H

#if HAVE_CONFIG_H
#include <config.h>
#endif

#if defined(__GNUC__) && defined(__GNUC_MINOR__)
#define GCC_VERSION_AT_LEAST(major, minor) \
((__GNUC__ > (major)) || \
 (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
#else
#define GCC_VERSION_AT_LEAST(major, minor) 0
#endif

#if GCC_VERSION_AT_LEAST(2,95)
#define CK_ATTRIBUTE_UNUSED __attribute__ ((unused))
#else
#define CK_ATTRIBUTE_UNUSED              
#endif /* GCC 2.95 */

#if _MSC_VER
#include <WinSock2.h> /* struct timeval, API used in gettimeofday implementation */
#include <io.h> /* read, write */
#include <process.h> /* getpid */
#endif /* _MSC_VER */

/* defines size_t */
#include <sys/types.h>

/* provides assert */
#include <assert.h>

/* defines FILE */
#include <stdio.h>

/* provides localtime and struct tm */
#ifdef HAVE_SYS_TIME_H
#include <sys/time.h>
#endif /* !HAVE_SYS_TIME_H */
#include <time.h>

/* declares fork(), _POSIX_VERSION.  according to Autoconf.info,
   unistd.h defines _POSIX_VERSION if the system is POSIX-compliant,
   so we will use this as a test for all things uniquely provided by
   POSIX like sigaction() and fork() */
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

/* declares pthread_create and friends */
#ifdef HAVE_PTHREAD
#include <pthread.h>
#endif

/* replacement functions for broken originals */
#if !HAVE_MALLOC
void *rpl_malloc (size_t n);
#endif /* !HAVE_MALLOC */

#if !HAVE_REALLOC
void *rpl_realloc (void *p, size_t n);
#endif /* !HAVE_REALLOC */

/* functions that may be undeclared */
#if !HAVE_FILENO && !HAVE__FILENO
int fileno (FILE *stream);
#elif !HAVE_FILENO && HAVE__FILENO
#define fileno _fileno;
#endif /* !HAVE_FILENO && HAVE__FILENO */

#if !HAVE_GETPID && HAVE__GETPID
#define getpid _getpid;
#endif /* !HAVE_GETPID && HAVE__GETPID */

#if !HAVE_GETTIMEOFDAY
int gettimeofday (struct timeval *tv, void* tz);
#endif /* !HAVE_LOCALTIME_R */

#if !HAVE_LOCALTIME_R
struct tm *localtime_r (const time_t *clock, struct tm *result);
#endif /* !HAVE_LOCALTIME_R */

#if !HAVE_PIPE && !HAVE__PIPE
int pipe (int *fildes);
#elif !HAVE_PIPE && HAVE__PIPE
#define pipe _pipe;
#endif /* !HAVE_PIPE && HAVE__PIPE */

#if !HAVE_PUTENV && !HAVE__PUTENV
int putenv (const char *string);
#elif !HAVE_PUTENV && HAVE__PUTENV
#define putenv _putenv;
#endif /* HAVE__PUTENV && !HAVE_FILENO */

#if !HAVE_READ && HAVE__READ
#define read _read
#endif /* !HAVE_READ && HAVE__READ */

#if !HAVE_SETENV
int setenv (const char *name, const char *value, int overwrite);
#endif /* !HAVE_SETENV */

/* our setenv implementation is currently broken */
#if !HAVE_SETENV
#define HAVE_WORKING_SETENV 0
#else
#define HAVE_WORKING_SETENV 1
#endif

#if !HAVE_SLEEP
unsigned int sleep (unsigned int seconds);
#endif /* !HAVE_SLEEP */

#if !HAVE_STRDUP && !HAVE__STRDUP
char *strdup (const char *str);
#elif !HAVE_STRDUP && HAVE__STRDUP
#define strdup _strdup;
#endif /* !HAVE_STRDUP && HAVE__STRDUP */

#if !HAVE_SNPRINTF && HAVE__SNPRINTF
#define snprintf _snprintf
#endif /* !HAVE_STRDUP && HAVE__STRDUP */

#if !HAVE_STRSIGNAL
const char *strsignal (int sig);
#endif /* !HAVE_STRSIGNAL */

#if !HAVE_UNSETENV
void unsetenv (const char *name);
#endif /* !HAVE_UNSETENV */

#if !HAVE_WRITE && HAVE_WRITE
#define write _write
#endif /* !HAVE_WRITE && HAVE__WRITE */

/* silence warnings about an empty library */
void ck_do_nothing (void);

#endif /* !LIBCOMPAT_H */
