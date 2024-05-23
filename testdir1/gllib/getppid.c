/* getppid function for Native Windows.

   Copyright 2024 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as
   published by the Free Software Foundation; either version 2.1 of the
   License, or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by Collin Funk.  */

#include <config.h>

#include <unistd.h>
#include <stdlib.h>

#if defined _WIN32 && ! defined __CYGWIN__
#  include <windows.h>
#  include <tlhelp32.h>
#  ifndef TH32CS_SNAPPROCESS
#    define TH32CS_SNAPPROCESS 2
#  endif
#endif

pid_t
getppid (void)
{
  HANDLE snapshot;
  PROCESSENTRY32 entry;
  BOOL found;
  DWORD pid = GetCurrentProcessId ();

  snapshot = CreateToolhelp32Snapshot (TH32CS_SNAPPROCESS, 0);
  if (snapshot == INVALID_HANDLE_VALUE)
    abort ();
  entry.dwSize = sizeof (PROCESSENTRY32);
  for (found = Process32First (snapshot, &entry); found;
       found = Process32Next (snapshot, &entry))
    {
      if (entry.th32ProcessID == pid)
        {
          CloseHandle (snapshot);
          return (pid_t) entry.th32ParentProcessID;
        }
    }
  CloseHandle (snapshot);
  abort ();
  return -1;
}
