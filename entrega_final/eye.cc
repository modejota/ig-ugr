#include "eye.h"

_eye::_eye() : Eye(15){}

void _eye::draw(unsigned int mode) {

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glRotatef(90,1,0,0);
        glScalef(0.4,0.1,0.4);
        switch (mode) {
        case 0: Eye.draw_point(); break;
        case 1: Eye.draw_line();  break;
        case 2: Eye.draw_fill();  break;
        case 3: Eye.draw_chess(); break;
        case 4: Eye.draw_illumination_flat_shading(); break;
        case 5: Eye.draw_illumination_smooth_shading(); break;
        case 6: Eye.draw_triangles_color();break;
        case 7: Eye.draw_vertices_color();break;
        }
    glPopMatrix();

}

void _eye::draw_point(){this->draw(0);}
void _eye::draw_line(){this->draw(1);}
void _eye::draw_fill(){this->draw(2);}
void _eye::draw_chess(){this->draw(3);}
void _eye::draw_illumination_flat_shading(){this->draw(4);}
void _eye::draw_illumination_smooth_shading(){this->draw(5);}
void _eye::draw_triangles_color(){this->draw(6);}
void _eye::draw_vertices_color(){this->draw(7);}
