#ifndef SPHERE_H
#define SPHERE_H

#include "object3DR.h"

class _sphere:public _object3DR
{
public:
    _sphere(unsigned int perfiles, unsigned int puntos_perfil, unsigned int grados = 360, float Size = 0.5);

    void calcular_normales();   //@Override

};

#endif // SPHERE_H
