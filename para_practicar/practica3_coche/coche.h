#ifndef COCHE_H
#define COCHE_H

#include "chasis_completo.h"
#include "eje_ruedas.h"

class _coche {
public:
    _chasis_completo Chasis;
    _eje_ruedas Ruedas_delanteras;
    _eje_ruedas Ruedas_traseras;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void eje_delantero_izquierda(){Ruedas_delanteras.girarIzquierda();}
    void eje_delantero_derecha(){Ruedas_delanteras.girarDerecha();}
    void ruedas_avanzar(){Ruedas_delanteras.avanzar();  Ruedas_traseras.avanzar();}
    void ruedas_retroceder(){Ruedas_delanteras.retroceder(); Ruedas_traseras.retroceder();}

private:
    void draw(unsigned int mode);
};

#endif // COCHE_H
