#include "varilla.h"

void _varilla::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(10+angulo,0,0,1);
        glScalef(1,10,1);
        glTranslatef(0,-0.5,0);
        switch(mode){
        case 0: Varilla.draw_point();break;
        case 1: Varilla.draw_line();break;
        case 2: Varilla.draw_fill();break;
        case 3: Varilla.draw_chess();break;
        }
    glPopMatrix();
}

//Se imponen limitaciones, creo que las logicas
//Solo se puede abrir hasta formar 90º.
//Solo se puede cerrar hasta formar 0º.

void _varilla::subir(){
    if((angulo + 10) < LIMITE_SUBIDA){
        angulo+=10;
    }
    else
        angulo = LIMITE_SUBIDA;
}

void _varilla::bajar(){
    if((angulo - 10) > LIMITE_BAJADA){
        angulo -= 10;
    }
    else
        angulo = LIMITE_BAJADA;

}


