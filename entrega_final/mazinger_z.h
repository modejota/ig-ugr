#ifndef MAZINGER_Z_H
#define MAZINGER_Z_H

#include "lower_limb_with_joint.h"
#include "upper_limb.h"

class _mazinger_z {

public:
    _lower_limb_with_joint Parte_inferior;
    _upper_limb Parte_superior;

    void draw_point();
    void draw_line();
    void draw_fill();
    void draw_chess();
    void draw_triangles_color();
    void draw_vertices_color();
    void draw_illumination_flat_shading();
    void draw_illumination_smooth_shading();


    void antebrazo_derecho_out()    { Parte_superior.antebrazo_derecho_out(); }
    void antebrazo_derecho_in()     { Parte_superior.antebrazo_derecho_in(); }
    void antebrazo_derecho_up()     { Parte_superior.antebrazo_derecho_up(); }
    void antebrazo_derecho_down()   { Parte_superior.antebrazo_derecho_down(); }
    void brazo_derecho_up()         { Parte_superior.brazo_derecho_up(); }
    void brazo_derecho_down()       { Parte_superior.brazo_derecho_down(); }

    void antebrazo_izquierdo_out()    { Parte_superior.antebrazo_izquierdo_out(); }
    void antebrazo_izquierdo_in()     { Parte_superior.antebrazo_izquierdo_in(); }
    void antebrazo_izquierdo_up()     { Parte_superior.antebrazo_izquierdo_up(); }
    void antebrazo_izquierdo_down()   { Parte_superior.antebrazo_izquierdo_down(); }
    void brazo_izquierdo_up()         { Parte_superior.brazo_izquierdo_up(); }
    void brazo_izquierdo_down()       { Parte_superior.brazo_izquierdo_down(); }

    void arms_up()          { Parte_superior.arms_up();     }
    void arms_down()        { Parte_superior.arms_down();   }
    void antebrazos_up()    { Parte_superior.antebrazos_up(); }
    void antebrazos_down()  { Parte_superior.antebrazos_down(); }
    void antebrazos_out()   { Parte_superior.antebrazos_out();  }
    void antebrazos_in()    { Parte_superior.antebrazos_in();   }

    void body_right();
    void body_left();

    void cabeza_out() { Parte_superior.cabeza_out(); }
    void cabeza_in()  { Parte_superior.cabeza_in();  }

    void right_leg_up();
    void right_leg_down();
    void left_leg_up();
    void left_leg_down();
    void legs_forward()     { right_leg_up();   left_leg_down(); }
    void legs_backwards()   { right_leg_down(); left_leg_up();   }

    void increase_speed_antebrazo_movement(){Parte_superior.increase_speed_antebrazo_movement();}
    void decrease_speed_antebrazo_movement(){Parte_superior.decrease_speed_antebrazo_movement();}
    void increase_speed_antebrazo_scale(){Parte_superior.increase_speed_antebrazo_scale();}
    void decrease_speed_antebrazo_scale(){Parte_superior.decrease_speed_antebrazo_scale();}
    void increase_speed_brazo_movement(){Parte_superior.increase_speed_brazo_movement();}
    void decrease_speed_brazo_movement(){Parte_superior.decrease_speed_brazo_movement();}

    void increase_speed_cuerpo_movement();
    void decrease_speed_cuerpo_movement();

    void increase_speed_piernas_movement();
    void decrease_speed_piernas_movement();

    void head_faster() { Parte_superior.head_faster(); }
    void head_slower() { Parte_superior.head_slower(); }

    float getVelocidadBrazos()                { return Parte_superior.getVelocidadBrazos();  }
    float getVelocidadGiroAntebrazos()        { return Parte_superior.getVelocidadGiroAntebrazos();   }
    float getVelocidadEscaladoAntebrazos()    { return Parte_superior.getVelocidadEscaladoAntebrazos();  }
    float getVelocidadPiernas()   { return velocidad_giro_piernas; }
    float getVelocidadCuerpo()    { return velocidad_giro_cuerpo;  }
    float getVelocidadCabeza()    { return Parte_superior.getVelocidadCabeza(); }

    void auto_arms();
    void auto_legs();
    void auto_body();
    void auto_giro_antebrazo();
    void auto_escalado_antebrazo();
    void auto_head();

private:
    void draw(unsigned int mode);
    static const int MAX_GIRO_CUERPO = 15;
    static const int MAX_GIRO_PIERNA = 30;
    static constexpr float FACTOR_VELOCIDAD_CUERPO = 0.2;
    static constexpr float FACTOR_VELOCIDAD_PIERNA = 0.2;
    static const int MAX_VELOCIDAD_PIERNA = 3;
    static const int MAX_VELOCIDAD_CUERPO = 2;

    float angulo_giro_cuerpo = 0;
    float angulo_giro_pierna_izquierda = 0;
    float angulo_giro_pierna_derecha = 0;

    float velocidad_giro_cuerpo = 0.2;
    float velocidad_giro_piernas = 0.2;

    bool topeCuerpoDerecha = false, topeCuerpoIzquierda = false;
    bool ultimoCuerpoDerecha = false;

    bool topePiernaDerechaArriba = false, topePiernaDerechaAbajo = false;
    bool topePiernaIzquierdaArriba = false, topePiernaIzquierdaAbajo = false;
    bool ultimoPiernaDerechaArriba = false, ultimoPiernaIzquierdaArriba = true;

};

#endif // MAZINGER_Z_H
