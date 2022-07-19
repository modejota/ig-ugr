#include "arm_bone.h"

_arm_bone::_arm_bone() : Cilindro (30) {}

void _arm_bone::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
        glRotatef(90,0,0,1);
        glScalef(0.6,0.6,0.6);
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

void _arm_bone::draw_point(){this->draw(0);}
void _arm_bone::draw_line(){this->draw(1);}
void _arm_bone::draw_fill(){this->draw(2);}
void _arm_bone::draw_chess(){this->draw(3);}
void _arm_bone::draw_illumination_flat_shading(){this->draw(4);}
void _arm_bone::draw_illumination_smooth_shading(){this->draw(5);}
void _arm_bone::draw_triangles_color(){this->draw(6);}
void _arm_bone::draw_vertices_color(){this->draw(7);}
