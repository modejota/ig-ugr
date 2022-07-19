#ifndef SOPORTE_H
#define SOPORTE_H

#include "cylinder.h"
#include "varilla.h"

class _soporte {
public:
    _cylinder Soporte;
    _varilla Varilla;
    _soporte();

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void subir_varilla(){Varilla.subir();}
    void bajar_varilla(){Varilla.bajar();}

private:
    void draw(unsigned int mode);
};

#endif // SOPORTE_H
