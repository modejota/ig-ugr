#include "base.h"

_base::_base() : Base(20){}

void _base::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(1,0.05,1);
        switch(mode){
        case 0: Base.draw_point();break;
        case 1: Base.draw_line();break;
        case 2: Base.draw_fill();break;
        case 3: Base.draw_chess();break;
        }
    glPopMatrix();
}


void _base::draw_point(){ this->draw(0); }
void _base::draw_line() { this->draw(1); }
void _base::draw_fill() { this->draw(2); }
void _base::draw_chess(){ this->draw(3); }
