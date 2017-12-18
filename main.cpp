#include <iostream>
#include "CCollider.h"
#include "CParticleFactory.h"

int main()
{
    CParticle *particle = CParticleFactory::getInstance().createParticle(EPtPion);

    delete &CParticleFactory::getInstance();
    return 0;
}

