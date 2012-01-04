#
# Check: a unit test framework for C
#
# Copyright (C) 2011 Mateusz Loskot
# Copyright (C) 2001, 2002 Arien Malec
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the
# Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.
#
project(check C)

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# TODO: extract from configure.ac
set(CHECK_MAJOR_VERSION 0)
set(CHECK_MINOR_VERSION 9)
set(CHECK_MICRO_VERSION 6)

set(CHECK_VERSION
  "${CHECK_MAJOR_VERSION}.${CHECK_MINOR_VERSION}.${CHECK_MICRO_VERSION}")

###############################################################################
# Set build features
set(CMAKE_BUILD_TYPE Debug)

set(TIMEOUT_TESTS_ENABLED 0)

###############################################################################
# Check system and architecture
if(WIN32)
  if(MSVC60)
    set(WINVER 0x0400)
  else()
    set(WINVER 0x0500)
  endif()
  set(_WIN32_WINNT ${WINVER})
endif(WIN32)

if(MSVC)
  add_definitions(-D_CRT_SECURE_NO_DEPRECATE)
endif(MSVC)

###############################################################################
include(CheckCSourceCompiles)
include(CheckCSourceRuns)
include(CheckFunctionExists)
include(CheckIncludeFile)
include(CheckIncludeFiles)
include(CheckLibraryExists)
include(CheckStructMember)
include(CheckSymbolExists)
include(CheckTypeExists)
include(CheckTypeSize)

###############################################################################
# Check headers
SET(INCLUDES "")
macro(ck_check_include_file header var)
  check_include_files("${INCLUDES};${header}" ${var})
  if(${var})
    set(INCLUDES ${INCLUDES} ${header})
  endif(${var})
endmacro(ck_check_include_file)

# Some FreeBSD headers assume sys/types.h was already included.
ck_check_include_file("sys/types.h" HAVE_SYS_TYPES_H)

# Alphabetize the rest unless there's a compelling reason
ck_check_include_file("ctype.h" HAVE_CTYPE_H)
ck_check_include_file("copyfile.h" HAVE_COPYFILE_H)
ck_check_include_file("direct.h" HAVE_DIRECT_H)
ck_check_include_file("dlfcn.h" HAVE_DLFCN_H)
ck_check_include_file("errno.h" HAVE_ERRNO_H)
ck_check_include_file("inttypes.h" HAVE_INTTYPES_H)
ck_check_include_file("io.h" HAVE_IO_H)
ck_check_include_file("limits.h" HAVE_LIMITS_H)
ck_check_include_file("locale.h" HAVE_LOCALE_H)
ck_check_include_file("memory.h" HAVE_MEMORY_H)
ck_check_include_file("poll.h" HAVE_POLL_H)
ck_check_include_file("process.h" HAVE_PROCESS_H)
ck_check_include_file("signal.h" HAVE_SIGNAL_H)
ck_check_include_file("stdarg.h" HAVE_STDARG_H)
ck_check_include_file("stdint.h" HAVE_STDINT_H)
ck_check_include_file("stdlib.h" HAVE_STDLIB_H)
ck_check_include_file("string.h" HAVE_STRING_H)
ck_check_include_file("strings.h" HAVE_STRINGS_H)
ck_check_include_file("sys/cdefs.h" HAVE_SYS_CDEFS_H)
ck_check_include_file("sys/poll.h" HAVE_SYS_POLL_H)
ck_check_include_file("sys/select.h" HAVE_SYS_SELECT_H)
ck_check_include_file("sys/stat.h" HAVE_SYS_STAT_H)
ck_check_include_file("sys/time.h" HAVE_SYS_TIME_H)
ck_check_include_file("sys/wait.h" HAVE_SYS_WAIT_H)
ck_check_include_file("time.h" HAVE_TIME_H)
ck_check_include_file("unistd.h" HAVE_UNISTD_H)
ck_check_include_file("utime.h" HAVE_UTIME_H)
ck_check_include_file("wchar.h" HAVE_WCHAR_H)
ck_check_include_file("wctype.h" HAVE_WCTYPE_H)
ck_check_include_file("windows.h" HAVE_WINDOWS_H)
# Following files need windows.h, so we should test it after windows.h test.
ck_check_include_file("wincrypt.h" HAVE_WINCRYPT_H)
ck_check_include_file("winioctl.h" HAVE_WINIOCTL_H)

