#ifndef OTROS_OBJETOS_H
#define OTROS_OBJETOS_H

#include "object3DR.h"

class _peon:public _object3DR
{
public:
    _peon(unsigned int perfiles,unsigned int grados = 360);
};

//

class _copa:public _object3DR
{
public:
    _copa(unsigned int perfiles,unsigned int grados = 360);
};

//

class _copa_reves:public _object3DR
{
public:
    _copa_reves(unsigned int perfiles,unsigned int grados = 360);
};


//

class _hormigonera:public _object3DR
{
public:
    _hormigonera(unsigned int perfiles,unsigned int grados = 360);
};



#endif // OTROS_OBJETOS_H
