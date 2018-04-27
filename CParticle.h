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
	Int_t m_ID;
	Int_t m_ParentID;

        CParticle(const TString &_name, Int_t _ParentID = 0);
        CParticle(const TString &_name, const TVector3 &_pos, Int_t _ParentID = 0);
        CParticle(const TString &_name, const TVector3 &_pos, const TVector3 &_velocity, Int_t _ParentID = 0);
        CParticle(const CParticle &_copy);
        CParticle& operator=(CParticle &_copy);


    public:
	virtual ~CParticle();
        virtual bool step(Double_t _dt);

        TString name() const;
        Double_t m() const;
        Int_t q() const;
        Double_t hf() const;
        Int_t iD() const {return m_ID;}
        Int_t parentID() const {return m_ParentID;}

        friend class CParticleFactory;

    }; //class CParticle
    
} // namespace ColliderModel
#endif // __CPARTICLE_H__
