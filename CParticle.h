#include "CMovableObject.h"
#include "CVelocity.h"
#include "CPosition.h"

#ifndef CPARTICLE_H
#define CPARTICLE_H

enum EParticleType{EPtPion = 0, EPtProton = 1};                 //???

class CParticleFactory;             // ???

class CParticle : public CMovableObject {
private:
    CParticle() = default;
    CParticle(const CParticle &_c);
    CParticle &operator = (CParticle &_c);

    double m;
    double q;
    EParticleType type;                                                                                 //???

    CPosition r;
    CVelocity v;
public:

    virtual void step();

    double get_m() const;
    double get_q() const;
    EParticleType get_type() const;

    CPosition get_position() const;

    friend class CParticleFactory;
};

#endif // CPARTICLE_H
