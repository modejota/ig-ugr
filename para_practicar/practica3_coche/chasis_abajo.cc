#include "chasis_abajo.h"

void _chasis_abajo::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(2,1.5,4);
        switch(mode){
        case 0: Chasis.draw_point();break;
        case 1: Chasis.draw_line();break;
        case 2: Chasis.draw_fill();break;
        case 3: Chasis.draw_chess();break;
        }
    glPopMatrix();
}
