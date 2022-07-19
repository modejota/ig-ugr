#include "barra_gancho_completa.h"

void _barra_gancho_completa::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    //Dibujado de la barra
    glPushMatrix();
        glTranslatef(0,0,posicion);
        switch(mode){
        case 0: Barra.draw_point();break;
        case 1: Barra.draw_line();break;
        case 2: Barra.draw_fill();break;
        case 3: Barra.draw_chess();break;
        }
   glPopMatrix();
   //Dibujado de la union
   glPushMatrix();
       glTranslatef(0,0.1,0);
       switch(mode){
       case 0: Union.draw_point();break;
       case 1: Union.draw_line();break;
       case 2: Union.draw_fill();break;
       case 3: Union.draw_chess();break;
       }
   glPopMatrix();
}

void _barra_gancho_completa::sacarGancho(){
    if((posicion+deslizamiento) < LIMITE_SACAR){
        posicion += deslizamiento;
        limiteSacar = false;
    }
    else {
        posicion = LIMITE_SACAR;
        limiteSacar = true;
    }
    ultimoSacar = true;
}

void _barra_gancho_completa::retraerGancho(){
    if((posicion-deslizamiento) > LIMITE_RETRAER){
        posicion -= deslizamiento;
        limiteRetraer = false;
    }
    else {
        posicion = LIMITE_RETRAER;
        limiteRetraer = true;
    }
    ultimoSacar = false;
}

void _barra_gancho_completa::autoFrontal(){
    if(limiteSacar) this->retraerGancho();
    if(limiteRetraer) this->sacarGancho();
    else if (ultimoSacar) this->sacarGancho();
    else    this->retraerGancho();
}
