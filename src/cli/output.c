#include "cli.h"
#include <stdio.h>
#include <stdarg.h>

const char* AC_RED = "\x1b[31m";
const char* AC_YELLOW = "\x1b[33m";
const char* AC_NORMAL = "\x1b[m";

void output_error(char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  printf("%sError%s: ", AC_RED, AC_NORMAL);
  vprintf(fmt, args);
  va_end(args);
  printf("\n");
}

void output_usage(const Command* cmd) {
  printf("%sUsage%s: %s\n", AC_YELLOW, AC_NORMAL, cmd->usage);
}
