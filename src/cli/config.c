#include <string.h>
#include <stdio.h>
#include "cli.h"

#define MATCH(s,n) strcmp(section, s) == 0 && strcmp(name, n) == 0
int handler(void* main, const char* section, const char* name, const char* value) {
  Config* mconfig = (Config*)main;

  if (MATCH("main", "corpus_path")) {
    mconfig->corpus_path = strdup(value);
  } else {
    return 0;
  }

  return 1;
}
