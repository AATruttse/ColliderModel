#include "CParticleFactory.h"
#include "CParticle.h"
#include <stdlib.h>
#include <iostream>

// may be it's better to put double x, y, z ???!!!
CParticle* CParticleFactory::createParticle(const EParticleType type, const CPosition &r, const CVelocity &v) const {
    CParticle *particle = new CParticle();      // may be better to put it into switch and use constructor !!!

    switch (type)
    {
        case EPtPion:
            // use CParticleBook !!!
            break;
        case EPtProton:
            // use CParticleBook !!!
            break;
        default:
            exit(15);   // if something goes wrong (how?)
    }
    particle->type = type;


    particle->r = r;
    particle->v = v;

    return particle;
}