###############################################################################
# Check functions
check_function_exists(ctime_r HAVE_CTIME_R)
check_function_exists(fcntl HAVE_FCNTL)
check_function_exists(fileno HAVE_DECL_FILENO)
check_function_exists(fork HAVE_FORK)
check_function_exists(fstat HAVE_FSTAT)
check_function_exists(getenv HAVE_DECL_GETENV)
check_function_exists(getpid HAVE_GETPID)
check_function_exists(gmtime_r HAVE_GMTIME_R)
check_function_exists(localtime_r HAVE_LOCALTIME_R)
check_function_exists(lstat HAVE_LSTAT)
check_function_exists(malloc HAVE_MALLOC)
check_function_exists(mbrtowc HAVE_MBRTOWC)
check_function_exists(mbsnrtowcs HAVE_MBSNRTOWCS)
check_function_exists(memmove HAVE_MEMMOVE)
check_function_exists(mkdir HAVE_MKDIR)
check_function_exists(mkstemp HAVE_MKSTEMP)
check_function_exists(pipe HAVE_PIPE)
check_function_exists(poll HAVE_POLL)
check_function_exists(putenv HAVE_DECL_PUTENV)
check_function_exists(realloc HAVE_REALLOC)
check_function_exists(select HAVE_SELECT)
check_function_exists(setenv HAVE_SETENV)
check_function_exists(setlocale HAVE_SETLOCALE)
check_function_exists(sigaction HAVE_SIGACTION)
check_function_exists(sleep HAVE_DECL_SLEEP)
check_function_exists(strchr HAVE_STRCHR)
check_function_exists(strdup HAVE_STRDUP)
CHECK_FUNCTION_EXISTS(strftime HAVE_STRFTIME)
check_function_exists(strerror HAVE_STRERROR)
CHECK_FUNCTION_EXISTS(strerror_r HAVE_STRERROR_R)
check_function_exists(strncpy_s HAVE_STRNCPY_S)
check_function_exists(strrchr HAVE_STRRCHR)
check_function_exists(strsignal HAVE_STRSIGNAL)
check_function_exists(timegm HAVE_TIMEGM)
check_function_exists(tzset HAVE_TZSET)
check_function_exists(unsetenv HAVE_UNSETENV)
check_function_exists(utime HAVE_UTIME)
check_function_exists(vfork HAVE_VFORK)
CHECK_FUNCTION_EXISTS(vprintf HAVE_VPRINTF)
check_function_exists(wcrtomb HAVE_WCRTOMB)
check_function_exists(wcscmp HAVE_WCSCMP)
check_function_exists(wcscpy HAVE_WCSCPY)
check_function_exists(wcslen HAVE_WCSLEN)
check_function_exists(wcsnrtombs HAVE_WCSNRTOMBS)
check_function_exists(wctomb HAVE_WCTOMB)
CHECK_FUNCTION_EXISTS(wmemcmp HAVE_WMEMCMP)
CHECK_FUNCTION_EXISTS(wmemcpy HAVE_WMEMCPY)
check_function_exists(_ctime64_s HAVE__CTIME64_S)
check_function_exists(_fseeki64 HAVE__FSEEKI64)
check_function_exists(_get_timezone HAVE__GET_TIMEZONE)
check_function_exists(_localtime64_s HAVE__LOCALTIME64_S)
check_function_exists(_mkgmtime64 HAVE__MKGMTIME64)

###############################################################################
# Check defines
set(headers "limits.h")

if(HAVE_STDINT_H)
  list(APPEND headers "stdint.h")
endif(HAVE_STDINT_H)

if(HAVE_INTTYPES_H)
  list(APPEND headers "inttypes.h")
endif(HAVE_INTTYPES_H)

check_symbol_exists(INT64_MAX "${headers}" HAVE_DECL_INT64_MAX)
check_symbol_exists(INT64_MIN "${headers}" HAVE_DECL_INT64_MIN)
check_symbol_exists(UINT32_MAX "${headers}" HAVE_DECL_UINT32_MAX)
check_symbol_exists(UINT64_MAX "${headers}" HAVE_DECL_UINT64_MAX)
check_symbol_exists(SIZE_MAX "${headers}" HAVE_DECL_SIZE_MAX)
check_symbol_exists(SSIZE_MAX "limits.h"   HAVE_DECL_SSIZE_MAX)

###############################################################################
# Check struct members

###############################################################################
# Check for integer types
check_type_size("short" SIZE_OF_SHORT)
check_type_size("int" SIZE_OF_INT)
check_type_size("long" SIZE_OF_LONG)
check_type_size("long long" SIZE_OF_LONG_LONG)

check_type_size("unsigned short" SIZE_OF_UNSIGNED_SHORT)
check_type_size("unsigned" SIZE_OF_UNSIGNED)
check_type_size("unsigned long" SIZE_OF_UNSIGNED_LONG)
check_type_size("unsigned long long" SIZE_OF_UNSIGNED_LONG_LONG)

