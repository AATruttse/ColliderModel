#include "CParticle.h"
#include <iostream>

CParticle::CParticle() {
}

double CParticle::get_m() const {
    return m;
}

double CParticle::get_q() const {
    return q;
}

EParticleType CParticle::get_type() const {
    return type;
}

void CParticle::step() {
    CMovableObject::step();
}
