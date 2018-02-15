#include "CParticle.h"

#ifndef CPARTICLEFACTORY_H
#define CPARTICLEFACTORY_H

class CParticleFactory {
private:

    CParticleFactory() = default;
    CParticleFactory(const CParticleFactory &_c);
    CParticleFactory &operator = (CParticleFactory &_c);
public:
    static CParticleFactory &getInstance() {
        static CParticleFactory  instance;
        return instance;
    }
    CParticle *createParticle(const EParticleType type, const CPosition &r, const CVelocity &v) const;                                 //???!!! into private?
};

#endif // CPARTICLEFACTORY_H
