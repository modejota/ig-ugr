#ifndef GANCHO_H
#define GANCHO_H

#include "agarre.h"
#include "cajetilla.h"

class _gancho{
public:
    _cajetilla Caja;
    _agarre Chapas;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);
};

#endif // GANCHO_H
