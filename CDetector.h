#ifndef __CDETECTOR_H__
#define __CDETECTOR_H__

#include <list>

#include "TVector3.h"

#include "CObject.h"

namespace ColliderModel {

    class CParticle;
    
    struct SDetectorEvent
    {
        TString m_Type;
        
        Float_t m_Time;
        Float_t m_Mass;
        Float_t m_Charge;
        
        TVector3 m_Pos;
        TVector3 m_Velocity;
    };
    
    typedef std::list<SDetectorEvent> eventList;
    typedef eventList::iterator eventListIter;
    typedef eventList::const_iterator eventListConstIter;

    // CDetector - class for Particle Detectors
    
    class CDetector : public CObject {
    protected:
        TVector3 m_Pos;
        TVector3 m_Size;
        
        eventList m_EventList;

        CDetector();
        
        virtual bool addParticle(const CParticle &_particle, const TVector3 &_pos);        
        
    public:
        CDetector(const TVector3 &_pos, const TVector3 &_size);
        CDetector(const CDetector &_copy);
        
        CDetector& operator=(const CDetector &_copy);
            
        virtual void step(Double_t _dt);
        
        const TVector3& pos() const {return m_Pos;}
        const TVector3& size() const {return m_Size;}
        const eventList& events() const {return m_EventList;}
        void setPos(const TVector3 &_pos) {m_Pos = _pos;}
        void setSize(const TVector3 &_size) {m_Size = _size;}
        
        virtual bool check(const CParticle& _particle, const TVector3 &_newPos) const;
        virtual bool checkAdd(const CParticle& _particle, const TVector3 &_newPos);
    }; // CDetector

} // namespace ColliderModel

#endif // __CDETECTOR_H__
