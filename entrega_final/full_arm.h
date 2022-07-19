#ifndef FULL_ARM_H
#define FULL_ARM_H

#include "brazo_arriba.h"
#include "antebrazo_mano.h"

class _full_arm {
public:
    _brazo_arriba Brazo_arriba;
    _antebrazo_mano Brazo_abajo;
    _full_arm(){}

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_triangles_color();
    void draw_vertices_color();
    void draw_illumination_flat_shading();
    void draw_illumination_smooth_shading();

    void increase_factor_escala() { Brazo_abajo.increase_factor_escala(); }
    void decrease_factor_escala() { Brazo_abajo.decrease_factor_escala(); }
    void increase_angulo_antebrazo();
    void decrease_angulo_antebrazo();

    void increase_speed_antebrazo_movement();
    void decrease_speed_antebrazo_movement();
    void increase_speed_antebrazo_scale(){Brazo_abajo.increase_speed_antebrazo_scale();}
    void decrease_speed_antebrazo_scale(){Brazo_abajo.decrease_speed_antebrazo_scale();}

    float getVelocidadGiroAntebrazos()        { return variacion_giro_brazo;   }
    float getVelocidadEscaladoAntebrazos()    { return Brazo_abajo.getVelocidadEscaladoAntebrazos();  }

    void auto_giro_antebrazo();
    void auto_escalado_antebrazo()  { Brazo_abajo.auto_escalado_antebrazo(); }


private:
    void draw(unsigned int mode);
    static const int MAX_GIRO_ANTEBRAZO = 60;
    static constexpr float FACTOR_GIRO_ANTEBRAZO = 0.2;
    static const int MAX_VELOCIDAD = 3;

    float angulo_brazo = 0;
    float variacion_giro_brazo = 0.2;

    bool topeArriba = false, topeAbajo = false;
    bool ultimoSubir = true;
};

#endif // FULL_ARM_H
