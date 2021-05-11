#ifndef GMatrix_DEFINED
#define GMatrix_DEFINED

#include "include/core/GMath.h"

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

    GMatrix22 submatrix(int row, int col) {
        float out[4];
        int index = 0;
        for(int i = 0; i < 3; i++) {
            if(row == i) continue; 
            for(int j = 0; j < 3; j++) {
                if(col == j) continue;
                out[index++] = this->fMat[i*3+j];
            }
        }
        return GMatrix22(out[0], out[1], 
                         out[2], out[3]);
    }

    float minor(int row, int col) {
        GMatrix22 m = this->submatrix(row, col);
        return m.det();
    }

    float cofactor(int row, int col) {
        if(G_INT_ISODD(row+col)) return -1*minor(row, col);
        else return minor(row, col);
    }

    float det() {
        return fMat[0]*this->cofactor(0, 0) + fMat[1]*this->cofactor(0, 1) + 
               fMat[2]*this->cofactor(0,2);
    }

    float operator[](int index) {
        return fMat[index];
    }

private:
    float fMat[9]; 
};

/////////////////////////////////////////////////////////////////////////////////////

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

    GMatrix44 operator*(const GMatrix44& rhs) {
        float matrix[16];
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                matrix[j+(i<<2)] = this->fMat[(i<<2)] * rhs.fMat[j] +
                                   this->fMat[(i<<2)+1] * rhs.fMat[j+4] +
                                   this->fMat[(i<<2)+2] * rhs.fMat[j+8] +
                                   this->fMat[(i<<2)+3] * rhs.fMat[j+12];
            }
        }
        return GMatrix44(matrix[0], matrix[1], matrix[2], matrix[3], 
                         matrix[4], matrix[5], matrix[6], matrix[7],
                         matrix[8], matrix[9], matrix[10], matrix[11], 
                         matrix[12], matrix[13], matrix[14], matrix[15]);
    }

    GMatrix44 transpose() {
        return GMatrix44(this->fMat[0], this->fMat[4], this->fMat[8], this->fMat[12],
                        this->fMat[1], this->fMat[5], this->fMat[9], this->fMat[13], 
                        this->fMat[2], this->fMat[6], this->fMat[10], this->fMat[14],
                        this->fMat[3], this->fMat[7], this->fMat[11], this->fMat[15]);
    }

    GMatrix33 submatrix(int row, int col) {
        float out[9];
        int index = 0;
        for(int i = 0; i < 4; i++) {
            if(row == i) continue; 
            for(int j = 0; j < 4; j++) {
                if(col == j) continue;
                out[index++] = this->fMat[(i<<2)+j];
            }
        }
        return GMatrix33(out[0], out[1], out[2], 
                         out[3], out[4], out[5],
                         out[6], out[7], out[8]);
    }

    float minor(int row, int col) {
        GMatrix33 m = this->submatrix(row, col);
        return m.det();
    }

    float cofactor(int row, int col) {
        if(G_INT_ISODD(row+col)) return -1*minor(row, col);
        else return minor(row, col);
    }

    float det() {
        return fMat[0]*this->cofactor(0, 0) + fMat[1]*this->cofactor(0, 1) + 
               fMat[2]*this->cofactor(0,2) + fMat[3]*this->cofactor(0, 3);
    }

    GMatrix44 inverse() {
        float det = this->det();
        if(G_FL_EQUAL(det, 0)) { return GMatrix44(); }
        
        float matrix[16];
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                matrix[i+(j<<2)] = this->cofactor(i, j) / det;
            }
        }

        return GMatrix44(matrix[0], matrix[1], matrix[2], matrix[3], 
                         matrix[4], matrix[5], matrix[6], matrix[7],
                         matrix[8], matrix[9], matrix[10], matrix[11], 
                         matrix[12], matrix[13], matrix[14], matrix[15]);
    }

private:
    float fMat[16]; 
};

#endif
