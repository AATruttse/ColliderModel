#include "CVector3.h"
#include <iostream>

/*CVector3::CVector3(double x, double y, double z) {    // do this !!!
    this->x = x;
    this->y = y;
    this->z = z;
}*/

CVector3 &CVector3::operator = (const CVector3 &v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;

    return *this;
}

// multiplying by a real number
CVector3 &CVector3::operator * (const double a) {       // returns only CVector3 and can't return CVelocity !!!
    this->x = a*x;
    this->y = a*y;
    this->z = a*z;

    return *this;
}

void CVector3::show() const {
    std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
}

/*CVector3 &CVector3::operator + (const CVector3 &v1, const CVector3 &v2) {     // do this !!!
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;

    return *this;
}*/
