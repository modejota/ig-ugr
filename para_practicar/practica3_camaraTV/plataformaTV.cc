#include "plataformaTV.h"

void _plataformaTV::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

        //Parece que hace que gire raro, la base en un sentido y la camara en el contrario, pero bueno...
        glRotatef(angulo_rotacion,0,1,0);

        glPushMatrix();
            glTranslatef(0,-0.025,0);
            switch(mode){
            case 0: Base.draw_point();break;
            case 1: Base.draw_line();break;
            case 2: Base.draw_fill();break;
            case 3: Base.draw_chess();break;
            }
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.4,0,0);
            switch(mode){
            case 0: Camara.draw_point();break;
            case 1: Camara.draw_line();break;
            case 2: Camara.draw_fill();break;
            case 3: Camara.draw_chess();break;
            }
        glPopMatrix();

    glPopMatrix();

}

void _plataformaTV::draw_point(){ this->draw(0); }
void _plataformaTV::draw_line() { this->draw(1); }
void _plataformaTV::draw_fill() { this->draw(2); }
void _plataformaTV::draw_chess(){ this->draw(3); }

void _plataformaTV::girarPlataformaDerecha(){
    angulo_rotacion = (angulo_rotacion < 360 ) ? angulo_rotacion += 15 : angulo_rotacion = 0;
}
void _plataformaTV::girarPlataformaIzquierda(){
    angulo_rotacion = (angulo_rotacion > 0) ? angulo_rotacion -= 15 : angulo_rotacion = 360;
}
