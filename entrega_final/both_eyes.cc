#include "both_eyes.h"

void _both_eyes::draw(unsigned int mode) {

    glMatrixMode(GL_MODELVIEW);
    //Dibujado ojo derecho
    glPushMatrix();
        glTranslatef(0.3,0,0);
        switch (mode) {
        case 0: Ojo.draw_point(); break;
        case 1: Ojo.draw_line();  break;
        case 2: Ojo.draw_fill();  break;
        case 3: Ojo.draw_chess(); break;
        case 4: Ojo.draw_illumination_flat_shading(); break;
        case 5: Ojo.draw_illumination_smooth_shading(); break;
        case 6: Ojo.draw_triangles_color();break;
        case 7: Ojo.draw_vertices_color();break;
        }
    glPopMatrix();

    //Dibujado ojo izquierdo
    glPushMatrix();
        glTranslatef(-0.3,0,0);
        switch (mode) {
        case 0: Ojo.draw_point(); break;
        case 1: Ojo.draw_line();  break;
        case 2: Ojo.draw_fill();  break;
        case 3: Ojo.draw_chess(); break;
        case 4: Ojo.draw_illumination_flat_shading(); break;
        case 5: Ojo.draw_illumination_smooth_shading(); break;
        case 6: Ojo.draw_triangles_color();break;
        case 7: Ojo.draw_vertices_color();break;
        }
    glPopMatrix();

}

void _both_eyes::draw_point(){this->draw(0);}
void _both_eyes::draw_line(){this->draw(1);}
void _both_eyes::draw_fill(){this->draw(2);}
void _both_eyes::draw_chess(){this->draw(3);}
void _both_eyes::draw_illumination_flat_shading(){this->draw(4);}
void _both_eyes::draw_illumination_smooth_shading(){this->draw(5);}
void _both_eyes::draw_triangles_color(){this->draw(6);}
void _both_eyes::draw_vertices_color(){this->draw(7);}
