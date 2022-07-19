#include "parte_arriba.h"

void _parte_arriba::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glTranslatef(-0.35,0.1,0);
        glRotatef(90,0,1,0);
        switch(mode){
        case 0: Barra.draw_point();break;
        case 1: Barra.draw_line();break;
        case 2: Barra.draw_fill();break;
        case 3: Barra.draw_chess();break;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(1,0,0);
        switch(mode){
        case 0: Brazo_gancho.draw_point();break;
        case 1: Brazo_gancho.draw_line();break;
        case 2: Brazo_gancho.draw_fill();break;
        case 3: Brazo_gancho.draw_chess();break;
        }
    glPopMatrix();
}
