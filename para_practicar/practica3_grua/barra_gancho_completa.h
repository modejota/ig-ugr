#ifndef BARRA_GANCHO_COMPLETA_H
#define BARRA_GANCHO_COMPLETA_H

#include "barra_gancho.h"
#include "union_barras.h"

class _barra_gancho_completa{
public:
    _barra_gancho Barra;
    _union_barras Union;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void sacarGancho();
    void retraerGancho();

    void autoFrontal();
private:
    void draw(unsigned int mode);
    float posicion = 0;
    float deslizamiento = 0.001;

    static constexpr float LIMITE_SACAR = 0.8;
    static constexpr float LIMITE_RETRAER = -0.5;

    bool ultimoSacar = false;
    bool limiteSacar = false, limiteRetraer = false;
};

#endif // BARRA_GANCHO_COMPLETA_H
