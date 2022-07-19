#ifndef LOWER_LIMB_WITH_JOINT_H
#define LOWER_LIMB_WITH_JOINT_H


#include "lower_limb.h"
#include "joint_leg.h"

class _lower_limb_with_joint {

public:
    _lower_limb Pierna;
    _joint_leg Union;
    _lower_limb_with_joint(){}

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
#endif // LOWER_LIMB_WITH_JOINT_H
