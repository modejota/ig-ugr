#include "lower_limb.h"

_lower_limb::_lower_limb(){}

void _lower_limb::draw(unsigned int mode){

    glMatrixMode(GL_MODELVIEW);

    //Dibujado del pie del robot
    glPushMatrix();
        glTranslatef(0,-1.6,0.3);
        switch (mode) {
        case 0: Pie.draw_point(); break;
        case 1: Pie.draw_line();  break;
        case 2: Pie.draw_fill();  break;
        case 3: Pie.draw_chess(); break;
        case 4: Pie.draw_illumination_flat_shading(); break;
        case 5: Pie.draw_illumination_smooth_shading(); break;
        case 6: Pie.draw_triangles_color();break;
        case 7: Pie.draw_vertices_color();break;
        }
    glPopMatrix();

    //Dibujado de la pierna del robot
    glPushMatrix();
        glTranslatef(0,-0.9,0);
        switch (mode) {
        case 0: Pata.draw_point(); break;
        case 1: Pata.draw_line();  break;
        case 2: Pata.draw_fill();  break;
        case 3: Pata.draw_chess(); break;
        case 4: Pata.draw_illumination_flat_shading(); break;
        case 5: Pata.draw_illumination_smooth_shading(); break;
        case 6: Pata.draw_triangles_color();break;
        case 7: Pata.draw_vertices_color();break;
        }
     glPopMatrix();


}

void _lower_limb::draw_point(){this->draw(0);}
void _lower_limb::draw_line(){this->draw(1);}
void _lower_limb::draw_fill(){this->draw(2);}
void _lower_limb::draw_chess(){this->draw(3);}
void _lower_limb::draw_illumination_flat_shading() {this->draw(4);}
void _lower_limb::draw_illumination_smooth_shading(){this->draw(5);}
void _lower_limb::draw_triangles_color(){this->draw(6);}
void _lower_limb::draw_vertices_color(){this->draw(7);}
