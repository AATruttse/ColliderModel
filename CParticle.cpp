#include "CParticle.h"

namespace ColliderModel
{
    CParticle::CParticle() :
        CMovableObject()
    {
    }

    CParticle::CParticle(const TVector3 &_pos) :
        CMovableObject(_pos)
    {
    }

    CParticle::CParticle(const TVector3 &_pos, const TVector3 &_velocity) :
        CMovableObject(_pos, _velocity)
    {
    }

    CParticle::CParticle(const CParticle &_copy) :
        CMovableObject(_copy)
    {
    }

    CParticle& CParticle::operator=(CParticle &_copy)
    {
        CMovableObject::operator=(_copy);
    }

    void CParticle::step(Double_t _dt)
    {
        CMovableObject::step(_dt);
    }

    Double_t CParticle::m() const
    {
        return 0.0;
    }
    
    Double_t CParticle::q() const
    {
        return 0.0;
    }
    
} // namespace ColliderModel
