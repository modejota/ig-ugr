#ifndef HEAD_H
#define HEAD_H

#include "cube.h"

class _head {

public:
    _cube Cabeza;
    _head(){}

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

#endif // HEAD_H
