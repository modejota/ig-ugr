#ifndef ANTEBRAZO_MANO_H
#define ANTEBRAZO_MANO_H


#include "antebrazo.h"
#include "hand.h"

class _antebrazo_mano {

public:
    _antebrazo Antebrazo;
    _hand Mano;
    _antebrazo_mano(){}

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_triangles_color();
    void draw_vertices_color();
    void draw_illumination_flat_shading();
    void draw_illumination_smooth_shading();

    void increase_factor_escala() { Antebrazo.increase_factor_escala(); }
    void decrease_factor_escala() { Antebrazo.decrease_factor_escala(); }

    void increase_speed_antebrazo_scale(){Antebrazo.increase_speed_antebrazo_scale();}
    void decrease_speed_antebrazo_scale(){Antebrazo.decrease_speed_antebrazo_scale();}

    float getVelocidadEscaladoAntebrazos()    { return Antebrazo.getVelocidadEscaladoAntebrazos();  }

    void auto_escalado_antebrazo()  { Antebrazo.auto_escalado_antebrazo(); }


private:
    void draw(unsigned int mode);
};

#endif // ANTEBRAZO_MANO_H
