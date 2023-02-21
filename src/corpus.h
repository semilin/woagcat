#pragma once
#include <stdint.h>
extern const char* SYMBOLS;
enum { SYMBOLS_LENGTH = 31 };
struct Corpus {
  uint32_t chars[SYMBOLS_LENGTH];
  uint32_t bigrams[SYMBOLS_LENGTH*SYMBOLS_LENGTH];
  uint32_t skipgrams[SYMBOLS_LENGTH*SYMBOLS_LENGTH];
  uint32_t trigrams[SYMBOLS_LENGTH*SYMBOLS_LENGTH*SYMBOLS_LENGTH];
};
typedef struct Corpus Corpus;

int8_t char_to_index(char c);
int bigram_to_index(char a, char b);
int trigram_to_index(char a, char b, char c);
int read_file_corpus(Corpus* corpus, char* path);
