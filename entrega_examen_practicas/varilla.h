#ifndef VARILLA_H
#define VARILLA_H

#include "cube.h"

class _varilla{
public:
    _cube Varilla;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void subir();
    void bajar();

private:
    void draw(unsigned int mode);
    float angulo = 10;
    static const int LIMITE_SUBIDA = 80;
    static const int LIMITE_BAJADA = -10;
};

#endif // VARILLA_H
