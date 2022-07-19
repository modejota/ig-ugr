#ifndef BOTH_EYES_H
#define BOTH_EYES_H

#include "eye.h"

class _both_eyes {

public:
    _eye Ojo;
    _both_eyes(){}

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

#endif // BOTH_EYES_H
