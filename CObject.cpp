#include "CObject.h"
#include "CObjectManager.h"

namespace ColliderModel {

    CObject::CObject()
    {
        CObjectManager::manager().addObject(this);
    }
    
    CObject::~CObject()
    {
        CObjectManager::manager().removeObject(this);
    }
   
} // namespace ColliderModel
