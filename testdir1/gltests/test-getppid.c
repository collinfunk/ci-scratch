/* Test the getppid function.
   Copyright (C) 2024 Free Software Foundation, Inc.

   This file is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published
   by the Free Software Foundation, either version 3 of the License,
   or (at your option) any later version.

   This file is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* Written by Collin Funk <collin.funk1@gmail.com>, 2024.  */

#include <config.h>

/* Specification.  */
#include <unistd.h>

#include "signature.h"
SIGNATURE_CHECK (getppid, pid_t, (void));

#include <stdlib.h>
#include <stdio.h>

#include "macros.h"

int
main (int argc, char *argv[])
{
  unsigned long int expected_ppid;
  unsigned long int ppid;
  char *endp;

  if (argc < 2)
    {
      fprintf (stderr, "Expected parent PID in argv[1]\n");
      exit (1);
    }

  expected_ppid = strtoul (argv[1], &endp, 10);
  if (*endp != '\0')
    {
      fprintf (stderr, "Expected an integer argument.\n");
      exit (1);
    }

  ppid = getppid ();

  printf ("expected ppid: %lu\n", expected_ppid);
  printf ("ppid:          %lu\n", ppid);

  ASSERT (expected_ppid == ppid);

  return test_exit_status;
}
