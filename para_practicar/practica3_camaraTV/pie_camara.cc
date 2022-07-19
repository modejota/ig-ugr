#include "pie_camara.h"

_pie_camara::_pie_camara() : Pie(20){}

void _pie_camara::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.2,0.4,0.2);
        switch(mode){
        case 0: Pie.draw_point();break;
        case 1: Pie.draw_line();break;
        case 2: Pie.draw_fill();break;
        case 3: Pie.draw_chess();break;
        }
    glPopMatrix();
}

void _pie_camara::draw_point() { this->draw(0); }
void _pie_camara::draw_line() { this->draw(1); }
void _pie_camara::draw_fill() { this->draw(2); }
void _pie_camara::draw_chess() { this->draw(3); }
