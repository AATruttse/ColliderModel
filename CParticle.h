#include "CMovableObject.h"

#ifndef CPARTICLE_H
#define CPARTICLE_H

enum EParticleType{EPtPion = 0, EPtProton = 1};                 //???!!! where should it be?

class CParticleFactory;

class CParticle : public CMovableObject {
private:
    CParticle();
    CParticle(const CParticle &_c);
    CParticle &operator = (CParticle &_c);
    double m;
    double q;
    EParticleType type;                                                                                 //???!!!
public:

    virtual void step();

    double get_m() const;
    double get_q() const;
    EParticleType get_type() const;

    friend CParticleFactory;
};

#endif // CPARTICLE_H
