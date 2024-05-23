# getppid.m4
# serial 1
dnl Copyright 2024 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.

AC_DEFUN([gl_FUNC_GETPPID],
[
  AC_REQUIRE([gl_UNISTD_H_DEFAULTS])
  AC_CHECK_FUNCS_ONCE([getppid])

  if test "$ac_cv_func_getppid" = "yes"; then
    HAVE_GETPPID=1
  else
    HAVE_GETPPID=0
  fi
])
