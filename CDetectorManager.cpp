#include "CDetectorManager.h"
#include "CDetector.h"

namespace ColliderModel
{
    CDetectorManager& CDetectorManager::detectorManager() {
            static CDetectorManager manager;
            return manager;
        }
        
    CDetector* CDetectorManager::createDetector(const TVector3 &_pos, const TVector3 &_size)
    {
        CDetector* pDetector = new CDetector(_pos, _size);
        m_pDetectors.push_back(pDetector);
        return pDetector;
    }
    
    bool CDetectorManager::checkAll(const CParticle& _particle, const TVector3 &_newPos)
    {
        return false;
    }
} // namespace ColliderModel
