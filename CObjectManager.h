#ifndef __COBJECTMANAGER_H__
#define __COBJECTMANAGER_H__

#include <list>

#include "Rtypes.h"

namespace ColliderModel {
    
    class CObject;
    
    typedef std::list<CObject*> objPointerList;
    typedef objPointerList::iterator objPointerListIter;

    // CObjectManager - singleton manager for all steppable object which steps all of them

    class CObjectManager {
        friend class CObject;
        
        private:
            objPointerList m_pObjects;
        
            CObjectManager() {};
            CObjectManager(const CObjectManager& _copy) {};
            CObjectManager& operator=(const CObjectManager& _copy) {};
            
            void addObject(CObject* _pObject);
            bool removeObject(CObject* _pObject);
                
        public:
            static CObjectManager& manager();
            void step(Double_t _dt);
                
    }; // CObjectManager
    
} // namespace ColliderModel
#endif // __COBJECTMANAGER_H__
