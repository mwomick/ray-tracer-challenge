#include "include/core/GMatrix.h"

#include <assert.h>
#include <iostream>

// #include "include/core/GMath.h"

using namespace std;

int main() {
    GMatrix44 m1 = GMatrix44(1, 2, 3, 4,
                             5, 6, 7, 8,
                             9, 8, 7, 6,
                             5, 4, 3, 2);
                             
    GMatrix44 m2 = GMatrix44(-2, 1, 2, 3,
                             3, 2, 1, -1, 
                             4, 3, 6, 5,
                             1, 2, 7, 8);
    GMatrix44 m3 = m1*m2;

    assert(m3[0] == 20);
    assert(m3[1] == 22);
    assert(m3[2] == 50);
    assert(m3[3] == 48);
    assert(m3[4] == 44);
    assert(m3[5] == 54);
    assert(m3[6] == 114);
    assert(m3[7] == 108);
    assert(m3[8] == 40);
    assert(m3[9] == 58);
    assert(m3[10] == 110);
    assert(m3[11] == 102);
    assert(m3[12] == 16);
    assert(m3[13] == 26);
    assert(m3[14] == 46);
    assert(m3[15] == 42);

    GMatrix33 m4 = GMatrix33(1, 5, 0, 
                             -3, 2, 7,
                             0, 6, -3);

    GMatrix22 m5 = m4.submatrix(0, 2);

    assert(m5[0] == -3);
    assert(m5[1] == 2);
    assert(m5[2] == 0);
    assert(m5[3] == 6);

    GMatrix44 m6 = GMatrix44(-6, 1, 1, 6,
                             -8, 5, 8, 6, 
                             -1, 0, 8, 2,
                             -7, 1, -1, 1);
    
    GMatrix33 m7 = m6.submatrix(2, 1);

    assert(m7[0] == -6);
    assert(m7[1] == 1);
    assert(m7[2] == 6);
    assert(m7[3] == -8);
    assert(m7[4] == 8);
    assert(m7[5] == 6);
    assert(m7[6] == -7);
    assert(m7[7] == -1);
    assert(m7[8] == 1);

    GMatrix33 m8 = GMatrix33(3, 5, 0, 
                             2, -1, -7, 
                             6, -1, 5);

    assert(m8.minor(1, 0) == 25);

    GMatrix33 m9 = GMatrix33(3, 5, 0, 
                             2, -1, -7, 
                             6, -1, 5);

    assert(m9.cofactor(0, 0) == -12);
    assert(m9.cofactor(1, 0) == -25);
}