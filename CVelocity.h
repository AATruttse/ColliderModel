#ifndef CVELOCITY_H
#define CVELOCITY_H
#include "CVector3.h"

class CVelocity: public CVector3 {
public:
    CVelocity() = default;
    CVelocity(const CVector3 &_copy) : CVector3(_copy) {

    }
};

#endif // CVELOCITY_H
