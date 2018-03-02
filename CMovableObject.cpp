#include "CMovableObject.h"

namespace ColliderModel {

    CMovableObject::CMovableObject() :
        CObject(),
        m_Pos(0.0, 0.0, 0.0),
        m_Velocity(0.0, 0.0, 0.0)
    {
    };
    
    CMovableObject::CMovableObject(const TVector3 &_pos) :
        CObject(),
        m_Pos(_pos),
        m_Velocity(0.0, 0.0, 0.0)
    {
    };
    
    CMovableObject::CMovableObject(const TVector3 &_pos, const TVector3 &_velocity) :
        CObject(),
        m_Pos(_pos),
        m_Velocity(_velocity)
    {
    };

    CMovableObject::CMovableObject(const CMovableObject &_copy) : 
        CObject(),
        m_Pos(_copy.m_Pos),
        m_Velocity(_copy.m_Velocity)
    
    {
    }
        
    CMovableObject& CMovableObject::operator=(const CMovableObject &_copy)
    {
        m_Pos = _copy.m_Pos;
        m_Velocity = _copy.m_Velocity;
        
    }
            
    void CMovableObject::step(Double_t _dt)
    {
        m_Pos += m_Velocity * _dt;
        
    }
    
} // namespace ColliderModel
