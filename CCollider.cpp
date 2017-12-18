#include "CCollider.h"

//CCollider *CCollider::p_instance = 0;

//changing time of system
void CCollider::Lstep(double dt) {
    t += dt;
}

double CCollider::get_t() const{
    return t;
}
