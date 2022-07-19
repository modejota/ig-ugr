#include "coche.h"

void _coche::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    //Dibujado del chasis completo
    glPushMatrix();
        switch(mode){
        case 0: Chasis.draw_point();break;
        case 1: Chasis.draw_line();break;
        case 2: Chasis.draw_fill();break;
        case 3: Chasis.draw_chess();break;
        }
    glPopMatrix();

    //Dibujado de las ruedas delanteras
    glPushMatrix();
        glTranslatef(0,-0.7,1.5);
        switch(mode){
        case 0: Ruedas_delanteras.draw_point();break;
        case 1: Ruedas_delanteras.draw_line();break;
        case 2: Ruedas_delanteras.draw_fill();break;
        case 3: Ruedas_delanteras.draw_chess();break;
        }
    glPopMatrix();

    //Dibujado de las ruedas traseras
    glPushMatrix();
        glTranslatef(0,-0.7,-1.5);
        switch(mode){
        case 0: Ruedas_traseras.draw_point();break;
        case 1: Ruedas_traseras.draw_line();break;
        case 2: Ruedas_traseras.draw_fill();break;
        case 3: Ruedas_traseras.draw_chess();break;
        }
    glPopMatrix();
}
