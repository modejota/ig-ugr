#include "pivote.h"

void _pivote::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glTranslatef(0,0.05,0);
        switch(mode){
        case 0: Base.draw_point();break;
        case 1: Base.draw_line();break;
        case 2: Base.draw_fill();break;
        case 3: Base.draw_chess();break;
        }
     glPopMatrix();

     glPushMatrix();
        glTranslatef(0,1.1,0);
         switch(mode){
         case 0: Barra.draw_point();break;
         case 1: Barra.draw_line();break;
         case 2: Barra.draw_fill();break;
         case 3: Barra.draw_chess();break;
         }
      glPopMatrix();
}
