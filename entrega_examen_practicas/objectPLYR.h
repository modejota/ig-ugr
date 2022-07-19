#ifndef OBJECTPLYR_H
#define OBJECTPLYR_H

#include "file_ply_stl.h"
#include "object3DR.h"

class _objectPLYR:public _object3DR
{
public:
    _objectPLYR();
    void cargarPLYR(const string &ruta);
};

#endif // OBJECTPLYR_H
