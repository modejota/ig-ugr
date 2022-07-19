#ifndef MIDDLE_ARM_H
#define MIDDLE_ARM_H

#include "joint_arm.h"
#include "antebrazo.h"

class _upper_middle_arm {
public:
    _joint_arm Union;
    _antebrazo Antebrazo;
    _upper_middle_arm(){}

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    void draw(unsigned int mode);
};


#endif // MIDDLE_ARM_H
