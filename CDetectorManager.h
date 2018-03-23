#ifndef __CDETECTORMANAGER_H__
#define __CDETECTORMANAGER_H__

#include <list>

#include "TVector3.h"

#include "CParticle.h"

namespace ColliderModel
{
    class CDetector;
    
    typedef std::list<CDetector*>  pDetectorList;
    typedef pDetectorList::iterator  pDetectorListIter;
    typedef pDetectorList::const_iterator  pDetectorListConstIter;    
    
    class CDetectorManager {
    
        private:
            pDetectorList m_pDetectors;
            
            CDetectorManager() {}
            CDetectorManager(const CDetectorManager &_copy) {}
            CDetectorManager &operator=(CDetectorManager &_copy) {}
        
        public:
            static CDetectorManager& detectorManager();
            CDetector* createDetector(const TVector3 &_pos, const TVector3 &_size);
            
            const pDetectorList& detectors() {return m_pDetectors;}
            
            bool checkAll(const CParticle& _particle, const TVector3 &_newPos);
    }; // class CDetectorManager
    
} // namespace ColliderModel

#endif // __CDETECTORMANAGER_H__
