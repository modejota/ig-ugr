#ifndef PLATAFORMATV_H
#define PLATAFORMATV_H

#include "base.h"
#include "camara_completa.h"

class _plataformaTV {
public:
    _base Base;
    _camara Camara;
    _plataformaTV(){}

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void camaraArriba()        { Camara.camaraArriba();    }
    void camaraAbajo()         { Camara.camaraAbajo();     }
    void camaraDerecha()       { Camara.camaraDerecha();   }
    void camaraIzquierda()     { Camara.camaraIzquierda(); }
    void subirCamara()         { Camara.subirCamara();     }
    void bajarCamara()         { Camara.bajarCamara();     }
    void girarPlataformaDerecha();
    void girarPlataformaIzquierda();

private:
    void draw(unsigned int mode);
    //Para la rotacion de la base
    float angulo_rotacion = 0;

};

#endif // PLATAFORMATV_H
