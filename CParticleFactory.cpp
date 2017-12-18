#include "CParticleFactory.h"
#include "CParticle.h"
#include <stdlib.h>

//CParticleFactory *CParticleFactory::p_instance = 0;

CParticle* CParticleFactory::createParticle(const EParticleType type) const {
    CParticle *particle;
    switch (type)
    {
        case EPtPion:
            particle = new CParticle();
            // use CParticleBook
            break;
        case EPtProton:
            particle = new CParticle();
            // use CParticleBook
            break;
        default:
            exit(15);   // if something goes wrong (how?)
    }
    particle->type = type;
    return particle;
}