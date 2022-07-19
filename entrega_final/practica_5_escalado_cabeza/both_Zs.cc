#include "both_Zs.h"

void _both_Z::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);

    //Dibujado de Z de la izquierda
    glPushMatrix();
        glTranslatef(-0.7,0,0);
        glScalef(-1.2,1.2,0.2);
        switch (mode) {
        case 0: front_Z.draw_point(); break;
        case 1: front_Z.draw_line();  break;
        case 2: front_Z.draw_fill();  break;
        case 3: front_Z.draw_chess(); break;
        case 4: front_Z.draw_illumination_flat_shading(); break;
        case 5: front_Z.draw_illumination_smooth_shading(); break;
        case 6: front_Z.draw_triangles_color();break;
        case 7: front_Z.draw_vertices_color();break;
        }
    glPopMatrix();

    //Dibujado de Z de la derecha
    glPushMatrix();
        glTranslatef(0.7,0,0);          
        glScalef(1.2,1.2,0.2);
        switch (mode) {
        case 0: front_Z.draw_point(); break;
        case 1: front_Z.draw_line();  break;
        case 2: front_Z.draw_fill();  break;
        case 3: front_Z.draw_chess(); break;
        case 4: front_Z.draw_illumination_flat_shading(); break;
        case 5: front_Z.draw_illumination_smooth_shading(); break;
        case 6: front_Z.draw_triangles_color();break;
        case 7: front_Z.draw_vertices_color();break;
        }
    glPopMatrix();
}

void _both_Z::draw_point(){this->draw(0);}
void _both_Z::draw_line(){this->draw(1);}
void _both_Z::draw_fill(){this->draw(2);}
void _both_Z::draw_chess(){this->draw(3);}
void _both_Z::draw_illumination_flat_shading(){this->draw(4);}
void _both_Z::draw_illumination_smooth_shading(){this->draw(5);}
void _both_Z::draw_triangles_color(){this->draw(6);}
void _both_Z::draw_vertices_color(){this->draw(7);}
