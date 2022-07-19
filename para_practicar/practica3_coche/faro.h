#ifndef FARO_H
#define FARO_H

#include "cylinder.h"

class _faro {
public:
    _cylinder Faro;
    _faro();

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);
};

#endif // FARO_H
