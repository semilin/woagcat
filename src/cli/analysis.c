#include "cli.h"
#include "stdio.h"
#include "../analysis.h"

void analyze_layout(Layout* l) {
  for (int i=0;i<NUM_METRICS;i++) {
    float stats = layout_metric_stats(l, metric_amounts[i], &corpus);
    printf("%s: %.2f%%\n", METRIC_LIST[i].name, 100*stats/(float)layout_freq_total(l, &corpus));
  }
}
