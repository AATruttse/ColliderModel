#ifndef __CPARTICLE_H__
#define __CPARTICLE_H__

#include "CMovableObject.h"

namespace ColliderModel
{
    class CParticleFactory;

    class CParticle : public CMovableObject {

    private:
        CParticle();
        CParticle(const TVector3 &_pos);
        CParticle(const TVector3 &_pos, const TVector3 &_velocity);
        CParticle(const CParticle &_copy);
        CParticle& operator=(CParticle &_copy);

    public:
        virtual void step(Double_t _dt);

        Double_t m() const;
        Double_t q() const;

        friend class CParticleFactory;

    }; //class CParticle
    
} // namespace ColliderModel
#endif // __CPARTICLE_H__
