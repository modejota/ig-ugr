#include "lower_middle_arm.h"

void _lower_middle_arm::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);

    //Dibujado del antebrazo (codo + huesos)
    glPushMatrix();
        glTranslatef(0.4,0,0);
        switch (mode) {
        case 0: Antebrazo.draw_point(); break;
        case 1: Antebrazo.draw_line();  break;
        case 2: Antebrazo.draw_fill();  break;
        case 3: Antebrazo.draw_chess(); break;
        }
    glPopMatrix();

    //Dibujado de la mano
    glPushMatrix();
        glTranslatef(1.7,0,0);
        switch (mode) {
        case 0: Mano.draw_point(); break;
        case 1: Mano.draw_line();  break;
        case 2: Mano.draw_fill();  break;
        case 3: Mano.draw_chess(); break;
        }
    glPopMatrix();
}

void _lower_middle_arm::draw_point(){
    this->draw(0);
}

void _lower_middle_arm::draw_line(){
    this->draw(1);
}

void _lower_middle_arm::draw_fill(){
    this->draw(2);
}

void _lower_middle_arm::draw_chess(){
    this->draw(3);
}
