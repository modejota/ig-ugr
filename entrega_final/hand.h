#ifndef HAND_H
#define HAND_H

#include "objectPLYR.h"

class _hand {

public:

    _objectPLYR Mano;
    _hand();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_triangles_color();
    void draw_vertices_color();
    void draw_illumination_flat_shading();
    void draw_illumination_smooth_shading();

private:
    void draw(unsigned int mode);
};

#endif // HAND_H
