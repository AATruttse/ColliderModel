#include "Geometry.h"

inline bool segmentPlaneIntersection(const TVector3& _segment0,
                                     const TVector3& _segment1,
                                     const TVector3& _plane0,
                                     const TVector3& _plane1,
                                     const TVector3& _plane2,
                                     TVector3 *_pRes
                                    )
{
    return segmentPlaneIntersection(_segment0, _segment1, _plane0, _plane1.Cross(_plane2), _pRes);
}

inline bool segmentPlaneIntersection(const TVector3& _segment0,
                                     const TVector3& _segment1,
                                     const TVector3& _plane0,
                                     const TVector3& _planeNormal,
                                     TVector3 *_pRes
                                    )
{
    TVector3 u = _segment1 - _segment0;
    if (u * _planeNormal == 0)
    {
        return false;
    }
    
    Float_t s = (_planeNormal * (_plane0 - _segment0)) /  (_planeNormal * u);
    
    if ((s >= 0) && (s <= 1))
    {
        if (_pRes != 0)
        {
            *_pRes = _segment0 + (s * u);
        }
        
        return true;
    }
    
    return false;    
}
