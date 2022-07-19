#include "chasis_completo.h"

void _chasis_completo::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glTranslatef(0,0.4,2.05);
        switch(mode){
        case 0: Faros.draw_point();break;
        case 1: Faros.draw_line();break;
        case 2: Faros.draw_fill();break;
        case 3: Faros.draw_chess();break;
        }
    glPopMatrix();

    glPushMatrix();
        switch(mode){
        case 0: Chasis_abajo.draw_point();break;
        case 1: Chasis_abajo.draw_line();break;
        case 2: Chasis_abajo.draw_fill();break;
        case 3: Chasis_abajo.draw_chess();break;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,1.25,0);
        switch(mode){
        case 0: Chasis_arriba.draw_point();break;
        case 1: Chasis_arriba.draw_line();break;
        case 2: Chasis_arriba.draw_fill();break;
        case 3: Chasis_arriba.draw_chess();break;
        }
    glPopMatrix();
}
