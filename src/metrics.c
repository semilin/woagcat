#include <stdbool.h>
#include "layout.h"

bool is_sfr(Pos a, Pos b) {
  return a == b;
}

bool is_sfb(Pos a, Pos b) {
  return !is_sfr(a, b) &&
    pos_finger(a) == pos_finger(b);
}
