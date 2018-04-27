#include "CParticle.h"
#include "CParticleFactory.h"
#include "CObjectManager.h"
#include "CParticleBook.h"
#include "CFissionBook.h"
#include "CCollider.h"
#include "CObjectManager.h"
#include <cmath>
#include "TRandom.h"
#include <iostream>	// for some outputs

namespace ColliderModel
{
    CParticle::CParticle(const TString &_name, Int_t _ParentID) :
        CMovableObject(), m_ParentID(_ParentID)
    {
    }

    CParticle::CParticle(const TString &_name, const TVector3 &_pos, Int_t _ParentID) :
        CMovableObject(_pos), m_ParentID(_ParentID)
    {
    }

    CParticle::CParticle(const TString &_name, const TVector3 &_pos, const TVector3 &_velocity, Int_t _ParentID) :
        CMovableObject(_pos, _velocity), m_ParentID(_ParentID)
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

    bool CParticle::step(Double_t _dt)		// creates two particles instead of one
    {
	// if the particle was create during this step, it won't be stepped
        if (is_Created) {
             is_Created = 0;

             return 0;
        }
	
        CMovableObject::step(_dt);

        //std::cout << "hi" << std::endl;
        std::vector<CFissionData> fissData = CFissionBook::getInstance().getData(m_Name);	     			// Get information about scenarios of fission    				                                   	        
	Double_t prob = gRandom->Rndm();	// may be better to add seed to generator
        for(std::vector<CFissionData>::iterator it = fissData.begin(); it != fissData.end(); it++) {
		// need to reconsider the way we choose which decay occurs!    
		if (prob < (*it).fProbability) {						// if fission occurs
                   Int_t n = (*it).fShatters.size();
                   std::vector<CParticle*> shat;
		   Double_t E = m_Mass*m_Velocity*m_Velocity/2;
		   Double_t checkE = E; 		// to check coservation law
		   Double_t partE = 0.0;
                   for (Int_t i = 0; i < n - 1; i++) {
			 Double_t E_new = gRandom->Rndm() * E;		// Energy of the new particle
			 Double_t vsqr = 2 * E_new / CParticleBook::getInstance().getData((*it).fShatters[i]).pMass;
			 // may be better to unite following actions!
			 Double_t vx_sqr = gRandom->Rndm() * vsqr;					
                         Double_t vy_sqr = gRandom->Rndm() * (vsqr - vx_sqr);
			 Double_t vz_sqr = vsqr - vx_sqr - vy_sqr;
			 Double_t vx = (gRandom->Integer(2)*2 - 1.0)*sqrt(vx_sqr);
			 Double_t vy = (gRandom->Integer(2)*2 - 1.0)*sqrt(vy_sqr);
			 Double_t vz = (gRandom->Integer(2)*2 - 1.0)*sqrt(vz_sqr);
                         TVector3 vel(vx, vy, vz);	// we also need velocities < 0, so we need some random of -1 or 1!
                         shat.push_back(CParticleFactory::particleFactory().createParticle((*it).fShatters[i], m_Pos, vel, m_ID));   // remember shatters
			 std::cout << " by " << this << std::endl;
			 E -= E_new;
                   }
                   // now find total momentum to determin momentum of the last particle
                   TVector3 totalMomentum(0.0, 0.0, 0.0);				// total momentum
                   for (std::vector<CParticle*>::iterator iter = shat.begin(); iter != shat.end(); iter++) {
                   	totalMomentum += (*iter)->m_Velocity * (*iter)->m_Mass;
		   	partE += (*iter)->m_Mass*(*iter)->m_Velocity*(*iter)->m_Velocity/2;
		   }
		   TVector3 vLast = m_Mass*m_Velocity-totalMomentum*(1.0/CParticleBook::getInstance().getData((*it).fShatters[n - 1]).pMass);	// velocity of the last particle
                   CParticleFactory::particleFactory().createParticle((*it).fShatters[n - 1], m_Pos, vLast, m_ID);	// creation of the last particle
		   partE += CParticleBook::getInstance().getData((*it).fShatters[n - 1]).pMass*vLast*vLast/2;
		   std::cout << " by " << this  << std::endl;
		   // check of laws of conservation
		   if (fabs(checkE - partE) > checkE*0.01) {
			std::cout << "no conservation of energy: " << fabs(checkE - partE) << " > " << checkE*0.01 << std::endl;
		   }            
		   // here we need check for momentum!
		   // and may be others (charge and so on)!    
		
		   delete this;
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

    CParticle::~CParticle() {
	CParticleFactory::particleFactory().removeParticle(this);
    }

} // namespace ColliderModel
