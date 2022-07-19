#ifndef BASE_H
#define BASE_H

#include "cylinder.h"

class _base : public _object3D {
public:
    _cylinder Base;
    _base();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    void draw(unsigned int mode);

};

#endif // BASE_H
