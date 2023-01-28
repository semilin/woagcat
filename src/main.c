#include <stdio.h>
#include <inttypes.h>
#include "corpus.h"
#include "layout.h"

int main() {
  Corpus corpus;

  char* path = "./tr_quotes.txt";

  printf("%s\n", path);
  read_file_corpus(&corpus, path);

  printf("symbols length: %d\n", SYMBOLS_LENGTH);
  printf("t index: %d\n", char_to_index('t'));
  printf("h index: %d\n", char_to_index('h'));
  printf("th index: %d\n", bigram_to_index('t', 'h'));

  printf("th count: %d\n", corpus.bigrams[bigram_to_index('t', 'h')]);
  printf("an count: %d\n", corpus.bigrams[bigram_to_index('a', 'n')]);

  printf("pos 4 finger: %d\n", pos_finger(4));
  printf("dist 4 3: %f\n", distance(4, 3));
  printf("dist 4 4: %f\n", distance(4, 4));
  printf("dist 10 0: %f\n", distance(10, 0));
  printf("ydist 10 0: %d\n", y_distance(10, 0));
  printf("xdist 10 0: %d\n", x_distance(10, 0));

  /* printf("%d\n", SYMBOLS_LENGTH); */
  /* printf("%" PRId8 "\n", char_to_index('t')); */
  /* printf("%" PRId8 "\n", char_to_index('h')); */
  /* printf("%" PRId8 "\n", (SYMBOLS_LENGTH * char_to_index('t')) + char_to_index('h')); */
  /* printf("%" PRId8 "\n", bigram_to_index('t', 'h')); */
  /* printf("%" PRId8 "\n", corpus.bigrams[bigram_to_index('t', 'h')]); */

  Layout l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
	      10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	      20, 21, 22, 23, 24, 25, 26, 27, 28, 29};

  print_layout(l);
  return 0;
}
