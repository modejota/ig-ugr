#include "upper_limb.h"

_upper_limb::_upper_limb(){}

void _upper_limb::draw(unsigned int mode){

    glMatrixMode(GL_MODELVIEW);

    //Dibujado del cuerpo del robot
    glPushMatrix();
        glTranslatef(0,-0.4,0);
        switch (mode) {
        case 0: Cuerpo.draw_point(); break;
        case 1: Cuerpo.draw_line();  break;
        case 2: Cuerpo.draw_fill();  break;
        case 3: Cuerpo.draw_chess(); break;
        case 4: Cuerpo.draw_illumination_flat_shading(); break;
        case 5: Cuerpo.draw_illumination_smooth_shading(); break;
        case 6: Cuerpo.draw_triangles_color();break;
        case 7: Cuerpo.draw_vertices_color();break;
        }
    glPopMatrix();

    //Dibujado de la cabeza del robot
    glPushMatrix();
        glTranslatef(0,0.6,-0.05);
        switch (mode) {
        case 0: Cabeza.draw_point(); break;
        case 1: Cabeza.draw_line();  break;
        case 2: Cabeza.draw_fill();  break;
        case 3: Cabeza.draw_chess(); break;
        case 4: Cabeza.draw_illumination_flat_shading(); break;
        case 5: Cabeza.draw_illumination_smooth_shading(); break;
        case 6: Cabeza.draw_triangles_color();break;
        case 7: Cabeza.draw_vertices_color();break;
        }
     glPopMatrix();

     //Dibujado del brazo izquierdo del robot
     glPushMatrix();
         glTranslatef(-1,0.1,-0.1);
         glScalef(-1,1,1);
         glRotatef(angulo_brazo_izquierdo,0,0,1);
         switch (mode) {
         case 0: Brazo_izq.draw_point(); break;
         case 1: Brazo_izq.draw_line();  break;
         case 2: Brazo_izq.draw_fill();  break;
         case 3: Brazo_izq.draw_chess(); break;
         case 4: Brazo_izq.draw_illumination_flat_shading(); break;
         case 5: Brazo_izq.draw_illumination_smooth_shading(); break;
         case 6: Brazo_izq.draw_triangles_color();break;
         case 7: Brazo_izq.draw_vertices_color();break;
         }
      glPopMatrix();

      //Dibujado del brazo derecho del robot
      glPushMatrix();
          glTranslatef(1,0.1,-0.1);
          glRotatef(angulo_brazo_derecho,0,0,1);
          switch (mode) {
          case 0: Brazo_der.draw_point(); break;
          case 1: Brazo_der.draw_line();  break;
          case 2: Brazo_der.draw_fill();  break;
          case 3: Brazo_der.draw_chess(); break;
          case 4: Brazo_der.draw_illumination_flat_shading(); break;
          case 5: Brazo_der.draw_illumination_smooth_shading(); break;
          case 6: Brazo_der.draw_triangles_color();break;
          case 7: Brazo_der.draw_vertices_color();break;
          }
       glPopMatrix();

}

void _upper_limb::draw_point()  {this->draw(0);}
void _upper_limb::draw_line()   {this->draw(1);}
void _upper_limb::draw_fill()   {this->draw(2);}
void _upper_limb::draw_chess()  {this->draw(3);}
void _upper_limb::draw_illumination_flat_shading(){this->draw(4);}
void _upper_limb::draw_illumination_smooth_shading(){this->draw(5);}
void _upper_limb::draw_triangles_color(){this->draw(6);}
void _upper_limb::draw_vertices_color(){this->draw(7);}

void _upper_limb::brazo_derecho_up() {
    if((angulo_brazo_derecho+variacion_angulo_brazo) < MAX_GIRO_BRAZO) {
        angulo_brazo_derecho+=variacion_angulo_brazo;
        topeArribaDerecha = false;
    }
    else {
        angulo_brazo_derecho = MAX_GIRO_BRAZO;
        topeArribaDerecha = true;
    }
    ultimoSubirDerecha = true;
}
void _upper_limb::brazo_derecho_down() {
    if((angulo_brazo_derecho-variacion_angulo_brazo) > -MAX_GIRO_BRAZO) {
        angulo_brazo_derecho-=variacion_angulo_brazo;
        topeAbajoDerecha = false;
    }
    else {
        angulo_brazo_derecho = -MAX_GIRO_BRAZO;
        topeAbajoDerecha = true;
    }
    ultimoSubirDerecha = false;
}
void _upper_limb::brazo_izquierdo_up() {
    if((angulo_brazo_izquierdo+variacion_angulo_brazo) < MAX_GIRO_BRAZO) {
        angulo_brazo_izquierdo+=variacion_angulo_brazo;
        topeArribaIzquierda = false;
    }
    else {
        angulo_brazo_izquierdo = MAX_GIRO_BRAZO;
        topeArribaIzquierda = true;
    }
    ultimoSubirIzquierda = true;
}
void _upper_limb::brazo_izquierdo_down() {
    if((angulo_brazo_izquierdo-variacion_angulo_brazo) > -MAX_GIRO_BRAZO){
        angulo_brazo_izquierdo-=variacion_angulo_brazo;
        topeAbajoIzquierda = false;
    }
    else {
        angulo_brazo_izquierdo = -MAX_GIRO_BRAZO;
        topeAbajoIzquierda = true;
    }
    ultimoSubirIzquierda = false;
}

void _upper_limb::increase_speed_brazo_movement(){
    if((variacion_angulo_brazo + FACTOR_VELOCIDAD_BRAZOS) < MAX_VELOCIDAD)
        variacion_angulo_brazo += FACTOR_VELOCIDAD_BRAZOS;
    else
        variacion_angulo_brazo = MAX_VELOCIDAD;
}
void _upper_limb::decrease_speed_brazo_movement(){
    if((variacion_angulo_brazo - FACTOR_VELOCIDAD_BRAZOS) > 0)
        variacion_angulo_brazo -= FACTOR_VELOCIDAD_BRAZOS;
    else
        variacion_angulo_brazo = 0.2;
}

void _upper_limb::auto_arms(){
    if (topeArribaDerecha)      this->brazo_derecho_down();
    if (topeAbajoDerecha)       this->brazo_derecho_up();
    if (ultimoSubirDerecha)     this->brazo_derecho_up();
    else                        this->brazo_derecho_down();

    if (topeArribaIzquierda)    this->brazo_izquierdo_down();
    if (topeAbajoIzquierda)     this->brazo_izquierdo_up();
    if (ultimoSubirIzquierda)   this->brazo_izquierdo_up();
    else                        this->brazo_izquierdo_down();
}
