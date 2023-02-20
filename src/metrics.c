#include "layout.h"
#include "metrics.h"

float is_sfr(Pos bs[3]) {
  return bs[0] == bs[1];
}

float is_sfb(Pos bs[3]) {
  return !is_sfr(bs) &&
    pos_finger(bs[0]) == pos_finger(bs[1]);
}

Metric METRIC_LIST[NUM_METRICS] = {
    {.name = "sfb", .ngram_type = Bigram, .fn = is_sfb},
    {.name = "sfs", .ngram_type = Skipgram, .fn = is_sfb},
    {.name = "sfr", .ngram_type = Bigram, .fn = is_sfr}};
