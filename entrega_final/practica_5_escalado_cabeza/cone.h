#ifndef CONE_H
#define CONE_H

#include "object3DR.h"

class _cone:public _object3DR
{
public:
    _cone(unsigned int perfiles, unsigned int grados = 360, float Size = 1.0);
};

#endif // CONE_H
