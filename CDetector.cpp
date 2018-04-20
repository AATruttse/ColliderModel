#include "CDetector.h"

#include "CCollider.h"
#include "CParticle.h"

namespace ColliderModel {

    CDetector::CDetector() :
        CObject(),
        m_Pos(0.0, 0.0, 0.0),
        m_Size(1.0, 1.0, 1.0)
    {
    };
    
    CDetector::CDetector(const TVector3 &_pos, const TVector3 &_size) :
        CObject(),
        m_Pos(_pos),
        m_Size(_size)
    {
    };

    CDetector::CDetector(const CDetector &_copy) : 
        CObject(),
        m_Pos(_copy.m_Pos),
        m_Size(_copy.m_Size)
    
    {
    }
        
    CDetector& CDetector::operator=(const CDetector &_copy)
    {
        m_Pos = _copy.m_Pos;
        m_Size = _copy.m_Size;
        
        m_EventList.clear();
        
    }
    
    bool CDetector::step(Double_t _dt)
    {
    }
    
    bool CDetector::addParticle(const CParticle &_particle, const TVector3 &_pos)
    {
       
        SDetectorEvent newEvent;
        
        newEvent.m_Time = CCollider::collider().time();
        newEvent.m_Mass = _particle.m();
        newEvent.m_Charge = _particle.q();
        newEvent.m_Pos = _pos;
        newEvent.m_Velocity = _particle.velocity();
               
        
        m_EventList.push_back(newEvent);
        
        return true;
        
    }
    
    bool CDetector::check(const CParticle& _particle, const TVector3 &_newPos) const
    {
        return true;
    }
    
    bool CDetector::checkAdd(const CParticle& _particle, const TVector3 &_newPos)
    {

        if (check(_particle, _newPos))
        {
            return addParticle(_particle, _particle.pos());
        }
        
        return false;
        
        
    }
} // namespace ColliderModel
