#include "rueda.h"

_rueda::_rueda() : Rueda(30){}

void _rueda::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(angulo_izq_der,0,1,0);
        glRotatef(angulo_rotacion,1,0,0);
        glScalef(0.2,1,1);
        glRotatef(90,0,0,1);
        switch(mode){
        case 0: Rueda.draw_point();break;
        case 1: Rueda.draw_line();break;
        case 2: Rueda.draw_fill();break;
        case 3: Rueda.draw_chess();break;
        }
    glPopMatrix();
}

void _rueda::girarIzquierda(){
    if((angulo_izq_der+3) < LIMITE_GIRO_IZQ_DER){
        angulo_izq_der+=3;
    }
    else{
        angulo_izq_der = LIMITE_GIRO_IZQ_DER;
    }
}

void _rueda::girarDerecha(){
    if((angulo_izq_der-3) > -LIMITE_GIRO_IZQ_DER){
        angulo_izq_der-=3;
    }
    else{
        angulo_izq_der = -LIMITE_GIRO_IZQ_DER;
    }
}

void _rueda::avanzar(){angulo_rotacion+=15;}
void _rueda::retroceder(){angulo_rotacion-=15;}
