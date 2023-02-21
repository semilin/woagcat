#include "../layout.h"
#include "cli.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

Layout *get_layout(char *layout_name) {
  char full_path[50];
  strcpy(full_path, "layouts/");
  const size_t base_len = strlen(full_path);
  size_t i;
  for (i = base_len; i < sizeof(full_path); i++) {
    char c = layout_name[i - base_len];
    full_path[i] = layout_name[i - 8];
    if (c == '\0')
      break;
  }
  FILE *fp;
  fp = fopen(full_path, "r");
  if (fp == NULL)
    return NULL;
  char c;
  Layout *l = malloc(sizeof(*l));
  size_t j = 0;
  for (int i = 0; i < 32; i++) {
    c = getc(fp);
    if (feof(fp)) {
      output_error("Layout file %s is too short!", full_path);
      exit(1);
    }
    if (c == '\n') {
      continue;
    }
    if (j < sizeof(*l)) {
      l->matrix[j] = char_to_index(c);
      j++;
    }
  }
  fclose(fp);
  return l;
}

const Command *get_command(char *name) {
  for (size_t i = 0; i < NUM_COMMANDS; i++) {
    if (strcmp(COMMANDS[i].name, name) == 0)
      return &COMMANDS[i];
    for (size_t a = 0; a<COMMANDS[i].alias_count; a++) {
      if (strcmp(COMMANDS[i].aliases[a], name) == 0)
	return &COMMANDS[i];
    }
  }
  return NULL;
}

void run_command(const Command *cmd, char *tokens[]) {
  ArgVal vals[5];
  for (size_t i = 0; i < cmd->argc; i++) {
    char *token = tokens[i + 1];
    switch (cmd->args[i]) {
    case LayoutArg:
      if (!token) {
        output_error("command `%s` missing a LAYOUT arg.", cmd->name);
        output_usage(cmd);
        return;
      }
      Layout *layout = get_layout(token);
      if (!layout) {
        output_error("layout `%s` not found.", token);
        return;
      }
      vals[i].LayoutVal = get_layout(token);
      break;
    }
  }
  cmd->fn(vals);
}
