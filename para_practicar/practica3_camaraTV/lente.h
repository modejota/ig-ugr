#ifndef LENTE_H
#define LENTE_H

#include "cone.h"

class _lente : public _object3D{
public:
    _cone Lente;
    _lente();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    void draw(unsigned int mode);
};


#endif // LENTE_H
