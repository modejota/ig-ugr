#ifndef CHASIS_COMPLETO_H
#define CHASIS_COMPLETO_H

#include "faros.h"
#include "chasis_abajo.h"
#include "chasis_arriba.h"

class _chasis_completo {
public:
    _faros Faros;
    _chasis_abajo  Chasis_abajo;
    _chasis_arriba Chasis_arriba;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}
private:
    void draw(unsigned int mode);
};

#endif // CHASIS_COMPLETO_H
