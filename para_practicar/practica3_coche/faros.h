#ifndef FAROS_H
#define FAROS_H

#include "faro.h"

class _faros {
public:
    _faro Faro;
    _faros(){}

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);
};

#endif // FAROS_H
