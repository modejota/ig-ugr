#ifndef CYLINDER_H
#define CYLINDER_H

#include "object3DR.h"

class _cylinder:public _object3DR
{
public:
    _cylinder(unsigned int perfiles, float Size = 1.0);
};

#endif // CYLINDER_H
