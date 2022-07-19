#ifndef PARTE_ARRIBA_H
#define PARTE_ARRIBA_H

#include "barra_gancho_completa.h"

class _parte_arriba{
public:
    _barra_gancho_completa Brazo_gancho;
    _barra Barra;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void sacarGancho(){Brazo_gancho.sacarGancho();}
    void retraerGancho(){Brazo_gancho.retraerGancho();}

    void autoFrontal(){Brazo_gancho.autoFrontal();}
private:
    void draw(unsigned int mode);

};

#endif // PARTE_ARRIBA_H
