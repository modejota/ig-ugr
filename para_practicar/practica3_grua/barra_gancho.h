#ifndef BARRA_GANCHO_H
#define BARRA_GANCHO_H

#include "gancho.h"
#include "barra.h"

class _barra_gancho{
public:
    _gancho Gancho;
    _barra Barra;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);

};

#endif // BARRA_GANCHO_H
