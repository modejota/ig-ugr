#ifndef OBJECTPLY_H
#define OBJECTPLY_H

#include "file_ply_stl.h"
#include "object3d.h"

class _objectPLY:public _object3D
{
public:
    _objectPLY();
    void cargarPLY(const string &ruta);
};

#endif // OBJECTPLY_H
