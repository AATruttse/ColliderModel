#include "CObject.h"

#ifndef CMOVABLEOBJECT_H
#define CMOVABLEOBJECT_H

class CMovableObject : public CObject {
public:
    CMovableObject();

    virtual void step();
};

#endif // CMOVABLEOBJECT_H
