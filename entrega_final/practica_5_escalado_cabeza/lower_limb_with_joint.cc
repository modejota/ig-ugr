#include "lower_limb_with_joint.h"

void _lower_limb_with_joint::draw(unsigned int mode){

    glMatrixMode(GL_MODELVIEW);

    //Dibujado del pierna del robot
    glPushMatrix();
        switch (mode) {
        case 0: Pierna.draw_point(); break;
        case 1: Pierna.draw_line();  break;
        case 2: Pierna.draw_fill();  break;
        case 3: Pierna.draw_chess(); break;
        case 4: Pierna.draw_illumination_flat_shading(); break;
        case 5: Pierna.draw_illumination_smooth_shading(); break;
        case 6: Pierna.draw_triangles_color();break;
        case 7: Pierna.draw_vertices_color();break;
        }
    glPopMatrix();

    //Dibujado de la union con el cuerpo
    glPushMatrix();
        switch (mode) {
        case 0: Union.draw_point(); break;
        case 1: Union.draw_line();  break;
        case 2: Union.draw_fill();  break;
        case 3: Union.draw_chess(); break;
        case 4: Union.draw_illumination_flat_shading(); break;
        case 5: Union.draw_illumination_smooth_shading(); break;
        case 6: Union.draw_triangles_color();break;
        case 7: Union.draw_vertices_color();break;
        }
     glPopMatrix();


}

void _lower_limb_with_joint::draw_point()   {this->draw(0);}
void _lower_limb_with_joint::draw_line()    {this->draw(1);}
void _lower_limb_with_joint::draw_fill()    {this->draw(2);}
void _lower_limb_with_joint::draw_chess()   {this->draw(3);}
void _lower_limb_with_joint::draw_illumination_flat_shading() {this->draw(4);}
void _lower_limb_with_joint::draw_illumination_smooth_shading(){this->draw(5);}
void _lower_limb_with_joint::draw_triangles_color(){this->draw(6);}
void _lower_limb_with_joint::draw_vertices_color(){this->draw(7);}
