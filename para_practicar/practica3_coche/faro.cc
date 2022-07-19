#include "faro.h"

_faro::_faro() : Faro(30) {}

void _faro::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.5,0.5,0.1);
        glRotatef(90,1,0,0);
        switch(mode){
        case 0: Faro.draw_point();break;
        case 1: Faro.draw_line();break;
        case 2: Faro.draw_fill();break;
        case 3: Faro.draw_chess();break;
        }
    glPopMatrix();
}
