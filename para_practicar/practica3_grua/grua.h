#ifndef GRUA_H
#define GRUA_H

#include "pivote.h"
#include "parte_arriba_completa.h"

class _grua{
public:
    _pivote Pivote;
    _parte_arriba_completa Parte_arriba;

    void draw_point(){this->draw(0);}
    void draw_line(){this->draw(1);}
    void draw_fill(){this->draw(2);}
    void draw_chess(){this->draw(3);}

    void subir_grua();
    void bajar_grua();
    void mover_derecha(){Parte_arriba.mover_derecha();}
    void mover_izquierda(){Parte_arriba.mover_izquierda();}
    void sacarGancho(){Parte_arriba.sacarGancho();}
    void retraerGancho(){Parte_arriba.retraerGancho();}

    void autoSubir();
    void autoLateral(){Parte_arriba.autoLateral();}
    void autoFrontal(){Parte_arriba.autoFrontal();}

private:
    void draw(unsigned int mode);
    float posicion = 1.5;
    float deslizamiento = 0.001;

    //El tope superior va a ser 1.9 (ligeramente por encima del fin de la barra vertical, pero con parte aun dentro
    static constexpr float LIMITE_SUBIDA = 1.9;
    //El tope inferior va a ser 0.4 (que no llegue a tocar abajo del todo nada de la parte superior)
    static constexpr float LIMITE_BAJADA = 0.4;

    bool ultimoSubir = false;
    bool limiteSubir = false, limiteBajar = false;
};

#endif // GRUA_H
