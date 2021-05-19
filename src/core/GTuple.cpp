#include "include/core/GTuple.h"

float GTuple::magnitude() {
    return sqrt(this->fX * this->fX + this->fY * this->fY + this->fZ * this->fZ + this->fW * this->fW);
}

float GTuple::length() {
    return this->magnitude();
}

float GTuple::lengthSquared() {
    return this->dot(*this);
}

GTuple GTuple::normalize() {
    float magnitude = this->magnitude();
    GTuple fTuple;
    fTuple.fX = this->fX / magnitude;
    fTuple.fY = this->fY / magnitude;
    fTuple.fZ = this->fZ / magnitude;
    fTuple.fW = this->fW / magnitude;
    return fTuple;
}

GTuple GTuple::reflect(GTuple& normal) {
    return *this - normal * 2 * this->dot(normal);
}

float GTuple::dot(GTuple& rhs) {
    return this->fX * rhs.fX + this->fY * rhs.fY + this->fZ * rhs.fZ;
}

GTuple GTuple::cross(GTuple& rhs) {
    return GTuple( this->fY * rhs.fZ - this->fZ * rhs.fY,
                   this->fZ * rhs.fX - this->fX * rhs.fZ,
                   this->fX * rhs.fY - this->fY * rhs.fX );
}

GTuple GTuple::operator+(const GTuple& rhs) {
    GTuple fTuple;
    fTuple.fX = this->fX + rhs.fX;
    fTuple.fY = this->fY + rhs.fY;
    fTuple.fZ = this->fZ + rhs.fZ;
    fTuple.fW = this->fW + rhs.fW;
    return fTuple;
}

GTuple GTuple::operator-(const GTuple& rhs) {
    GTuple fTuple;
    fTuple.fX = this->fX - rhs.fX;
    fTuple.fY = this->fY - rhs.fY;
    fTuple.fZ = this->fZ - rhs.fZ;
    fTuple.fW = this->fW - rhs.fW;
    return fTuple;
} 

GTuple GTuple::operator-()
{
    GTuple fTuple;
    fTuple.fX = -this->fX;
    fTuple.fY = -this->fY;
    fTuple.fZ = -this->fZ;
    fTuple.fW = -this->fW;
    return fTuple;
}

GTuple GTuple::operator/(const float& rhs) {
    GTuple fTuple;
    fTuple.fX = this->fX / rhs ;
    fTuple.fY = this->fY / rhs;
    fTuple.fZ = this->fZ / rhs;
    fTuple.fW = this->fW / rhs;
    return fTuple;
}

GTuple GTuple::operator*(const float& rhs) {
    GTuple fTuple;
    fTuple.fX = this->fX * rhs ;
    fTuple.fY = this->fY * rhs;
    fTuple.fZ = this->fZ * rhs;
    fTuple.fW = this->fW * rhs;
    return fTuple;
} 

GTuple GTuple::operator*(const GTuple& rhs) {
    GTuple fTuple;
    fTuple.fX = this->fX * rhs.x();
    fTuple.fY = this->fY * rhs.y();
    fTuple.fZ = this->fZ * rhs.z();
    fTuple.fW = this->fW * rhs.w();
    return fTuple;
} 