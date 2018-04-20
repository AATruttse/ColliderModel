#ifndef __CCOLLIDER_H__
#define __CCOLLIDER_H__

#include <iostream>
#include "Rtypes.h"

namespace ColliderModel {

    class CCollider {
        private:
            Double_t m_T;
            Double_t m_Step;

            CCollider() {};
            CCollider(const CCollider& _copy) {};
            CCollider& operator= (const CCollider& _copy) {};
    
        public:
            static CCollider& collider();

            Double_t t() const {return m_T;}
            Double_t time() const {return t();}
            Double_t getStep() const {return m_Step;}
            
            void setStep(const Double_t _step) { m_Step = _step;}
            
            Double_t step();
            Double_t step(const Double_t _dt);
    };

}
#endif // __CCOLLIDER_H__
