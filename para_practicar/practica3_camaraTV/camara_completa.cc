#include "camara_completa.h"

void _camara::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glTranslatef(0.05,0.15+0.4*factor_escala,0);
        glRotatef(angulo_subir,0,1,0);
        glRotatef(angulo_lado,0,0,1);
        switch(mode){
        case 0: Cuerpo.draw_point();break;
        case 1: Cuerpo.draw_line();break;
        case 2: Cuerpo.draw_fill();break;
        case 3: Cuerpo.draw_chess();break;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0.4*(factor_escala/2),0);
        glScalef(1,factor_escala,1);
        switch(mode){
        case 0: Pie.draw_point();break;
        case 1: Pie.draw_line();break;
        case 2: Pie.draw_fill();break;
        case 3: Pie.draw_chess();break;
        }
    glPopMatrix();

}

void _camara::draw_point() { this->draw(0); }
void _camara::draw_line() { this->draw(1); }
void _camara::draw_fill() { this->draw(2); }
void _camara::draw_chess() { this->draw(3); }

void _camara::camaraDerecha(){
    if((angulo_lado + 5) < LIMITE_ANGULO_LADO){
        angulo_lado += 5;
    }
    else
        angulo_lado = LIMITE_ANGULO_LADO;
}
void _camara::camaraIzquierda(){
    if((angulo_lado - 5) > -LIMITE_ANGULO_LADO){
        angulo_lado -= 5;
    }
    else
        angulo_lado = -LIMITE_ANGULO_LADO;
}

void _camara::camaraArriba(){
    if((angulo_subir + 2) < LIMITE_ANGULO_SUBIR){
        angulo_subir += 2;
    }
    else
        angulo_subir = LIMITE_ANGULO_SUBIR;
}
void _camara::camaraAbajo(){
    if((angulo_subir - 2) > -LIMITE_ANGULO_SUBIR){
        angulo_subir -= 2;
    }
    else
        angulo_subir = -LIMITE_ANGULO_SUBIR;
}

void _camara::subirCamara(){
    if((factor_escala+0.1) < LIMITE_ESCALADO){
        factor_escala += 0.1;
    }
    else
        factor_escala = LIMITE_ESCALADO;
}
void _camara::bajarCamara(){
    if((factor_escala-0.1) > 0.5){
        factor_escala -= 0.1;
    }
    else
        factor_escala = 0.5;
}
