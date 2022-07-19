#include "body_with_accessories.h"

void _body_with_accessories::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0,-0.1);
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

    //Dibujado de las Z
    glPushMatrix();
        glTranslatef(0.0,0.8,0.5);
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

void _body_with_accessories::draw_point(){this->draw(0);}
void _body_with_accessories::draw_line(){this->draw(1);}
void _body_with_accessories::draw_fill(){this->draw(2);}
void _body_with_accessories::draw_chess(){this->draw(3);}
void _body_with_accessories::draw_illumination_flat_shading(){this->draw(4);}
void _body_with_accessories::draw_illumination_smooth_shading(){this->draw(5);}
void _body_with_accessories::draw_triangles_color(){this->draw(6);}
void _body_with_accessories::draw_vertices_color(){this->draw(7);}
