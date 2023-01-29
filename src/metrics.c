#include "layout.h"

float is_sfr(Pos bs[3]) {
  return bs[0] == bs[1];
}

float is_sfb(Pos bs[3]) {
  return !is_sfr(bs) &&
    pos_finger(bs[0]) == pos_finger(bs[1]);
}
