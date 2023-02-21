#pragma once
#include "../layout.h"
#include <stdlib.h>

extern Corpus corpus;

typedef struct {
  char* corpus_path;
} Config;
int handler(void* main, const char* section, const char* name, const char* value);

typedef enum {
  LayoutArg,
} Argument;

typedef union {
  Layout* LayoutVal;
} ArgVal;

typedef struct {
  char* name;
  char* usage;
  char* aliases[3];
  size_t alias_count;
  Argument args[5];
  size_t argc;
  void (*fn)(ArgVal*);
} Command;

Layout *get_layout(char *layout_name);
const Command* get_command(char* name);
void run_command(const Command* cmd, char* tokens[]);

void output_error(char* fmt, ...);
void output_usage(const Command* cmd);

void analyze_layout(Layout* l);

extern const size_t NUM_COMMANDS;
extern const Command COMMANDS[];
