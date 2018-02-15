#include "CCollider.h"

//changing time of system
void CCollider::Lstep(double dt) {
    t += dt;                            // do !!!
}

double CCollider::get_t() const{
    return t;
}
