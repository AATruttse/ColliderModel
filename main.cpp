#include <iostream>
#include <ctime>

#include "TVector3.h"
#include "TRandom.h"

#include "CCollider.h"
#include "CMovableObject.h"

#include "CParticleBook.h"
#include "CFissionBook.h"

#include "CParticle.h"
#include "CParticleFactory.h"

using namespace ColliderModel;

int main()	// doesn't erays everithing that needed! (?)
{
    gRandom->SetSeed(time(NULL));	// set seed!
    TVector3 r1, r2;

    r1.SetX(1.0);
    r1.SetY(2.0);
    r1.SetZ(3.0);

    r2.SetX(1.0);
    r2.SetY(1.0);
    r2.SetZ(1.0);
    
    CFissionBook::getInstance().updateData("FissionData");
    CParticleBook::getInstance().updateData("ParticleData");

    CParticle *pParticle = CParticleFactory::particleFactory().createParticle("PI_ZERO", r1, r2);

    CCollider::collider().setStep(0.001);
    for (int i = 0; i < 5; i++)
    {
	std::cout << "step is " << i << " ------------------------------------------------------------" << std::endl;
	CParticleFactory::particleFactory().show();
        CCollider::collider().step();
    }

    // delete all particles
    CParticleFactory::particleFactory().clean();

    /*CParticle *particle = CParticleFactory::getInstance().createParticle(EPtProton, r, v);
    CParticle *res_particle = CParticleFactory::getInstance().createParticle(EPtProton, r2, v + v);

    cout << particle->get_position().x << endl;
    cout << res_particle->get_position().x << endl;

    delete &CParticleFactory::getInstance();*/
    return 0;
}

