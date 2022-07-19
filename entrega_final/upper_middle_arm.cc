#include "upper_middle_arm.h"

void _upper_middle_arm::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);

    //Dibujado del hueso (cilindro)
    glPushMatrix();
//        glTranslatef(0.,0,0);
        switch (mode) {
        case 0: Antebrazo.draw_point(); break;
        case 1: Antebrazo.draw_line();  break;
        case 2: Antebrazo.draw_fill();  break;
        case 3: Antebrazo.draw_chess(); break;
        }
    glPopMatrix();

    //Dibujado de la junta (centrada en origen para permitir giro del hombro)
    glPushMatrix();
        switch (mode) {
        case 0: Union.draw_point(); break;
        case 1: Union.draw_line();  break;
        case 2: Union.draw_fill();  break;
        case 3: Union.draw_chess(); break;
        }
    glPopMatrix();
}

void _upper_middle_arm::draw_point(){
    this->draw(0);
}

void _upper_middle_arm::draw_line(){
    this->draw(1);
}

void _upper_middle_arm::draw_fill(){
    this->draw(2);
}

void _upper_middle_arm::draw_chess(){
    this->draw(3);
}
