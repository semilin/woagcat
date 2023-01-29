#pragma once
#include <stdint.h>
#include "layout.h"
typedef enum {
  Unistroke,
  Bistroke,
  Tristroke
} NstrokeType;
typedef enum {
  Char,
  Bigram,
  Trigram,
  Skipgram
} NgramType;
typedef struct {
  char* name;
  NgramType ngram_type;
  float (*fn)(Pos[3]);
} Metric;

float is_sfr(Pos bs[3]);
float is_sfb(Pos bs[3]);
