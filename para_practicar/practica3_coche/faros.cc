#include "faros.h"

void _faros::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    //Dibujado del faro izquierdo
    glPushMatrix();
        glTranslatef(-0.6,0,0);
        switch(mode){
        case 0: Faro.draw_point();break;
        case 1: Faro.draw_line();break;
        case 2: Faro.draw_fill();break;
        case 3: Faro.draw_chess();break;
        }
    glPopMatrix();
    //Dibujado del faro derecho
    glPushMatrix();
        glTranslatef(0.6,0,0);
        switch(mode){
        case 0: Faro.draw_point();break;
        case 1: Faro.draw_line();break;
        case 2: Faro.draw_fill();break;
        case 3: Faro.draw_chess();break;
        }
    glPopMatrix();
}
