#ifndef CAMARA_COMPLETA_H
#define CAMARA_COMPLETA_H

#include "pie_camara.h"
#include "cuerpo_camara.h"

class _camara : public _object3D{
public:
    _pie_camara Pie;
    _cuerpo_camara Cuerpo;
    _camara(){}

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();

    void camaraArriba();
    void camaraAbajo();
    void camaraDerecha();
    void camaraIzquierda();
    void subirCamara();
    void bajarCamara();

private:
    void draw(unsigned int mode);
    //Para las rotaciones de la camara
    float angulo_subir = 0, angulo_lado = 0;
    static const int LIMITE_ANGULO_SUBIR = 20, LIMITE_ANGULO_LADO = 45;
    //Para la bajada y subida de la camara
    float factor_escala = 1;
    static const int LIMITE_ESCALADO = 3;


};

#endif // CAMARA_COMPLETA_H
