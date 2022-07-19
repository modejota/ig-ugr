#include "agarre.h"

void _agarre::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    //Dibujado de la pieza izquierda
    glPushMatrix();
        glTranslatef(-0.2,0,0);
        switch(mode){
        case 0: Pieza.draw_point();break;
        case 1: Pieza.draw_line();break;
        case 2: Pieza.draw_fill();break;
        case 3: Pieza.draw_chess();break;
        }
    glPopMatrix();
    //Dibujado de la pieza derecha
    glPushMatrix();
        glTranslatef(0.2,0,0);
        switch(mode){
        case 0: Pieza.draw_point();break;
        case 1: Pieza.draw_line();break;
        case 2: Pieza.draw_fill();break;
        case 3: Pieza.draw_chess();break;
        }
    glPopMatrix();
}
