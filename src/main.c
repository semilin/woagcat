#include "analysis.h"
#include "corpus.h"
#include "layout.h"
#include <inttypes.h>
#include <stdio.h>

int main(void) {
  Corpus corpus;

  char *path = "./tr_quotes.txt";

  read_file_corpus(&corpus, path);

  printf("th count: %d\n", corpus.bigrams[bigram_to_index('t', 'h')]);
  printf("an count: %d\n", corpus.bigrams[bigram_to_index('a', 'n')]);

  classify_all_metrics();

  //Layout *l = str_to_layout("qwertyuiopasdfghjkl;zxcvbnm,./");
  Layout *l = str_to_layout("flhvz'wuoysrntkcdeaixjbmqpg,./");
  print_layout(l);

  float result = layout_metric_stats(l, metric_amounts[2], &corpus);
  printf("%i\n", layout_freq_total(l, &corpus));
  printf("%f\n", result);
  printf("%.2f%%\n", 100 * result / (float)layout_freq_total(l, &corpus));
  return 0;
}
