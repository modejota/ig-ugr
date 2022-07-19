#include "cuerpo_camara.h"

void _cuerpo_camara::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);

    //Ahora se supone que esta centrado con respecto del origen
    glPushMatrix();
       glTranslatef(0.15,0,0);
        switch(mode){
        case 0: Lente.draw_point();break;
        case 1: Lente.draw_line();break;
        case 2: Lente.draw_fill();break;
        case 3: Lente.draw_chess();break;
        }
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.05,0,0);
        switch(mode){
        case 0: Caja.draw_point();break;
        case 1: Caja.draw_line();break;
        case 2: Caja.draw_fill();break;
        case 3: Caja.draw_chess();break;
        }
    glPopMatrix();
}

void _cuerpo_camara::draw_point() { this->draw(0); }
void _cuerpo_camara::draw_line() { this->draw(1); }
void _cuerpo_camara::draw_fill() { this->draw(2); }
void _cuerpo_camara::draw_chess() { this->draw(3); }
