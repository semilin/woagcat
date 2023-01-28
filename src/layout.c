#include "corpus.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include "layout.h"

const Finger FINGER_MAP[30] =
  {LP, LR, LM, LI, LI, RI, RI, RM, RR, RP,
   LP, LR, LM, LI, LI, RI, RI, RM, RR, RP,
   LP, LR, LM, LI, LI, RI, RI, RM, RR, RP,};

void print_layout(Layout l) {
  for (int i=0;i<30;i++) {
    if (i != 0 && i % 5 == 0) {
      if (i % 10 == 0) {
	printf("\n");
      } else {
	printf(" ");
      }
    }
    printf("%c ", SYMBOLS[l[i]]);
  }
  printf("\n");
}

Finger pos_finger(Pos p) {
  return FINGER_MAP[p];
}

uint8_t pos_x(Pos p) {
  if (p <= 9) {
    return p;
  } else if (p <= 19) {
    return p - 10;
  } else {
    return p - 20;
  }
}

uint8_t pos_y(Pos p) {
  if (p <= 9) {
    return 0;
  } else if (p <= 19) {
    return 1;
  } else {
    return 2;
  }
}

uint8_t x_distance(Pos a, Pos b) {
  return abs(pos_x(a) - pos_x(b));
}

uint8_t y_distance(Pos a, Pos b) {
  return abs(pos_y(a) - pos_y(b));
}

float distance(Pos a, Pos b) {
  float xd = (float) x_distance(a, b);
  float yd = (float) y_distance(a, b);
  return sqrtf((xd*xd)+(yd*yd));
}
