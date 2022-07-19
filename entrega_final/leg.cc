#include "leg.h"

_leg::_leg() : Cilindro(30){}

void _leg::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.5,1.2,0.6);
        switch (mode) {
        case 0: Cilindro.draw_point(); break;
        case 1: Cilindro.draw_line();  break;
        case 2: Cilindro.draw_fill();  break;
        case 3: Cilindro.draw_chess(); break;
        case 4: Cilindro.draw_illumination_flat_shading(); break;
        case 5: Cilindro.draw_illumination_smooth_shading(); break;
        case 6: Cilindro.draw_triangles_color();break;
        case 7: Cilindro.draw_vertices_color();break;
        }
    glPopMatrix();
}

void _leg::draw_point(){this->draw(0);}
void _leg::draw_line(){this->draw(1);}
void _leg::draw_fill(){this->draw(2);}
void _leg::draw_chess(){this->draw(3);}
void _leg::draw_illumination_flat_shading(){this->draw(4);}
void _leg::draw_illumination_smooth_shading(){this->draw(5);}
void _leg::draw_triangles_color(){this->draw(6);}
void _leg::draw_vertices_color(){this->draw(7);}
