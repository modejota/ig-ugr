#include "brazo_arriba.h"

_brazo_arriba::_brazo_arriba(){}

void _brazo_arriba::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);

    //Dibujado del cilindro
    glPushMatrix();
        glScalef(1.5,1,1);
        glTranslatef(0.3,0,0);
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

    glPushMatrix();
        switch (mode) {
        case 0: Rotula.draw_point(); break;
        case 1: Rotula.draw_line();  break;
        case 2: Rotula.draw_fill();  break;
        case 3: Rotula.draw_chess(); break;
        case 4: Rotula.draw_illumination_flat_shading(); break;
        case 5: Rotula.draw_illumination_smooth_shading(); break;
        case 6: Rotula.draw_triangles_color();break;
        case 7: Rotula.draw_vertices_color();break;
        }
    glPopMatrix();
}

void _brazo_arriba::draw_point(){this->draw(0);}
void _brazo_arriba::draw_line(){this->draw(1);}
void _brazo_arriba::draw_fill(){this->draw(2);}
void _brazo_arriba::draw_chess(){this->draw(3);}
void _brazo_arriba::draw_illumination_flat_shading(){this->draw(4);}
void _brazo_arriba::draw_illumination_smooth_shading(){this->draw(5);}
void _brazo_arriba::draw_triangles_color(){this->draw(6);}
void _brazo_arriba::draw_vertices_color(){this->draw(7);}
