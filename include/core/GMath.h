#ifndef GMath_DEFINED
#define GMath_DEFINED

#include <stdlib.h>

const float G_FL_EPSILON = 0.0015;

static inline bool G_FL_EQUAL(float a, float b) { return abs(a - b) < G_FL_EPSILON; }

static inline bool G_INT_ISODD(int a) { return (1&a) == 1; }

static inline int G_FL_ROUND_TO_INT(float a) { return (int)(a + 0.5f); }

#endif