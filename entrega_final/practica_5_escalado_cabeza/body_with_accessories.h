#ifndef BODY_WITH_ACCESSORIES_H
#define BODY_WITH_ACCESSORIES_H

#include "body.h"
#include "both_Zs.h"

class _body_with_accessories {

public:
    _body Pecho;
    _both_Z front_Z;

    _body_with_accessories(){}

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

#endif // BODY_WITH_ACCESSORIES_H
