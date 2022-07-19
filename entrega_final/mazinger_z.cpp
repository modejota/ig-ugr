#include "mazinger_z.h"

void _mazinger_z::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);

    //Dibujado de la pierna izquierda
    glPushMatrix();
        glTranslatef(-0.7,1.7,0);
        glRotatef(angulo_giro_pierna_izquierda,1,0,0);
        switch (mode) {
        case 0: Parte_inferior.draw_point(); break;
        case 1: Parte_inferior.draw_line();  break;
        case 2: Parte_inferior.draw_fill();  break;
        case 3: Parte_inferior.draw_chess(); break;
        case 4: Parte_inferior.draw_illumination_flat_shading();   break;
        case 5: Parte_inferior.draw_illumination_smooth_shading(); break;
        case 6: Parte_inferior.draw_triangles_color();break;
        case 7: Parte_inferior.draw_vertices_color();break;
        }
    glPopMatrix();

    //Dibujado de la pierna derecha
    glPushMatrix();
        glTranslatef(0.7,1.7,0);
        glRotatef(angulo_giro_pierna_derecha,1,0,0);
        switch (mode) {
        case 0: Parte_inferior.draw_point(); break;
        case 1: Parte_inferior.draw_line();  break;
        case 2: Parte_inferior.draw_fill();  break;
        case 3: Parte_inferior.draw_chess(); break;
        case 4: Parte_inferior.draw_illumination_flat_shading();   break;
        case 5: Parte_inferior.draw_illumination_smooth_shading(); break;
        case 6: Parte_inferior.draw_triangles_color();break;
        case 7: Parte_inferior.draw_vertices_color();break;
        }
    glPopMatrix();

    //Dibujado de la parte superior por ahora.
    glPushMatrix();
        glTranslatef(0,3,0.1);
        glRotatef(angulo_giro_cuerpo,0,1,0);
        switch (mode) {
        case 0: Parte_superior.draw_point(); break;
        case 1: Parte_superior.draw_line();  break;
        case 2: Parte_superior.draw_fill();  break;
        case 3: Parte_superior.draw_chess(); break;
        case 4: Parte_superior.draw_illumination_flat_shading();   break;
        case 5: Parte_superior.draw_illumination_smooth_shading(); break;
        case 6: Parte_superior.draw_triangles_color();break;
        case 7: Parte_superior.draw_vertices_color();break;
         }
     glPopMatrix();


}

void _mazinger_z::draw_point()  {this->draw(0);}
void _mazinger_z::draw_line()   {this->draw(1);}
void _mazinger_z::draw_fill()   {this->draw(2);}
void _mazinger_z::draw_chess()  {this->draw(3);}
void _mazinger_z::draw_illumination_flat_shading()  {this->draw(4);}
void _mazinger_z::draw_illumination_smooth_shading(){this->draw(5);}
void _mazinger_z::draw_triangles_color(){this->draw(6);}
void _mazinger_z::draw_vertices_color(){this->draw(7);}

void _mazinger_z::body_right(){
    if ((angulo_giro_cuerpo + velocidad_giro_cuerpo) < MAX_GIRO_CUERPO) {
        angulo_giro_cuerpo += velocidad_giro_cuerpo;
        topeCuerpoDerecha = false;
    }
    else {
        angulo_giro_cuerpo = MAX_GIRO_CUERPO;
        topeCuerpoDerecha = true;
    }
    ultimoCuerpoDerecha = true;
}
void _mazinger_z::body_left(){
    if ((angulo_giro_cuerpo - velocidad_giro_cuerpo) > -MAX_GIRO_CUERPO) {
        angulo_giro_cuerpo -= velocidad_giro_cuerpo;
        topeCuerpoIzquierda = false;
    }
    else {
        angulo_giro_cuerpo = -MAX_GIRO_CUERPO;
        topeCuerpoIzquierda = true;
    }
    ultimoCuerpoDerecha = false;
}

