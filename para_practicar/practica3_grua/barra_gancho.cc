#include "barra_gancho.h"

void _barra_gancho::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glTranslatef(0,0.1,-0.1);
        switch(mode){
        case 0: Barra.draw_point();break;
        case 1: Barra.draw_line();break;
        case 2: Barra.draw_fill();break;
        case 3: Barra.draw_chess();break;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0,0,0.9);
        switch(mode){
        case 0: Gancho.draw_point();break;
        case 1: Gancho.draw_line();break;
        case 2: Gancho.draw_fill();break;
        case 3: Gancho.draw_chess();break;
        }
    glPopMatrix();
}
