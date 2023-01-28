#pragma once
#include <stdint.h>
typedef int8_t Layout[30];
typedef int8_t Pos;
enum Finger {
  LP, LR, LM, LI, LT,
  RT, RI, RM, RR, RP,
  NONE
};
typedef enum Finger Finger;
extern const Finger FINGER_MAP[30];

void print_layout(Layout l);
Finger pos_finger(Pos p);

uint8_t pos_x(Pos p);
uint8_t pos_y(Pos p);

uint8_t x_distance(Pos a, Pos b);
uint8_t y_distance(Pos a, Pos b);
float distance(Pos a, Pos b);
