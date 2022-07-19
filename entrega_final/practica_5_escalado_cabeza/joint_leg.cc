#include "joint_leg.h"

_joint_leg::_joint_leg() : Esfera(30,30) {}

void _joint_leg::draw(unsigned int mode) {

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.5,0.6,0.6);
        switch (mode) {
        case 0: Esfera.draw_point(); break;
        case 1: Esfera.draw_line();  break;
        case 2: Esfera.draw_fill();  break;
        case 3: Esfera.draw_chess(); break;
        case 4: Esfera.draw_illumination_flat_shading(); break;
        case 5: Esfera.draw_illumination_smooth_shading(); break;
        case 6: Esfera.draw_triangles_color();break;
        case 7: Esfera.draw_vertices_color();break;
        }
    glPopMatrix();

}

void _joint_leg::draw_point()   {this->draw(0);}
void _joint_leg::draw_line()    {this->draw(1);}
void _joint_leg::draw_fill()    {this->draw(2);}
void _joint_leg::draw_chess()   {this->draw(3);}
void _joint_leg::draw_illumination_flat_shading(){this->draw(4);}
void _joint_leg::draw_illumination_smooth_shading(){this->draw(5);}
void _joint_leg::draw_triangles_color(){this->draw(6);}
void _joint_leg::draw_vertices_color(){this->draw(7);}
