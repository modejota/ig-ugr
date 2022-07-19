#include "antebrazo.h"

_antebrazo::_antebrazo(){}

void _antebrazo::draw(unsigned int mode) {
    glMatrixMode(GL_MODELVIEW);

    //Dibujado del cilindro
    glPushMatrix();
        glScalef(factor_escala,1,1);
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

void _antebrazo::draw_point(){this->draw(0);}
void _antebrazo::draw_line(){this->draw(1);}
void _antebrazo::draw_fill(){this->draw(2);}
void _antebrazo::draw_chess(){this->draw(3);}
void _antebrazo::draw_illumination_flat_shading(){this->draw(4);}
void _antebrazo::draw_illumination_smooth_shading(){this->draw(5);}
void _antebrazo::draw_triangles_color(){this->draw(6);}
void _antebrazo::draw_vertices_color(){this->draw(7);}

void _antebrazo::increase_factor_escala(){
    if((factor_escala+variacion_factor_escala) < LIMITE_ESCALADO_AGRANDAR) {
        factor_escala += variacion_factor_escala;
        topeAgrandar = false;
    }
    else {
        factor_escala = LIMITE_ESCALADO_AGRANDAR;
        topeAgrandar = true;
    }
    ultimoAgrandar = true;
}
void _antebrazo::decrease_factor_escala(){
    if((factor_escala-variacion_factor_escala) > LIMITE_ESCALADO_ACORTAR) {
        factor_escala -= variacion_factor_escala;
        topeAcortar = false;
    }
    else {
        factor_escala = LIMITE_ESCALADO_ACORTAR;
        topeAcortar = true;
    }
    ultimoAgrandar = false;
}
//Existe un limite máximo de velocidad, para que no se vaya de madre
void _antebrazo::increase_speed_antebrazo_scale(){
    if((variacion_factor_escala+FACTOR_VARIACION_ESCALADO) < LIMITE_VELOCIDAD)
        variacion_factor_escala += FACTOR_VARIACION_ESCALADO;
    else
        variacion_factor_escala = LIMITE_VELOCIDAD;
}
//La velocidad por defecto es la mínima, en todo caso, se produce escalado.
void _antebrazo::decrease_speed_antebrazo_scale(){
    if((variacion_factor_escala - FACTOR_VARIACION_ESCALADO) > 0)
        variacion_factor_escala -= FACTOR_VARIACION_ESCALADO;
    else
        variacion_factor_escala = 0.01;
}

void _antebrazo::auto_escalado_antebrazo()  {
    if(topeAgrandar) decrease_factor_escala();
    if(topeAcortar) increase_factor_escala();
    else if (ultimoAgrandar) increase_factor_escala();
    else    decrease_factor_escala();
}
