#ifndef BRAZO_ARRIBA_H
#define BRAZO_ARRIBA_H

#include "arm_bone.h"
#include "joint_arm.h"

class _brazo_arriba {

public:
    _arm_bone Cilindro;
    _joint_arm Rotula;
    _brazo_arriba();

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

#endif // BRAZO_ARRIBA_H