void _mazinger_z::right_leg_up(){
    if ((angulo_giro_pierna_derecha - velocidad_giro_piernas) > -MAX_GIRO_PIERNA) {
        angulo_giro_pierna_derecha -= velocidad_giro_piernas;
        topePiernaDerechaArriba = false;
    }
    else {
        angulo_giro_pierna_derecha = -MAX_GIRO_PIERNA;
        topePiernaDerechaArriba = true;
    }
    ultimoPiernaDerechaArriba = true;
}
void _mazinger_z::right_leg_down(){
    if ((angulo_giro_pierna_derecha + velocidad_giro_piernas) < MAX_GIRO_PIERNA) {
        angulo_giro_pierna_derecha += velocidad_giro_piernas;
        topePiernaDerechaAbajo = false;
    }
    else {
        angulo_giro_pierna_derecha = MAX_GIRO_PIERNA;
        topePiernaDerechaAbajo = true;
    }
    ultimoPiernaDerechaArriba = false;
}
void _mazinger_z::left_leg_up(){
    if ((angulo_giro_pierna_izquierda - velocidad_giro_piernas) > -MAX_GIRO_PIERNA) {
        angulo_giro_pierna_izquierda -= velocidad_giro_piernas;
        topePiernaIzquierdaArriba = false;
    }
    else {
        angulo_giro_pierna_izquierda = -MAX_GIRO_PIERNA;
        topePiernaIzquierdaArriba = true;
    }
    ultimoPiernaIzquierdaArriba = true;
}
void _mazinger_z::left_leg_down(){
    if ((angulo_giro_pierna_izquierda + velocidad_giro_piernas) < MAX_GIRO_PIERNA) {
        angulo_giro_pierna_izquierda += velocidad_giro_piernas;
        topePiernaIzquierdaAbajo = false;
    }
    else {
        angulo_giro_pierna_izquierda = MAX_GIRO_PIERNA;
        topePiernaIzquierdaAbajo = true;
    }
    ultimoPiernaIzquierdaArriba = false;
}

void _mazinger_z::increase_speed_cuerpo_movement(){
    if ((velocidad_giro_cuerpo + FACTOR_VELOCIDAD_CUERPO) < MAX_VELOCIDAD_CUERPO)
        velocidad_giro_cuerpo += FACTOR_VELOCIDAD_CUERPO;
    else
        velocidad_giro_cuerpo = MAX_VELOCIDAD_CUERPO;
}
void _mazinger_z::decrease_speed_cuerpo_movement(){
    if ((velocidad_giro_cuerpo - FACTOR_VELOCIDAD_CUERPO) > 0)
        velocidad_giro_cuerpo -= FACTOR_VELOCIDAD_CUERPO;
    else
        velocidad_giro_cuerpo = 0.2;
}

void _mazinger_z::increase_speed_piernas_movement(){
    if((velocidad_giro_piernas + FACTOR_VELOCIDAD_PIERNA) < MAX_VELOCIDAD_PIERNA)
        velocidad_giro_piernas += FACTOR_VELOCIDAD_PIERNA;
    else
        velocidad_giro_piernas = MAX_VELOCIDAD_PIERNA;
}
void _mazinger_z::decrease_speed_piernas_movement(){
    if((velocidad_giro_piernas - FACTOR_VELOCIDAD_PIERNA) > 0)
        velocidad_giro_piernas -= FACTOR_VELOCIDAD_PIERNA;
    else
        velocidad_giro_piernas = 0.2;
}

void _mazinger_z::auto_arms() { Parte_superior.auto_arms(); }
void _mazinger_z::auto_legs() {

    if(topePiernaDerechaArriba)     { topePiernaDerechaArriba = false; this->right_leg_down(); }
    else if(topePiernaDerechaAbajo) { topePiernaDerechaAbajo = false;  this->right_leg_up(); }
    else if(ultimoPiernaDerechaArriba) this->right_leg_up();
    else    this->right_leg_down();

    if(topePiernaIzquierdaArriba)   { topePiernaIzquierdaArriba = false;    this->left_leg_down(); }
    else if(topePiernaIzquierdaAbajo) { topePiernaIzquierdaAbajo = false;     this->left_leg_up(); }
    else if(ultimoPiernaIzquierdaArriba) this->left_leg_up();
    else    this->left_leg_down();

}
void _mazinger_z::auto_body(){
    if(topeCuerpoDerecha)   this->body_left();
    if(topeCuerpoIzquierda) this->body_right();
    else if(ultimoCuerpoDerecha) this->body_right();
    else    this->body_left();
}
void _mazinger_z::auto_giro_antebrazo(){ Parte_superior.auto_giro_antebrazo(); }
void _mazinger_z::auto_escalado_antebrazo(){ Parte_superior.auto_escalado_antebrazo(); }
void _mazinger_z::auto_head(){Parte_superior.auto_head();}
