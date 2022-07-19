#ifndef LOWER_MIDDLE_ARM_H
#define LOWER_MIDDLE_ARM_H

#include "hand.h"
#include "upper_middle_arm.h"

class _lower_middle_arm {
public:
    _hand Mano;
    _upper_middle_arm Antebrazo;
    _lower_middle_arm(){}

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

private:
    void draw(unsigned int mode);
};

#endif // LOWER_MIDDLE_ARM_H
