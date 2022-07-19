#ifndef BARRA_VERTICAL_H
#define BARRA_VERTICAL_H

#include "cube.h"

class _barra_vertical{
public:
    _cube Cubo;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);
};

#endif // BARRA_VERTICAL_H
