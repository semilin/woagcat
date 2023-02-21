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

void help_cmd(ArgVal* args) {
  (void) args;
  for(size_t i=0;i<NUM_COMMANDS;i++) {
    output_command_help(&COMMANDS[i]);
  }
}

const size_t NUM_COMMANDS = 4;
const Command COMMANDS[] = {
  {.name = "view",
   .description = "prints the matrix of a layout.",
   .usage = "view LAYOUT",
   .aliases = {"v"},
   .alias_count = 1,
   .args = {LayoutArg},
   .argc = 1,
   .fn = view_cmd},
  {.name = "analyze",
   .description = "prints the metric stats of a layout.",
   .usage = "analyze LAYOUT",
   .aliases = {"a"},
   .alias_count = 1,
   .args = {LayoutArg},
   .argc = 1,
   .fn = analyze_cmd},
  {.name = "quit",
   .description = "quits woagcat.",
   .usage = "quit",
   .aliases = {"exit", "q"},
   .alias_count = 2,
   .argc = 0,
   .fn = quit_cmd},
    {.name = "help",
   .description = "prints the list of commands.",
   .usage = "help",
   .aliases = {"?", "hwat"},
   .alias_count = 2,
   .argc = 0,
   .fn = help_cmd}
};
