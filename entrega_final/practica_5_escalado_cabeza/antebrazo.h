#ifndef A_ARM_H
#define A_ARM_H

#include "arm_bone.h"
#include "joint_arm.h"

class _antebrazo {

public:
    _arm_bone Cilindro;
    _joint_arm Rotula;
    _antebrazo();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_triangles_color();
    void draw_vertices_color();
    void draw_illumination_flat_shading();
    void draw_illumination_smooth_shading();

    float getTamanio() { return 0.6*factor_escala; }
    void increase_factor_escala();
    void decrease_factor_escala();
    void increase_speed_antebrazo_scale();
    void decrease_speed_antebrazo_scale();

    float getVelocidadEscaladoAntebrazos()    { return variacion_factor_escala;  }

    void auto_escalado_antebrazo();

private:
    void draw(unsigned int mode);
    static constexpr float LIMITE_ESCALADO_ACORTAR = 0.4;   //Para que por mucho que acortemos tengamos algo de antebrazo
    static const int LIMITE_ESCALADO_AGRANDAR = 5;          //Un limite, del que se podria prescindir, para que el brazo no se vaya de madre
    static constexpr float FACTOR_VARIACION_ESCALADO = 0.01;
    static constexpr float LIMITE_VELOCIDAD = 0.4;

    float factor_escala = 1;
    float variacion_factor_escala = 0.01;

    bool topeAgrandar = false, topeAcortar = false;
    bool ultimoAgrandar = true;
};
#endif // A_ARM_H
