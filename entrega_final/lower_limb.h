#ifndef FOREARM_H
#define FOREARM_H

#include "cube.h"
#include "cylinder.h"
#include "foot.h"
#include "leg.h"


class _lower_limb {

public:

    _foot Pie;
    _leg Pata;
    _lower_limb();

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


#endif // FOREARM_H
