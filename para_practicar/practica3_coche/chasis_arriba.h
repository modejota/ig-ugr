#ifndef CHASIS_ARRIBA_H
#define CHASIS_ARRIBA_H

#include "cube.h"

class _chasis_arriba{
public:
    _chasis_arriba(){}
    _cube Chasis;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);
};

#endif // CHASIS_ARRIBA_H
