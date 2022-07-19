#ifndef CAJA_H
#define CAJA_H

#include "cube.h"

class _caja : public _object3D{
public:
    _cube Caja;
    _caja(){}

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    void draw(unsigned int mode);
};

#endif // CAJA_H
