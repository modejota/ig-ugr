#include "lente.h"

_lente::_lente() : Lente(20){}

void _lente::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(90,0,0,1);    //Creo que habra que cambiarlo
        glScalef(0.2,0.2,0.2);
        switch(mode){
        case 0: Lente.draw_point();break;
        case 1: Lente.draw_line();break;
        case 2: Lente.draw_fill();break;
        case 3: Lente.draw_chess();break;
        }
    glPopMatrix();
}

void _lente::draw_point(){ this->draw(0); }
void _lente::draw_line() { this->draw(1); }
void _lente::draw_fill() { this->draw(2); }
void _lente::draw_chess(){ this->draw(3); }
