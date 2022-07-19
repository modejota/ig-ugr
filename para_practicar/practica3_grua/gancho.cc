#include "gancho.h"

void _gancho::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    //Dibujado de la caja superior
    glPushMatrix();
        glTranslatef(0,0.1,0);
        switch(mode){
        case 0: Caja.draw_point();break;
        case 1: Caja.draw_line();break;
        case 2: Caja.draw_fill();break;
        case 3: Caja.draw_chess();break;
        }
    glPopMatrix();

    //Dibujado de las pestañas del gancho
    glPushMatrix();
        glTranslatef(0,-0.1,0);
        switch(mode){
        case 0: Chapas.draw_point();break;
        case 1: Chapas.draw_line();break;
        case 2: Chapas.draw_fill();break;
        case 3: Chapas.draw_chess();break;
        }
    glPopMatrix();

}
