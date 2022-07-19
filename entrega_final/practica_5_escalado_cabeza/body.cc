#include "body.h"

void _body::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(2,2,1);
        switch (mode) {
        case 0: Pecho.draw_point(); break;
        case 1: Pecho.draw_line();  break;
        case 2: Pecho.draw_fill();  break;
        case 3: Pecho.draw_chess(); break;
        case 4: Pecho.draw_illumination_flat_shading(); break;
        case 5: Pecho.draw_illumination_smooth_shading(); break;
        case 6: Pecho.draw_triangles_color();break;
        case 7: Pecho.draw_vertices_color();break;
        }
    glPopMatrix();
}

void _body::draw_point(){this->draw(0);}
void _body::draw_line(){this->draw(1);}
void _body::draw_fill(){this->draw(2);}
void _body::draw_chess(){this->draw(3);}
void _body::draw_illumination_flat_shading(){this->draw(4);}
void _body::draw_illumination_smooth_shading(){this->draw(5);}
void _body::draw_triangles_color(){this->draw(6);}
void _body::draw_vertices_color(){this->draw(7);}
