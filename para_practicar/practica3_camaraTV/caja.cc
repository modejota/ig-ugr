#include "caja.h"

void _caja::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.4,0.3,0.4);
        switch(mode){
        case 0: Caja.draw_point();break;
        case 1: Caja.draw_line();break;
        case 2: Caja.draw_fill();break;
        case 3: Caja.draw_chess();break;
        }
    glPopMatrix();
}


void _caja::draw_point(){ this->draw(0); }
void _caja::draw_line() { this->draw(1); }
void _caja::draw_fill() { this->draw(2); }
void _caja::draw_chess(){ this->draw(3); }
