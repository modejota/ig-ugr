#include "parte_arriba_completa.h"

void _parte_arriba_completa::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glTranslatef(posicion,0,0);
        switch(mode){
        case 0: Parte_arriba.draw_point();break;
        case 1: Parte_arriba.draw_line();break;
        case 2: Parte_arriba.draw_fill();break;
        case 3: Parte_arriba.draw_chess();break;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0.1,0);
        glRotatef(90,0,1,0);
        switch(mode){
        case 0: Union.draw_point();break;
        case 1: Union.draw_line();break;
        case 2: Union.draw_fill();break;
        case 3: Union.draw_chess();break;
        }
    glPopMatrix();

}

void _parte_arriba_completa::mover_derecha(){
    if((posicion+deslizamiento) < LIMITE_DERECHA){
        posicion += deslizamiento;
        limiteDerecha = false;
    }
    else {
        posicion = LIMITE_DERECHA;
        limiteDerecha = true;
    }
    ultimoDerecha = true;
}
void _parte_arriba_completa::mover_izquierda(){
    if((posicion-deslizamiento) > LIMITE_IZQUIERDA){
        posicion -= deslizamiento;
        limiteIzquierda = false;
    }
    else {
        posicion = LIMITE_IZQUIERDA;
        limiteIzquierda = true;
    }
    ultimoDerecha = false;
}

void _parte_arriba_completa::autoLateral(){
    if(limiteDerecha) this->mover_izquierda();
    if(limiteIzquierda) this->mover_derecha();
    else if (ultimoDerecha) this->mover_derecha();
    else    this->mover_izquierda();
}
