#ifndef HEAD_WITH_FACE_H
#define HEAD_WITH_FACE_H

#include "head.h"
#include "both_eyes.h"

class _head_with_face {

public:

    _head Cabeza;
    _both_eyes Ojos;

    _head_with_face(){}

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_triangles_color();
    void draw_vertices_color();
    void draw_illumination_flat_shading();
    void draw_illumination_smooth_shading();

    void head_out();
    void head_in();
    void head_faster();
    void head_slower();

    void auto_head();
    float getVelocidadCabeza() { return variacion_factor_escala; }

private:
    void draw(unsigned int mode);
    static constexpr float LIMITE_ESCALADO_ACORTAR = 0.8;   //Para que por mucho que acortemos tengamos algo cabeza, minimo el tamaño los ojos
    static const int LIMITE_ESCALADO_AGRANDAR = 3;          //Un limite, del que se podria prescindir, para que el brazo no se vaya de madre
    static constexpr float FACTOR_VARIACION_ESCALADO = 0.01;
    static constexpr float LIMITE_VELOCIDAD = 0.4;

    float factor_escala = 1;
    float variacion_factor_escala = 0.01;

    bool topeAgrandar = false, topeAcortar = false;
    bool ultimoAgrandar = true;
};


#endif // HEAD_WITH_FACE_H
