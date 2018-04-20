#include <iostream>

#include "TVector3.h"
#include "TRandom.h"

#include "CCollider.h"
#include "CMovableObject.h"

#include "CParticleBook.h"
#include "CFissionBook.h"

#include "CParticle.h"
#include "CParticleFactory.h"

using namespace ColliderModel;

int main()
{
    gRandom->SetSeed();
    TVector3 r1, r2;

    r1.SetX(1.0);
    r1.SetY(2.0);
    r1.SetZ(3.0);

    r2.SetX(1.0);
    r2.SetY(1.0);
    r2.SetZ(1.0);
    
    const TString str = "ELECTRON";
    
    CFissionBook::getInstance().updateData("FissionData");
    CParticleBook::getInstance().updateData("ParticleData");

    CParticle *pParticle = CParticleFactory::particleFactory().createParticle(str, r1, r2);

    CCollider::collider().setStep(0.001);
    for (int i = 0; i < 15; i++)
    {
	// printf("current step is %d", i);
	CParticleFactory::particleFactory().show();
        CCollider::collider().step();
    }

    std::cout << pParticle->pos().x() << " " << pParticle->pos().y() << " " << pParticle->pos().z() << std::endl;
    delete pParticle;

    /*CParticle *particle = CParticleFactory::getInstance().createParticle(EPtProton, r, v);
    CParticle *res_particle = CParticleFactory::getInstance().createParticle(EPtProton, r2, v + v);

    cout << particle->get_position().x << endl;
    cout << res_particle->get_position().x << endl;

    delete &CParticleFactory::getInstance();*/
    return 0;
}

