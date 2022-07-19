#ifndef BOARD_H
#define BOARD_H

#include "object3d.h"

class _board : public _object3D {
    public:
    _board(float Size=1.0, unsigned int casillas = 16);
};

#endif // BOARD_H
