#include "cli.h"

void view_cmd(ArgVal* args) {
  print_layout(args[0].LayoutVal);
}

void analyze_cmd(ArgVal* args) {
  analyze_layout(args[0].LayoutVal);
}

const size_t NUM_COMMANDS = 2;
const Command COMMANDS[] = {
  {.name = "view",
   .usage = "view LAYOUT",
   .args = {LayoutArg},
   .argc = 1,
   .fn = view_cmd},
  {.name = "analyze",
   .usage = "analyze LAYOUT",
   .args = {LayoutArg},
   .argc = 1,
   .fn = analyze_cmd}
};
