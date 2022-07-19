#ifndef UPPER_LIMB_H
#define UPPER_LIMB_H

#include "body_with_accessories.h"
#include "full_arm.h"
#include "head_with_face.h"

class _upper_limb {

public:

    _body_with_accessories Cuerpo;
    _full_arm Brazo_izq;
    _full_arm Brazo_der;
    _head_with_face Cabeza;
    _upper_limb();

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_triangles_color();
    void draw_vertices_color();
    void draw_illumination_flat_shading();
    void draw_illumination_smooth_shading();

    void antebrazo_derecho_out() { Brazo_der.increase_factor_escala(); }
    void antebrazo_derecho_in() { Brazo_der.decrease_factor_escala(); }
    void antebrazo_derecho_up() { Brazo_der.increase_angulo_antebrazo(); }
    void antebrazo_derecho_down() { Brazo_der.decrease_angulo_antebrazo(); }
    void brazo_derecho_up();
    void brazo_derecho_down();

    void antebrazo_izquierdo_out() { Brazo_izq.increase_factor_escala(); }
    void antebrazo_izquierdo_in() { Brazo_izq.decrease_factor_escala(); }
    void antebrazo_izquierdo_up() { Brazo_izq.increase_angulo_antebrazo(); }
    void antebrazo_izquierdo_down() { Brazo_izq.decrease_angulo_antebrazo(); }
    void brazo_izquierdo_up();
    void brazo_izquierdo_down();

    void cabeza_out()   { Cabeza.head_out(); }
    void cabeza_in()    { Cabeza.head_in();  }

    void increase_speed_antebrazo_movement(){Brazo_izq.increase_speed_antebrazo_movement(); Brazo_der.increase_speed_antebrazo_movement();}
    void decrease_speed_antebrazo_movement(){Brazo_izq.decrease_speed_antebrazo_movement(); Brazo_der.decrease_speed_antebrazo_movement();}
    void increase_speed_antebrazo_scale(){Brazo_izq.increase_speed_antebrazo_scale(); Brazo_der.increase_speed_antebrazo_scale();}
    void decrease_speed_antebrazo_scale(){Brazo_izq.decrease_speed_antebrazo_scale(); Brazo_der.decrease_speed_antebrazo_scale();}
    void increase_speed_brazo_movement();
    void decrease_speed_brazo_movement();

    void head_faster() { Cabeza.head_faster(); }
    void head_slower() { Cabeza.head_slower(); }

    float getVelocidadBrazos()                { return variacion_angulo_brazo;  }
    float getVelocidadGiroAntebrazos()        { return Brazo_izq.getVelocidadGiroAntebrazos();   }      //Se lo puedo preguntar a cualquiera, es un valor comun.
    float getVelocidadEscaladoAntebrazos()    { return Brazo_izq.getVelocidadEscaladoAntebrazos();  }
    float getVelocidadCabeza() { return Cabeza.getVelocidadCabeza(); }

    void arms_up()          { brazo_derecho_up();   brazo_izquierdo_up(); }
    void arms_down()        { brazo_derecho_down(); brazo_izquierdo_down();   }
    void antebrazos_up()    { Brazo_izq.increase_angulo_antebrazo(); Brazo_der.increase_angulo_antebrazo(); }
    void antebrazos_down()  { Brazo_izq.decrease_angulo_antebrazo(); Brazo_der.decrease_angulo_antebrazo(); }
    void antebrazos_out()   { Brazo_izq.increase_factor_escala(); Brazo_der.increase_factor_escala(); }
    void antebrazos_in()    { Brazo_izq.decrease_factor_escala(); Brazo_der.decrease_factor_escala(); }

    void auto_arms();
    void auto_giro_antebrazo()      { Brazo_izq.auto_giro_antebrazo();     Brazo_der.auto_giro_antebrazo(); }
    void auto_escalado_antebrazo()  { Brazo_izq.auto_escalado_antebrazo(); Brazo_der.auto_escalado_antebrazo(); }
    void auto_head()    { Cabeza.auto_head(); }


private:
    void draw(unsigned int mode);
    static const int MAX_GIRO_BRAZO = 45;
    static constexpr float FACTOR_VELOCIDAD_BRAZOS = 0.2;
    static const int MAX_VELOCIDAD = 3;

    float angulo_brazo_izquierdo = 0;
    float angulo_brazo_derecho = 0;
    float variacion_angulo_brazo = 0.2;

    bool topeArribaDerecha = false, topeArribaIzquierda = false;
    bool topeAbajoDerecha = false, topeAbajoIzquierda = false;
    bool ultimoSubirDerecha = true, ultimoSubirIzquierda = true;

};

#endif // UPPER_LIMB_H