check_type_size("__int64" __INT64)
check_type_size("unsigned __int64" UNSIGNED___INT64)

check_type_size(int16_t INT16_T) 
check_type_size(int32_t INT32_T)
check_type_size(int64_t INT64_T)
check_type_size(intmax_t INTMAX_T)
check_type_size(uint8_t UINT8_T) 
check_type_size(uint16_t UINT16_T) 
check_type_size(uint32_t UINT32_T) 
check_type_size(uint64_t UINT64_T)
check_type_size(uintmax_t UINTMAX_T)

check_type_size(dev_t DEV_T)
IF(NOT HAVE_DEV_T)
  IF(MSVC)
    SET(dev_t "unsigned int")
  ENDIF(MSVC)
ENDIF(NOT HAVE_DEV_T)
#
check_type_size(gid_t GID_T)
IF(NOT HAVE_GID_T)
  IF(WIN32)
    SET(gid_t "short")
  ELSE(WIN32)
    SET(gid_t "unsigned int")
  ENDIF(WIN32)
ENDIF(NOT HAVE_GID_T)
#
check_type_size(id_t ID_T)
IF(NOT HAVE_ID_T)
  IF(WIN32)
    SET(id_t "short")
  ELSE(WIN32)
    SET(id_t "unsigned int")
  ENDIF(WIN32)
ENDIF(NOT HAVE_ID_T)
#
check_type_size(mode_t MODE_T)
IF(NOT HAVE_MODE_T)
  IF(WIN32)
    SET(mode_t "unsigned short")
  ELSE(WIN32)
    SET(mode_t "int")
  ENDIF(WIN32)
ENDIF(NOT HAVE_MODE_T)
#
check_type_size(off_t OFF_T)
IF(NOT HAVE_OFF_T)
  SET(off_t "__int64")
ENDIF(NOT HAVE_OFF_T)
#
check_type_size(size_t SIZE_T)
IF(NOT HAVE_SIZE_T)
  IF("${CMAKE_SIZEOF_VOID_P}" EQUAL 8)
    SET(size_t "uint64_t")
  ELSE("${CMAKE_SIZEOF_VOID_P}" EQUAL 8)
    SET(size_t   "uint32_t")
  ENDIF("${CMAKE_SIZEOF_VOID_P}" EQUAL 8)
ENDIF(NOT HAVE_SIZE_T)
#
check_type_size(ssize_t SSIZE_T)
IF(NOT HAVE_SSIZE_T)
  IF("${CMAKE_SIZEOF_VOID_P}" EQUAL 8)
    SET(ssize_t "int64_t")
  ELSE("${CMAKE_SIZEOF_VOID_P}" EQUAL 8)
    SET(ssize_t "long")
  ENDIF("${CMAKE_SIZEOF_VOID_P}" EQUAL 8)
ENDIF(NOT HAVE_SSIZE_T)
#
check_type_size(uid_t UID_T)
IF(NOT HAVE_UID_T)
  IF(WIN32)
    SET(uid_t "short")
  ELSE(WIN32)
    SET(uid_t "unsigned int")
  ENDIF(WIN32)
ENDIF(NOT HAVE_UID_T)
#
check_type_size(pid_t PID_T)
IF(NOT HAVE_PID_T)
  IF(WIN32)
    SET(pid_t "int")
  ELSE(WIN32)
    MESSAGE(FATAL_ERROR "pid_t doesn't exist on this platform?")
  ENDIF(WIN32)
ENDIF(NOT HAVE_PID_T)
#
check_type_size(intptr_t INTPTR_T)
IF(NOT HAVE_INTPTR_T)
  IF("${CMAKE_SIZEOF_VOID_P}" EQUAL 8)
    SET(intptr_t "int64_t")
  ELSE()
    SET(intptr_t "int32_t")
  ENDIF()
ENDIF(NOT HAVE_INTPTR_T)
#
check_type_size(uintptr_t UINTPTR_T)
IF(NOT HAVE_UINTPTR_T)
  IF("${CMAKE_SIZEOF_VOID_P}" EQUAL 8)
    SET(uintptr_t "uint64_t")
  ELSE()
    SET(uintptr_t "uint32_t")
  ENDIF()
ENDIF(NOT HAVE_UINTPTR_T)
#
check_type_size(wchar_t SIZEOF_WCHAR_T)
IF(HAVE_SIZEOF_WCHAR_T)
  SET(HAVE_WCHAR_T 1)
ENDIF(HAVE_SIZEOF_WCHAR_T)

###############################################################################
# Generate "config.h" from "cmake/config.h.cmake"
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H)
set(CONFIG_HEADER ${CMAKE_CURRENT_BINARY_DIR}/config.h)