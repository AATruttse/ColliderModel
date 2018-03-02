#ifndef __COBJECT_H__
#define __COBJECT_H__

#include "Rtypes.h"

namespace ColliderModel {

    // CObject - base class for all steppable object

    class CObject {
    public:
        CObject();
        ~CObject();
        
        virtual void step(Double_t _dt) = 0;
    }; // CObject
    
} // namespace ColliderModel
#endif // __COBJECT_H__

