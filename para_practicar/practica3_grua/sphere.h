#ifndef SPHERE_H
#define SPHERE_H

#include "object3DR.h"

class _sphere:public _object3DR
{
public:
    _sphere(unsigned int perfiles, unsigned int puntos_perfil, float Size = 0.5);
};

#endif // SPHERE_H
