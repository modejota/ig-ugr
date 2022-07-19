#ifndef PIVOTE_H
#define PIVOTE_H

#include "base.h"
#include "barra_vertical.h"

class _pivote{
public:
    _base Base;
    _barra_vertical Barra;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);
};

#endif // PIVOTE_H
