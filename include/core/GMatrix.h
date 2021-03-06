#ifndef GMatrix_DEFINED
#define GMatrix_DEFINED

#include <cmath>

#include "include/core/GMath.h"
#include "include/core/GTuple.h"

class GMatrix22 {
public:
 
    GMatrix22() : fMat {1, 0, 
                        0, 1}
    {}
    
    GMatrix22(float a, float b, float c, float d) {
        fMat[0] = a;   fMat[1] = b;    
        fMat[2] = c;   fMat[3] = d;
    }

    float det() {
        return fMat[0]*fMat[3] - fMat[1]*fMat[2];
    }

    float operator[](int index) {
        return fMat[index];
    }

private:
    float fMat[4]; 
};

/////////////////////////////////////////////////////////////////////////////////////

class GMatrix33 {
public:
 
    GMatrix33() : fMat {1, 0, 0, 
                        0, 1, 0,
                        0, 0, 1} 
    {}
    
    GMatrix33(float a, float b, float c, 
              float d, float e, float f, 
              float g, float h, float i) {
        fMat[0] = a;   fMat[1] = b;    fMat[2] = c;
        fMat[3] = d;   fMat[4] = e;    fMat[5] = f;
        fMat[6] = g;   fMat[7] = h;    fMat[8] = i;
    }

    float operator[](int index) {
        return fMat[index];
    }

    GMatrix22 submatrix(int, int);
    float minor(int, int);
    float cofactor(int, int);
    float det();

private:
    float fMat[9]; 
};

/////////////////////////////////////////////////////////////////////////////////////

enum { kSX, kKXY, kKXZ, kTX, 
       kKYX, kSY, kKYZ, kTY,
       kKZX, kKZY, kSZ, kTZ,
};

class GMatrix44 {
public:
    GMatrix44() : fMat {1, 0, 0, 0, 
                        0, 1, 0, 0, 
                        0, 0, 1, 0, 
                        0, 0, 0, 1} 
    {}
    
    GMatrix44(float a, float b, float c, float d,
              float e, float f, float g, float h,  
              float i, float j, float k, float l,
              float m, float n, float o, float p) {
        fMat[ 0] = a;   fMat[ 1] = b;    fMat[ 2] = c;    fMat[ 3] = d;
        fMat[ 4] = e;   fMat[ 5] = f;    fMat[ 6] = g;    fMat[ 7] = h;
        fMat[ 8] = i;   fMat[ 9] = j;    fMat[10] = k;    fMat[11] = l;
        fMat[12] = m;   fMat[13] = n;    fMat[14] = o;    fMat[15] = p;
    }

    float operator[](int index) {
        return fMat[index];
    }

    GMatrix44 operator*(const GMatrix44& rhs) { return this->multiply(rhs); }
    GTuple operator*(GTuple rhs) { 
        float x, y, z;
        x = rhs.x()*this->fMat[kSX] + rhs.y()*this->fMat[kKXY] + rhs.z()*this->fMat[kKXZ] + this->fMat[kTX];
        y = rhs.y()*this->fMat[kSY] + rhs.x()*this->fMat[kKYX] + rhs.z()*this->fMat[kKYZ] + this->fMat[kTY];
        z = rhs.z()*this->fMat[kSZ] + rhs.x()*this->fMat[kKZX] + rhs.y()*this->fMat[kKZY] + this->fMat[kTZ];
        return GTuple(x, y, z);
    }

    GMatrix44 multiply(const GMatrix44&);
    GMatrix44 transpose();
    GMatrix33 submatrix(int, int);
    float minor(int, int);
    float cofactor(int, int);
    float det();
    GMatrix44 inverse();

    static GMatrix44 Translate(float tx, float ty, float tz) {
        return GMatrix44(1, 0, 0, tx,
                         0, 1, 0, ty, 
                         0, 0, 1, tz,
                         0, 0, 0, 1);
    }

    static GMatrix44 Scale(float sx, float sy, float sz) {
        return GMatrix44(sx, 0, 0, 0,
                         0, sy, 0, 0, 
                         0, 0, sz, 0,
                         0, 0, 0, 1);
    }

    static GMatrix44 Skew(float kxy, float kxz, float kyx, float kyz, float kzx, float kzy) {
        return GMatrix44(1, kxy, kxz, 0,
                         kyx, 1, kyz, 0, 
                         kzx, kzy, 1, 0,
                         0, 0, 0, 1);
    }

    static GMatrix44 RotateX(float angle) {
        return GMatrix44(1, 0, 0, 0,
                         0, cos(angle), -sin(angle), 0,
                         0, sin(angle), cos(angle), 0,
                         0, 0, 0, 1);
    }

    static GMatrix44 RotateY(float angle) {
        return GMatrix44(cos(angle), 0, sin(angle), 0,
                         0, 1, 0, 0,
                         -sin(angle), 0, cos(angle), 0,
                         0, 0, 0, 1);
    }

    static GMatrix44 RotateZ(float angle) {
        return GMatrix44(cos(angle), -sin(angle), 0, 0, 
                         sin(angle), cos(angle), 0, 0, 
                         0, 0, 1, 0,
                         0, 0, 0, 1);
    }

    static GMatrix44 Orient(GTuple from, GTuple to, GTuple up) {
        GTuple forward = (to - from).normalize();
        GTuple upn = up.normalize();
        GTuple left = forward.cross(upn);
        GTuple true_up = left.cross(forward);
        GMatrix44 m = GMatrix44(left.x(),     left.y(),     left.z(),     0,
                         true_up.x(),  true_up.y(),  true_up.z(),  0,
                         -forward.x(), -forward.y(), -forward.z(), 0,
                         0,             0,           0,             1);
        GMatrix44 t = GMatrix44::Translate(-from.x(), -from.y(), -from.z());
        return m * t;
    }

private:
    float fMat[16]; 
};

#endif
