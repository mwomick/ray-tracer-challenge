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

    GMatrix33 m10 = GMatrix33(1, 2, 6,
                              -5, 8, -4,
                              2, 6, 4);
    
    assert(m10.det() == -196);

    GMatrix44 m11 = GMatrix44(-2, -8, 3, 5,
                              -3, 1, 7, 3,
                              1, 2, -9, 6,
                              -6, 7, 7, -9);

    assert(m11.det() == -4071);

    GMatrix44 m12 = GMatrix44(8, -5, 9, 2,
                              7, 5, 6, 1, 
                              -6, 0, 9, 6, 
                              -3, 0, -9, -4);

    GMatrix44 m13 = m12.inverse();

    assert(G_FL_EQUAL(m13[0], -0.15385));
    assert(G_FL_EQUAL(m13[1], -0.15385));
    assert(G_FL_EQUAL(m13[2], -0.28205));
    assert(G_FL_EQUAL(m13[3], -0.53846));
    assert(G_FL_EQUAL(m13[4], -0.07692));
    assert(G_FL_EQUAL(m13[5], 0.12308));
    assert(G_FL_EQUAL(m13[6], 0.02564));
    assert(G_FL_EQUAL(m13[7], 0.03077));
    assert(G_FL_EQUAL(m13[8], 0.35897));
    assert(G_FL_EQUAL(m13[9], 0.35897));
    assert(G_FL_EQUAL(m13[10], 0.43590));
    assert(G_FL_EQUAL(m13[11], 0.92308));
    assert(G_FL_EQUAL(m13[12], -0.69231));
    assert(G_FL_EQUAL(m13[13], -0.69231));
    assert(G_FL_EQUAL(m13[14], -0.76923));
    assert(G_FL_EQUAL(m13[15], -1.92308));
}