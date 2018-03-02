#include <algorithm>

#include "CObjectManager.h"
#include "CObject.h"

namespace ColliderModel {

    void CObjectManager::addObject(CObject* _pObject)
    {
        if (_pObject != 0)
        {
            m_pObjects.push_back(_pObject);
        }
    }
    
    bool CObjectManager::removeObject(CObject* _pObject)
    {
        if (_pObject != 0)
        {
            objPointerListIter foundIter = std::find(m_pObjects.begin(), m_pObjects.end(), _pObject);
            if (foundIter != m_pObjects.end())
            {
                m_pObjects.erase(foundIter);
                return true;
            }
        }
        
        return false;
    }
    
    CObjectManager& CObjectManager::manager()
    {
        static CObjectManager theManager;
        return theManager;
    }
                
    void CObjectManager::step(Double_t _dt)
    {
        for (objPointerListIter iter = m_pObjects.begin(); iter != m_pObjects.end(); iter++)
        {
            if (*iter != 0)
            {
                (*iter)->step(_dt);
            }
        }
    }
    
} // namespace ColliderModel
