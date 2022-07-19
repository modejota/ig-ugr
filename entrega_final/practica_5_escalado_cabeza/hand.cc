#include "hand.h"

_hand::_hand() {
    Mano.cargarPLYR("./ply_models/mazingerz_hand_rev.ply",20);
}

void _hand::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glScalef(0.6,0.8,0.8);
        glRotatef(90,0,0,1);
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

void _hand::draw_point(){this->draw(0);}
void _hand::draw_line(){this->draw(1);}
void _hand::draw_fill(){this->draw(2);}
void _hand::draw_chess(){this->draw(3);}
void _hand::draw_illumination_flat_shading(){this->draw(4);}
void _hand::draw_illumination_smooth_shading(){this->draw(5);}
void _hand::draw_triangles_color(){this->draw(6);}
void _hand::draw_vertices_color(){this->draw(7);}
