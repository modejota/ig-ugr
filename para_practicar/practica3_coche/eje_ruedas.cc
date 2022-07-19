#include "eje_ruedas.h"

void _eje_ruedas::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    //Dibujado rueda izquierda
    glPushMatrix();
        glTranslatef(-1.1,0,0);
        switch(mode){
        case 0: Rueda.draw_point();break;
        case 1: Rueda.draw_line();break;
        case 2: Rueda.draw_fill();break;
        case 3: Rueda.draw_chess();break;
        }
    glPopMatrix();

    //Dibujado rueda derecha
    glPushMatrix();
        glTranslatef(1.1,0,0);
        switch(mode){
        case 0: Rueda.draw_point();break;
        case 1: Rueda.draw_line();break;
        case 2: Rueda.draw_fill();break;
        case 3: Rueda.draw_chess();break;
        }
    glPopMatrix();


}
