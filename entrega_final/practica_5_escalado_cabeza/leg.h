#ifndef LEG_H
#define LEG_H

#include "cylinder.h"

class _leg {
public:

    _cylinder Cilindro;

    _leg();

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

#endif // LEG_H
