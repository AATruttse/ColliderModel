#include "CCollider.h"
#include "CObjectManager.h"

namespace ColliderModel {
    
    CCollider& CCollider::collider()
    {
        static CCollider collider;
        return collider;        
    }
    
    Double_t CCollider::step()
    {
        return step(m_Step);
    }
    
    Double_t CCollider::step(const Double_t _dt)
    {
        CObjectManager::manager().step(_dt);
        m_T += _dt;
        return m_T;
    }
    
} // namespace ColliderModel
