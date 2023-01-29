#pragma once
#include <stdint.h>
#include "layout.h"
#include "metrics.h"
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
