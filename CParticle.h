#ifndef __CPARTICLE_H__
#define __CPARTICLE_H__

#include "CMovableObject.h"

namespace ColliderModel
{
    class CParticleFactory;

    class CParticle : public CMovableObject {

    private:
        TString m_Name;
        Double_t m_Mass;
        Int_t m_Charge;
        Double_t m_hf;
        bool is_Created;		// 1 if particle was created recently

        CParticle(const TString &_name);
        CParticle(const TString &_name, const TVector3 &_pos);
        CParticle(const TString &_name, const TVector3 &_pos, const TVector3 &_velocity);
        CParticle(const CParticle &_copy);
        CParticle& operator=(CParticle &_copy);

    public:
        virtual bool step(Double_t _dt);

        TString name() const;
        Double_t m() const;
        Int_t q() const;
        Double_t hf() const;

        friend class CParticleFactory;

    }; //class CParticle
    
} // namespace ColliderModel
#endif // __CPARTICLE_H__
