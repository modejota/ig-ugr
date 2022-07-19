#include "foot.h"

void _foot::draw(unsigned int mode){

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.5,0.2,1.2);
        switch (mode) {
        case 0: Cubo.draw_point(); break;
        case 1: Cubo.draw_line();  break;
        case 2: Cubo.draw_fill();  break;
        case 3: Cubo.draw_chess(); break;
        case 4: Cubo.draw_illumination_flat_shading(); break;
        case 5: Cubo.draw_illumination_smooth_shading(); break;
        case 6: Cubo.draw_triangles_color();break;
        case 7: Cubo.draw_vertices_color();break;
        }
    glPopMatrix();

}

void _foot::draw_point(){this->draw(0);}
void _foot::draw_line(){this->draw(1);}
void _foot::draw_fill(){this->draw(2);}
void _foot::draw_chess(){this->draw(3);}
void _foot::draw_illumination_flat_shading() {this->draw(4);}
void _foot::draw_illumination_smooth_shading(){this->draw(5);}
void _foot::draw_triangles_color(){this->draw(6);}
void _foot::draw_vertices_color(){this->draw(7);}
