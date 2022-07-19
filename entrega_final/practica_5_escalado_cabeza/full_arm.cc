#include "full_arm.h"

void _full_arm::draw(unsigned int mode) {

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        switch (mode) {
        case 0: Brazo_arriba.draw_point(); break;
        case 1: Brazo_arriba.draw_line();  break;
        case 2: Brazo_arriba.draw_fill();  break;
        case 3: Brazo_arriba.draw_chess(); break;
        case 4: Brazo_arriba.draw_illumination_flat_shading(); break;
        case 5: Brazo_arriba.draw_illumination_smooth_shading(); break;
        case 6: Brazo_arriba.draw_triangles_color();break;
        case 7: Brazo_arriba.draw_vertices_color();break;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1.1,0,0);
        glRotatef(angulo_brazo,0,0,1);
        switch (mode) {
        case 0: Brazo_abajo.draw_point(); break;
        case 1: Brazo_abajo.draw_line();  break;
        case 2: Brazo_abajo.draw_fill();  break;
        case 3: Brazo_abajo.draw_chess(); break;
        case 4: Brazo_abajo.draw_illumination_flat_shading(); break;
        case 5: Brazo_abajo.draw_illumination_smooth_shading(); break;
        case 6: Brazo_abajo.draw_triangles_color();break;
        case 7: Brazo_abajo.draw_vertices_color();break;
        }
    glPopMatrix();
}

void _full_arm::draw_point(){this->draw(0);}
void _full_arm::draw_line(){this->draw(1);}
void _full_arm::draw_fill(){this->draw(2);}
void _full_arm::draw_chess(){this->draw(3);}
void _full_arm::draw_illumination_flat_shading(){this->draw(4);}
void _full_arm::draw_illumination_smooth_shading(){this->draw(5);}
void _full_arm::draw_triangles_color(){this->draw(6);}
void _full_arm::draw_vertices_color(){this->draw(7);}

void _full_arm::increase_angulo_antebrazo(){
    if((angulo_brazo+variacion_giro_brazo) <= MAX_GIRO_ANTEBRAZO){
        angulo_brazo+=variacion_giro_brazo;
        topeArriba = false;
    }
    else {
        angulo_brazo = MAX_GIRO_ANTEBRAZO;
        topeArriba = true;
    }
    ultimoSubir = true;
}
void _full_arm::decrease_angulo_antebrazo(){
    if((angulo_brazo-variacion_giro_brazo) > -MAX_GIRO_ANTEBRAZO){
        angulo_brazo-=variacion_giro_brazo;
        topeAbajo = false;
    }
    else {
        angulo_brazo = -MAX_GIRO_ANTEBRAZO;
        topeAbajo = true;
    }
    ultimoSubir = false;
}
void _full_arm::increase_speed_antebrazo_movement(){
    if((variacion_giro_brazo + FACTOR_GIRO_ANTEBRAZO) < MAX_VELOCIDAD)
        variacion_giro_brazo += FACTOR_GIRO_ANTEBRAZO;
    else
        variacion_giro_brazo = MAX_VELOCIDAD;
}
void _full_arm::decrease_speed_antebrazo_movement(){
    if((variacion_giro_brazo - FACTOR_GIRO_ANTEBRAZO) > 0)
        variacion_giro_brazo -= FACTOR_GIRO_ANTEBRAZO;
    else
        variacion_giro_brazo = 0.2;
}

void _full_arm::auto_giro_antebrazo(){
    if(topeArriba) decrease_angulo_antebrazo();
    if(topeAbajo) increase_angulo_antebrazo();
    else if (ultimoSubir) increase_angulo_antebrazo();
    else decrease_angulo_antebrazo();
}
