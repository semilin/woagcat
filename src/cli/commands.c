#include "cli.h"

void view_cmd(ArgVal* args) {
  print_layout(args[0].LayoutVal);
}

void analyze_cmd(ArgVal* args) {
  analyze_layout(args[0].LayoutVal);
}

void quit_cmd(ArgVal* args) {
  (void) args;
  exit(0);
}

const size_t NUM_COMMANDS = 3;
const Command COMMANDS[] = {
  {.name = "view",
   .usage = "view LAYOUT",
   .aliases = {"v"},
   .alias_count = 1,
   .args = {LayoutArg},
   .argc = 1,
   .fn = view_cmd},
  {.name = "analyze",
   .usage = "analyze LAYOUT",
   .aliases = {"a"},
   .alias_count = 1,
   .args = {LayoutArg},
   .argc = 1,
   .fn = analyze_cmd},
  {.name = "quit",
   .usage = "quit",
   .aliases = {"exit", "q"},
   .alias_count = 2,
   .argc = 0,
   .fn = quit_cmd}
};
