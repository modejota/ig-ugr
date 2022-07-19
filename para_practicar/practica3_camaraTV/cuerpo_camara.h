#ifndef CUERPO_CAMARA_H
#define CUERPO_CAMARA_H

#include "caja.h"
#include "lente.h"

class _cuerpo_camara : public _object3D{
public:
    _caja Caja;
    _lente Lente;

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    void draw(unsigned int mode);
};

#endif // CUERPO_CAMARA_H
