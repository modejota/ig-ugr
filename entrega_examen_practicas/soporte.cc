#include "soporte.h"

_soporte::_soporte() : Soporte(40) {}

void _soporte::draw(unsigned int mode){
    glMatrixMode(GL_MODELVIEW);
    //Base de la sombrilla
    glPushMatrix();
        glTranslatef(0,7.5,0);
        glScalef(1,15,1);
        switch(mode){
        case 0: Soporte.draw_point();break;
        case 1: Soporte.draw_line();break;
        case 2: Soporte.draw_fill();break;
        case 3: Soporte.draw_chess();break;
        }
    glPopMatrix();

    //Plana a la derecha
    glPushMatrix();
        glTranslatef(0.5,15,0);
        switch(mode){
        case 0: Varilla.draw_point();break;
        case 1: Varilla.draw_line();break;
        case 2: Varilla.draw_fill();break;
        case 3: Varilla.draw_chess();break;
        }
    glPopMatrix();

    //Arriba derecha
    glPushMatrix();
        glTranslatef(0.35,15,-0.35);
        glRotatef(360/6,0,1,0);
        switch(mode){
        case 0: Varilla.draw_point();break;
        case 1: Varilla.draw_line();break;
        case 2: Varilla.draw_fill();break;
        case 3: Varilla.draw_chess();break;
        }
    glPopMatrix();

    //Arriba a la izquierda
    glPushMatrix();
        glTranslatef(-0.35,15,-0.35);
        glRotatef(360*2/6,0,1,0);
        switch(mode){
        case 0: Varilla.draw_point();break;
        case 1: Varilla.draw_line();break;
        case 2: Varilla.draw_fill();break;
        case 3: Varilla.draw_chess();break;
        }
    glPopMatrix();

    //Plana izquierda
    glPushMatrix();
        glTranslatef(-0.5,15,0);
        glRotatef(360*3/6,0,1,0);
        switch(mode){
        case 0: Varilla.draw_point();break;
        case 1: Varilla.draw_line();break;
        case 2: Varilla.draw_fill();break;
        case 3: Varilla.draw_chess();break;
        }
    glPopMatrix();

    //Abajo izquierda
    glPushMatrix();
        glTranslatef(-0.35,15,0.35);
        glRotatef(360*4/6,0,1,0);
        switch(mode){
        case 0: Varilla.draw_point();break;
        case 1: Varilla.draw_line();break;
        case 2: Varilla.draw_fill();break;
        case 3: Varilla.draw_chess();break;
        }
    glPopMatrix();

    //Abajo derecha
    glPushMatrix();
        glTranslatef(0.35,15,0.35);
        glRotatef(360*5/6,0,1,0);
        switch(mode){
        case 0: Varilla.draw_point();break;
        case 1: Varilla.draw_line();break;
        case 2: Varilla.draw_fill();break;
        case 3: Varilla.draw_chess();break;
        }
    glPopMatrix();

}

// Gomez -> La G es el numero 7 en el alfabeto
// (7 % 5) + 4 = 6

// Las translaciones de las varillas en X y Z se calculan como 0.5*cos(45)
// Positivas o negativas en funcion de cada varilla
