#ifndef OBJECTR_H
#define OBJECTR_H

#include "object3d.h"

class _object3DR:public _object3D
{
public:
    _object3DR();
    void revolucion(unsigned int divisiones, unsigned int grados);
    _vertex3f RotarPunto(_vertex3f vertice, char eje, double angulo);

};

#endif // OBJECTR_H
