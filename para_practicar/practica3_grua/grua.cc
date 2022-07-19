#include "grua.h"

void _grua::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        switch(mode){
        case 0: Pivote.draw_point();break;
        case 1: Pivote.draw_line();break;
        case 2: Pivote.draw_fill();break;
        case 3: Pivote.draw_chess();break;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,posicion,0);
        switch(mode){
        case 0: Parte_arriba.draw_point();break;
        case 1: Parte_arriba.draw_line();break;
        case 2: Parte_arriba.draw_fill();break;
        case 3: Parte_arriba.draw_chess();break;
        }
    glPopMatrix();

}

void _grua::subir_grua(){
    if((posicion + deslizamiento) < LIMITE_SUBIDA){
        posicion += deslizamiento;
        limiteSubir = false;
    }
    else {
        posicion = LIMITE_SUBIDA;
        limiteSubir = true;
    }
    ultimoSubir = true;

}

void _grua::bajar_grua(){
    if((posicion-deslizamiento) > LIMITE_BAJADA){
        posicion -= deslizamiento;
        limiteBajar = false;
    }
    else {
        posicion = LIMITE_BAJADA;
        limiteBajar = true;
    }
    ultimoSubir = false;
}

void _grua::autoSubir(){
    if(limiteSubir) this->bajar_grua();
    if(limiteBajar) this->subir_grua();
    else if(ultimoSubir) this->subir_grua();
    else                 this->bajar_grua();
}
