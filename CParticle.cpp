#include "CParticle.h"
#include <iostream>

double CParticle::get_m() const {
    return m;
}

double CParticle::get_q() const {
    return q;
}

EParticleType CParticle::get_type() const {
    return type;
}

CPosition CParticle::get_position() const {
    return r;
}

void CParticle::step() {
    CMovableObject::step();     // do !!!
}
