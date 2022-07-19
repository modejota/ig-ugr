#include "base.h"

void _base::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(2,0.1,1.5);
        switch(mode){
        case 0: Base.draw_point();break;
        case 1: Base.draw_line();break;
        case 2: Base.draw_fill();break;
        case 3: Base.draw_chess();break;
        }
     glPopMatrix();
}
