#ifndef BOTH_ZS_H
#define BOTH_ZS_H

#include "chestZ.h"

class _both_Z  {
public:
    _chest_z front_Z;

    _both_Z(){}

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

#endif // BOTH_ZS_H
