#include "CParticle.h"
#include "CParticleFactory.h"
#include "CObjectManager.h"
#include "CParticleBook.h"
#include "CFissionBook.h"
#include "CCollider.h"
#include <cmath>
#include "TRandom.h"
#include <iostream>	// for some outputs

namespace ColliderModel
{
    CParticle::CParticle(const TString &_name) :
        CMovableObject()
    {
    }

    CParticle::CParticle(const TString &_name, const TVector3 &_pos) :
        CMovableObject(_pos)
    {
    }

    CParticle::CParticle(const TString &_name, const TVector3 &_pos, const TVector3 &_velocity) :
        CMovableObject(_pos, _velocity)
    {
        CParticleData data = CParticleBook::getInstance().getData(_name);
        m_Name = _name;
        m_Mass = data.pMass;
        m_Charge = data.pCharge;
        m_hf = data.pHalfLife;
        is_Created = 1;
    }

    CParticle::CParticle(const CParticle &_copy) :
        CMovableObject(_copy)
    {
    }

    CParticle& CParticle::operator=(CParticle &_copy)
    {
        CMovableObject::operator=(_copy);
    }

    bool CParticle::step(Double_t _dt)
    {
        CMovableObject::step(_dt);
        
	// if the particle was create during this step, it won't have a decay
        if (is_Created) {
             is_Created = 0;
             return 0;
        }

        std::vector<CFissionData> fissData = CFissionBook::getInstance().getData(m_Name);	     			// Get information about scenarios of fission    				                                   	        
	Double_t prob = gRandom->Rndm();	// may be better to add seed to generator
        for(std::vector<CFissionData>::iterator it = fissData.begin(); it != fissData.end(); it++) {
		printf("prob = %f, I will decay if it is bigger then %f", prob, (*it).fProbability * CCollider::collider().getStep());        
		if (prob > (*it).fProbability * CCollider::collider().getStep()) {						// if fission occurs
                   Int_t n = (*it).fShatters.size();									// amount of shatters
                   std::vector<CParticle*> shat;									// vector where shatters will be collected

		   Double_t E = m_Mass*m_Velocity*m_Velocity/2;
		   Double_t checkE = E; 		// to check coservation law
                   for (Int_t i = 0; i < n - 1; i++) {
			 Double_t E_new = gRandom->Rndm() * E;		// Energy of the new particle
			 Double_t vsqr = 2 * E_new / CParticleBook::getInstance().getData((*it).fShatters[i]).pMass;
			 // may be better to unite following actions!
			 Double_t vx_sqr = gRandom->Rndm() * vsqr;						
                         Double_t vy_sqr = gRandom->Rndm() * (vsqr - vx_sqr);
			 Double_t vz_sqr = vsqr - vx_sqr - vy_sqr;
			 Double_t vx = (gRandom->Integer(2)*2 - 1)*sqrt(vx_sqr);
			 Double_t vy = (gRandom->Integer(2)*2 - 1)*sqrt(vy_sqr);
			 Double_t vz = (gRandom->Integer(2)*2 - 1)*sqrt(vz_sqr);
                         TVector3 vel(vx, vy, vz);	// we also need velocities < 0, so we need some random of -1 or 1!
                         shat.push_back(CParticleFactory::particleFactory().createParticle((*it).fShatters[i], m_Pos, vel));   // remember shatters
			 E -= E_new;
                   }

                   // now find total momentum to determin momentum of the last particle
		   Double_t partE = 0;
                   TVector3 totalMomentum;										// total momentum
                   for (std::vector<CParticle*>::iterator iter = shat.begin(); iter != shat.end() - 1; iter++) {
                         totalMomentum += (*iter)->m_Velocity * (*iter)->m_Mass;
			 partE += (*iter)->m_Mass*(*iter)->m_Velocity*(*iter)->m_Velocity/2;
                   }
		   
		   TVector3 vLast = -totalMomentum*(1.0/CParticleBook::getInstance().getData((*it).fShatters[n - 1]).pMass);	// velocity of the last particle
                   CParticleFactory::particleFactory().createParticle((*it).fShatters[n - 1], m_Pos, vLast);	// creation of the last particle
		   // check of laws of conservation
		   partE += CParticleBook::getInstance().getData((*it).fShatters[n - 1]).pMass*vLast*vLast/2;
		   if (fabs(E - partE) > E*0.0001) {
			std::cout << "no conservation of energy!" << std::endl;
		   }            
		   // here we need check for momentum!     
		
                   return 1;
		}
        }

	return 0;      
    }

    TString CParticle::name() const
    {
        return m_Name;
    }

    Double_t CParticle::m() const
    {
        return m_Mass;
    }
    
    Int_t CParticle::q() const
    {
        return m_Charge;
    }
    
    Double_t CParticle::hf() const
    {
        return m_hf;
    }
} // namespace ColliderModel
