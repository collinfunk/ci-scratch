#!/bin/sh

# Pass our process ID to the child process and check it.
${CHECKER} ./test-getppid${EXEEXT} $$ || exit 1
