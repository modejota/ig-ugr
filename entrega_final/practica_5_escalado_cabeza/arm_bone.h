#ifndef ARM_BONE_H
#define ARM_BONE_H

#include "cylinder.h"

class _arm_bone {

public:
    _cylinder Cilindro;
    _arm_bone();

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
#endif // ARM_BONE_H
