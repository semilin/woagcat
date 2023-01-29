#include <stdio.h>
#include <inttypes.h>
#include "corpus.h"
#include "layout.h"

int main() {
  Corpus corpus;

  char* path = "./tr_quotes.txt";

  read_file_corpus(&corpus, path);

  printf("th count: %d\n", corpus.bigrams[bigram_to_index('t', 'h')]);
  printf("an count: %d\n", corpus.bigrams[bigram_to_index('a', 'n')]);

  /* Layout l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, */
  /* 	      10, 11, 12, 13, 14, 15, 16, 17, 18, 19, */
  /* 	      20, 21, 22, 23, 24, 25, 26, 27, 28, 29}; */

  /* print_layout(l); */
  return 0;
}
