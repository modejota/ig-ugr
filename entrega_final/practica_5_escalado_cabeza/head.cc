#include "head.h"

void _head::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(1.4,0.8,1);
        switch (mode) {
        case 0: Cabeza.draw_point(); break;
        case 1: Cabeza.draw_line();  break;
        case 2: Cabeza.draw_fill();  break;
        case 3: Cabeza.draw_chess(); break;
        case 4: Cabeza.draw_illumination_flat_shading(); break;
        case 5: Cabeza.draw_illumination_smooth_shading(); break;
        case 6: Cabeza.draw_triangles_color();break;
        case 7: Cabeza.draw_vertices_color();break;
        }
    glPopMatrix();
}

void _head::draw_point(){this->draw(0);}
void _head::draw_line(){this->draw(1);}
void _head::draw_fill(){this->draw(2);}
void _head::draw_chess(){this->draw(3);}
void _head::draw_illumination_flat_shading(){this->draw(4);}
void _head::draw_illumination_smooth_shading(){this->draw(5);}
void _head::draw_triangles_color(){this->draw(6);}
void _head::draw_vertices_color(){this->draw(7);}
