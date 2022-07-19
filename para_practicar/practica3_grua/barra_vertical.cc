#include "barra_vertical.h"

void _barra_vertical::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glScalef(0.4,2,0.4);
        switch(mode){
        case 0: Cubo.draw_point();break;
        case 1: Cubo.draw_line();break;
        case 2: Cubo.draw_fill();break;
        case 3: Cubo.draw_chess();break;
        }
    glPopMatrix();
}
