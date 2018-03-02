#include "TVector3.h"

#include "CParticleFactory.h"
#include "CParticle.h"

namespace ColliderModel
{
    CParticleFactory& CParticleFactory::particleFactory() {
            static CParticleFactory factory;
            return factory;
        }
        
    CParticle* CParticleFactory::createParticle(const TVector3 &_pos, const TVector3 &_velocity) const
    {
        CParticle* pParticle = new CParticle(_pos, _velocity);
        return pParticle;
    }
} // namespace ColliderModel
