#include <iostream>
#include "CCollider.h"
#include "CParticleFactory.h"

int main()
{
    CVector3 r;
    r.x = 1.0;
    r.y = 1.0;
    r.z = 1.0;

    CVelocity v1;
    v1.x = 1.0;
    v1.y = 1.0;
    v1.z = 1.0;

    CVelocity v2;
    v2.x = 1.0;
    v2.y = 1.0;
    v2.z = 1.0;
    CVelocity v = v1 + v1;

    v.show();

    /*CParticle *particle = CParticleFactory::getInstance().createParticle(EPtProton, r, v);
    CParticle *res_particle = CParticleFactory::getInstance().createParticle(EPtProton, r2, v + v);

    cout << particle->get_position().x << endl;
    cout << res_particle->get_position().x << endl;

    delete &CParticleFactory::getInstance();*/
    return 0;
}

