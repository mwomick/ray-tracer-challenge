#ifndef GMath_DEFINED
#define GMath_DEFINED

#include <stdlib.h>

const float G_FL_EPSILON = 0.00001;

static inline bool G_FL_EQUAL(float a, float b) { return abs(a - b) < G_FL_EPSILON; }

static inline bool G_INT_ISODD(int a) { return (1&a) == 1; }

#endif