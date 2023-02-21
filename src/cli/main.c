#include "../analysis.h"
#include "../corpus.h"
#include "../layout.h"
#include "../../inih/ini.h"
#include "cli.h"
#include <inttypes.h>
#include <mcheck.h>
#include <stdio.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <string.h>

Corpus corpus;

int main(void) {
  mcheck(0);

  Config config;
  config.corpus_path = NULL;
  if (ini_parse("config.ini", handler, &config) < 0) {
    output_error("can't load `config.ini`.");
    return 1;
  }
  mcheck(0);

  if (read_file_corpus(&corpus, config.corpus_path)) {
    output_error("couldn't load file `%s`. Please edit your `config.ini`", config.corpus_path);
    return 1;
  }
  classify_all_metrics();

  char *tokens[10];
  using_history();
  while (1) {
    memset(&tokens[0], 0, sizeof(tokens));
    char *line = readline("> ");
    if (!line)
      break;
    add_history(line);
    int token_count = 0;
    char *token = strtok(line, " ");
    while (token != NULL && token_count < 10) {
      tokens[token_count] = token;
      token_count++;
      token = strtok(NULL, " ");
    }
    const Command* cmd = get_command(tokens[0]);
    if (!cmd) {
      output_error("command `%s` not found.", tokens[0]);
    } else {
      run_command(cmd, tokens);
    }
    free(line);
  }
  return 0;
}
