#include "antebrazo_mano.h"


void _antebrazo_mano::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        switch (mode) {
        case 0: Antebrazo.draw_point(); break;
        case 1: Antebrazo.draw_line();  break;
        case 2: Antebrazo.draw_fill();  break;
        case 3: Antebrazo.draw_chess(); break;
        case 4: Antebrazo.draw_illumination_flat_shading(); break;
        case 5: Antebrazo.draw_illumination_smooth_shading(); break;
        case 6: Antebrazo.draw_triangles_color();break;
        case 7: Antebrazo.draw_vertices_color();break;
        }
    glPopMatrix();

    //Dibujado de la mano. Su desplazamiento depende del tamaño del antebrazo
    glPushMatrix();
        glTranslatef(Antebrazo.getTamanio()+0.3,0,0);
        switch (mode) {
        case 0: Mano.draw_point(); break;
        case 1: Mano.draw_line();  break;
        case 2: Mano.draw_fill();  break;
        case 3: Mano.draw_chess(); break;
        case 4: Mano.draw_illumination_flat_shading(); break;
        case 5: Mano.draw_illumination_smooth_shading(); break;
        case 6: Mano.draw_triangles_color();break;
        case 7: Mano.draw_vertices_color();break;
        }
    glPopMatrix();
}

void _antebrazo_mano::draw_point(){this->draw(0);}
void _antebrazo_mano::draw_line(){this->draw(1);}
void _antebrazo_mano::draw_fill(){this->draw(2);}
void _antebrazo_mano::draw_chess(){this->draw(3);}
void _antebrazo_mano::draw_illumination_flat_shading(){this->draw(4);}
void _antebrazo_mano::draw_illumination_smooth_shading(){this->draw(5);}
void _antebrazo_mano::draw_triangles_color(){this->draw(6);}
void _antebrazo_mano::draw_vertices_color(){this->draw(7);}
