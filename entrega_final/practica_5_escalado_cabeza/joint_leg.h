#ifndef JOINT_H
#define JOINT_H

#include "sphere.h"

class _joint_leg {

public:
    _sphere Esfera;
    _joint_leg();

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

#endif // JOINT_H
