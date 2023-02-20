#include "analysis.h"
#include "corpus.h"
#include "layout.h"
#include <inttypes.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  Corpus corpus;

  char *path = "./tr_quotes.txt";

  read_file_corpus(&corpus, path);

  classify_all_metrics();

  //Layout *l = str_to_layout("qwertyuiopasdfghjkl;zxcvbnm,./");
  Layout *l = str_to_layout("flhvz'wuoysrntkcdeaixjbmqpg,./");
  print_layout(l);

  float result = layout_metric_stats(l, metric_amounts[2], &corpus);
  printf("%.2f%%\n", 100 * result / (float)layout_freq_total(l, &corpus));

  char* line;
  char* tokens[10];
  while ((line = readline("> ")) != NULL) {
    if (strlen(line) > 0) {
      add_history(line);
    }
    memset(tokens, 0, 10*sizeof(*tokens));
    int token_count = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
      tokens[token_count] = token;
      token_count++;
      token = strtok(NULL, " ");
    }
    free(line);
  }
  return 0;
}
