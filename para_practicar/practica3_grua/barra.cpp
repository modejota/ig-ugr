#include "barra.h"

void _barra::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.4,0.15,2);
        switch(mode){
        case 0: Barra.draw_point();break;
        case 1: Barra.draw_line();break;
        case 2: Barra.draw_fill();break;
        case 3: Barra.draw_chess();break;
        }
     glPopMatrix();
}
