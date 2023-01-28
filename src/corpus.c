#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "corpus.h"

const char* SYMBOLS = "abcdefghijklmnopqrstuvwxyz,./;'\0";

int8_t char_to_index(char c) {
  if (c >= 97 && c <= 122) {
    // alphabet
    return c - 97;
  } else if (c >= 65 && c <= 90) {
    // caps
    return c - 65;
  } else {
    switch(c) {
    case ',': 
      return 26;
      break;
    case '.': 
      return 27;
      break;
    case '/': 
      return 28;
      break;
    case '?':
      return 28;
      break;
    case ';': 
      return 29;
      break;
    case ':':
      return 29;
      break;
    case '\'':
      return 30;
      break;
    }
  }
  return -1;
}

int bigram_to_index(char a, char b) {
  int32_t a_idx = char_to_index(a);
  int32_t b_idx = char_to_index(b);
  if (a_idx == -1 || b_idx == -1) {
    return -1;
  }
  return (SYMBOLS_LENGTH * a_idx) + b_idx;
}

int trigram_to_index(char a, char b, char c) {
  int32_t bg_idx = bigram_to_index(b, c);
  int32_t a_idx = char_to_index(a);

  if (bg_idx == -1 || a_idx == -1) {
    return -1;
  }
  
  return (SYMBOLS_LENGTH * SYMBOLS_LENGTH * a_idx) + bg_idx;
}

void read_file_corpus(Corpus* corpus, char* path) {
  const int BUFFER_SIZE = 255;
  FILE* file;
  char buff[BUFFER_SIZE];

  memset(corpus, 0, sizeof(Corpus));

  file = fopen(path, "r");
  if (!file) {
    printf("File %s does not exist.\n", path);
    return;
  }

  while (1) {
    if (fgets(buff, BUFFER_SIZE, file) == NULL) {
      break;
    };

    short indexes[3] = {-1, -1, -1};
    for (int i=0;i<BUFFER_SIZE;i++) {
      char current = buff[i];
      if (current == '\0') {
	break;
      }
      indexes[2] = indexes[1];
      indexes[1] = indexes[0];
      indexes[0] = char_to_index(current);

      if (indexes[0] != -1) {
	corpus->chars[indexes[0]]++;
	if (indexes[1] != -1) {
	  int bg_head = indexes[1] * SYMBOLS_LENGTH;
	  corpus->bigrams[bg_head + indexes[0]]++;
	  if (indexes[2] != -1) {
	    int tg_head = indexes[2] * SYMBOLS_LENGTH * SYMBOLS_LENGTH;
	    corpus->trigrams[tg_head + bg_head + indexes[0]]++;
	    corpus->skipgrams[bg_head +indexes[0]]++;
	  }
      }}
    }
  }
  
  fclose(file);
}
