#ifndef EYE_H
#define EYE_H

#include "cylinder.h"

class _eye {

public:
    _cylinder Eye;
    _eye();

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

#endif // EYE_H
