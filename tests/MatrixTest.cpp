#include "include/core/GMatrix.h"

#include <assert.h>
#include <iostream>
using namespace std;

int main() {
    GMatrix44 m1 = GMatrix44(1, 2, 3, 4,
                             5, 6, 7, 8,
                             9, 8, 7, 6,
                             5, 4, 3, 2);
                             
    GMatrix44 m2 = GMatrix44(-2, 1, 2, 3,
                             -3, 2, 1, -1, 
                             4, 3, 6, 5,
                             1, 2, 7, 8);
    GMatrix44 m3 = m1*m2;

    assert(m3[0] == 8);
    assert(m3[1] == 22);
    assert(m3[2] == 50);
    assert(m3[3] == 48);
    assert(m3[4] == 8);
    assert(m3[5] == 54);
    assert(m3[6] == 114);
    assert(m3[7] == 108);
    assert(m3[8] == -8);
    assert(m3[9] == 58);
    assert(m3[10] == 110);
    assert(m3[11] == 102);
    assert(m3[12] == -8);
    assert(m3[13] == 26);
    assert(m3[14] == 46);
    assert(m3[15] == 42);
}