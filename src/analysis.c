#include <stdint.h>
#include <stdlib.h>
#include "analysis.h"
#include "layout.h"
#include "metrics.h"
#include "corpus.h"

const uint32_t INITIAL_ALLOC = 2048;

void push_metric_amount(MetricAmountList* list, MetricAmount amount) {
  if (amount.amount == 0) {
    return;
  }
  if (list->nstrokes == list->allocated_size) {
    list->amounts = realloc(list->amounts, (list->allocated_size)*2*sizeof(MetricAmount));
    list->allocated_size = 2*list->allocated_size;
  }
  list->amounts[list->nstrokes] = amount;
  list->nstrokes++;
}

MetricAmountList* classify_metric(const Metric* m) {
  MetricAmountList* list = malloc(sizeof(MetricAmountList));
  list->metric = m;
  list->amounts = malloc(sizeof(MetricAmount)*INITIAL_ALLOC);
  list->nstrokes = 0;
  list->allocated_size = INITIAL_ALLOC;

  const NgramType ngram_type = m->ngram_type;

  MetricAmount amount;
  switch (ngram_type) {
  case Char:
    amount.nstroke_type = Unistroke;
    break;
  case Bigram:
  case Skipgram:
    amount.nstroke_type = Bistroke;
    break;
  case Trigram:
    amount.nstroke_type = Tristroke;
    break;
  }
  for (Pos p1=0; p1<30; p1++) {
    amount.nstroke[0] = p1;
    amount.nstroke[1] = -1;
    amount.nstroke[2] = -1;
    if (ngram_type == Char) {
      amount.amount = m->fn(amount.nstroke);
      push_metric_amount(list, amount);
    } else {
      for (Pos p2=0; p2<30; p2++) {
	amount.nstroke[1] = p2;
	if (ngram_type != Trigram) {
	  amount.amount = m->fn(amount.nstroke);
	  push_metric_amount(list, amount);
	} else {
	  for (Pos p3=0; p3<30; p3++) {
	    amount.nstroke[2] = p3;
	    amount.amount = m->fn(amount.nstroke);
	    push_metric_amount(list, amount);
	  }
	}
      }
    }
  }
  list->amounts = realloc(list->amounts, sizeof(MetricAmount)*list->nstrokes);
  return list;
}
