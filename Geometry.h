#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "TVector3.h"

inline bool segmentPlaneIntersection(const TVector3& _segment0,
                                     const TVector3& _segment1,
                                     const TVector3& _plane0,
                                     const TVector3& _plane1,
                                     const TVector3& _plane2,
                                     TVector3 *_pRes = 0
                                    );

inline bool segmentPlaneIntersection(const TVector3& _segment0,
                                     const TVector3& _segment1,
                                     const TVector3& _plane0,
                                     const TVector3& _planeNormal,
                                     TVector3 *_pRes = 0
                                    );

#endif // __GEOMETRY_H__
