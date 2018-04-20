#ifndef __CMOVABLEOBJECT_H__
#define __CMOVABLEOBJECT_H__

#include "TVector3.h"

#include "CObject.h"

namespace ColliderModel {

    // CMovableObject - base class for all objects with position and speed
    
    class CMovableObject : public CObject {
    protected:
        TVector3 m_Pos;
        TVector3 m_Velocity;
        
    public:
        CMovableObject();
        CMovableObject(const TVector3 &_pos);
        CMovableObject(const TVector3 &_pos, const TVector3 &_velocity);
        CMovableObject(const CMovableObject &_copy);
        
        CMovableObject& operator=(const CMovableObject &_copy);
            
        virtual bool step(Double_t _dt);
        
        const TVector3& pos() const {return m_Pos;}
        const TVector3& velocity() const {return m_Velocity;}
        void setPos(const TVector3 &_pos) {m_Pos = _pos;}
        void setVelocity(const TVector3 &_velocity) {m_Velocity = _velocity;}
        
    }; // CMovableObject

} // namespace ColliderModel

#endif // __CMOVABLEOBJECT_H__
