#ifndef EJE_RUEDAS_H
#define EJE_RUEDAS_H

#include "rueda.h"

class _eje_ruedas {
public:
    _rueda Rueda;
    _eje_ruedas(){}

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void girarIzquierda(){Rueda.girarIzquierda();}
    void girarDerecha(){Rueda.girarDerecha();}
    void avanzar(){Rueda.avanzar();}
    void retroceder(){Rueda.retroceder();}

private:
    void draw(unsigned int mode);
};

#endif // EJE_RUEDAS_H
