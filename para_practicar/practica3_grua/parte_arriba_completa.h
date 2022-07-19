#ifndef PARTE_ARRIBA_COMPLETA_H
#define PARTE_ARRIBA_COMPLETA_H

#include "parte_arriba.h"

class _parte_arriba_completa{
public:
    _parte_arriba Parte_arriba;
    _union_barras Union;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void mover_derecha();
    void mover_izquierda();
    void sacarGancho(){Parte_arriba.sacarGancho();}
    void retraerGancho(){Parte_arriba.retraerGancho();}

    void autoLateral();
    void autoFrontal(){Parte_arriba.autoFrontal();}

private:
    void draw(unsigned int mode);
    float posicion = 0;
    float deslizamiento = 0.001;

    //No permite que salga entero, y de hecho se queda un pelin de la barra por fuera de la junta
    static constexpr float LIMITE_DERECHA = 1;
    //No permite que entre entero, hay un minimo de margen con respecto a la barra del gancho
    static constexpr float LIMITE_IZQUIERDA = -0.3;

    bool ultimoDerecha = false;
    bool limiteDerecha = false, limiteIzquierda = false;
};

#endif // PARTE_ARRIBA_COMPLETA_H
