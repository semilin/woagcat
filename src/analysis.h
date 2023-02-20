#pragma once
#include <stdint.h>
#include "layout.h"
#include "metrics.h"
#include "corpus.h"
typedef struct {
  Pos nstroke[3];
  NstrokeType nstroke_type;
  float amount;
} MetricAmount;
typedef struct {
  const Metric* metric;
  MetricAmount* amounts;
  uint32_t nstrokes;
  uint32_t allocated_size;
} MetricAmountList;
MetricAmountList* classify_metric(const Metric* m);
void classify_all_metrics(void);
float layout_metric_stats(Layout *l, MetricAmountList *metric_amount_list,
                          Corpus *corpus);

extern MetricAmountList* metric_amounts[NUM_METRICS];
