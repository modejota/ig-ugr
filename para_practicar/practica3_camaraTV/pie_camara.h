#ifndef PIE_CAMARA_H
#define PIE_CAMARA_H

#include "cylinder.h"

class _pie_camara : public _object3D{
public:
    _cylinder Pie;
    _pie_camara();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    void draw(unsigned int mode);
};

#endif // PIE_CAMARA_H
