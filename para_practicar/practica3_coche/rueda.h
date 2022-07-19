#ifndef RUEDA_H
#define RUEDA_H

#include "cylinder.h"

class _rueda {
public:
    _rueda();
    _cylinder Rueda;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void girarIzquierda();
    void girarDerecha();
    void avanzar();
    void retroceder();

private:
    void draw(unsigned int mode);
    float angulo_izq_der = 0;
    float angulo_rotacion = 0;
    static const int LIMITE_GIRO_IZQ_DER = 20;
};

#endif // RUEDA_H
