#ifndef AGARRE_H
#define AGARRE_H

#include "paletilla.h"

class _agarre{
public:
    _paletilla Pieza;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);
};

#endif // AGARRE_H
