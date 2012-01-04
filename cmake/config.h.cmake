/*-*- mode:C; -*- */
/*
 * Check: a unit test framework for C
 *
 * Copyright (C) 2011 Mateusz Loskot
 * Copyright (C) 2001, 2002 Arien Malec
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#cmakedefine HAVE_SIGACTION 1
#cmakedefine HAVE_DECL_FILENO 1
#cmakedefine HAVE_FORK 1
#cmakedefine HAVE_DECL_GETENV 1
#cmakedefine HAVE_LOCALTIME_R 1
#cmakedefine HAVE_MALLOC 1
#cmakedefine HAVE_DECL_PIPE 1
#cmakedefine HAVE_DECL_PUTENV 1
#cmakedefine HAVE_REALLOC 1
#cmakedefine HAVE_DECL_SETENV 1
#cmakedefine HAVE_DECL_SLEEP 1
#cmakedefine HAVE_DECL_STRDUP 1
#cmakedefine HAVE_STRSIGNAL 1
#cmakedefine HAVE_DECL_UNSETENV 1
#cmakedefine HAVE_SYS_TYPES_H 1
#cmakedefine HAVE_SYS_WAIT_H 1
#cmakedefine HAVE_SYS_TIME_H 1
#cmakedefine HAVE_UNISTD_H 1
#cmakedefine HAVE_SIGNAL_H 1
#cmakedefine HAVE_STDINT_H 1
#cmakedefine HAVE_PID_T 1
#cmakedefine HAVE_SSIZE_T 1
#define TIMEOUT_TESTS_ENABLED @TIMEOUT_TESTS_ENABLED@

#endif /* __CONFIG_H */