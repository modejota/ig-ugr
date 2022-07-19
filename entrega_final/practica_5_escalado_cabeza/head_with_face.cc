#include "head_with_face.h"

void _head_with_face::draw(unsigned int mode){

    glMatrixMode(GL_MODELVIEW);

//  Dibujado de la cabeza en general
    glPushMatrix();
        glTranslatef(0,(0.8*factor_escala)/2,-0.05);
        glScalef(1,factor_escala,1);
        switch (mode) {
        case 0: Cabeza.draw_point(); break;
        case 1: Cabeza.draw_line();  break;
        case 2: Cabeza.draw_fill();  break;
        case 3: Cabeza.draw_chess(); break;
        case 4: Cabeza.draw_illumination_flat_shading(); break;
        case 5: Cabeza.draw_illumination_smooth_shading(); break;
        case 6: Cabeza.draw_triangles_color();break;
        case 7: Cabeza.draw_vertices_color();break;
        }
    glPopMatrix();

//  Dibujado de los ojos
    glPushMatrix();
        glTranslatef(0,0.8*factor_escala-0.3,0.5);
        switch (mode) {
        case 0: Ojos.draw_point(); break;
        case 1: Ojos.draw_line();  break;
        case 2: Ojos.draw_fill();  break;
        case 3: Ojos.draw_chess(); break;
        case 4: Ojos.draw_illumination_flat_shading(); break;
        case 5: Ojos.draw_illumination_smooth_shading(); break;
        case 6: Ojos.draw_triangles_color();break;
        case 7: Ojos.draw_vertices_color();break;
        }
    glPopMatrix();

}

void _head_with_face::draw_point(){this->draw(0);}
void _head_with_face::draw_line(){this->draw(1);}
void _head_with_face::draw_fill(){this->draw(2);}
void _head_with_face::draw_chess(){this->draw(3);}
void _head_with_face::draw_illumination_flat_shading(){this->draw(4);}
void _head_with_face::draw_illumination_smooth_shading(){this->draw(5);}
void _head_with_face::draw_triangles_color(){this->draw(6);}
void _head_with_face::draw_vertices_color(){this->draw(7);}

void _head_with_face::head_out(){
    if(factor_escala+variacion_factor_escala < LIMITE_ESCALADO_AGRANDAR){
        factor_escala+=variacion_factor_escala;
        topeAgrandar = false;
    }
    else {
        factor_escala = LIMITE_ESCALADO_AGRANDAR;
        topeAgrandar = true;
    }
    ultimoAgrandar = true;
}

void _head_with_face::head_in(){
    if(factor_escala-variacion_factor_escala > LIMITE_ESCALADO_ACORTAR){
        factor_escala-=variacion_factor_escala;
        topeAcortar = false;
    }
    else{
        factor_escala = LIMITE_ESCALADO_ACORTAR;
        topeAcortar = true;
    }
    ultimoAgrandar = false;
}

void _head_with_face::head_faster(){
    if(variacion_factor_escala+FACTOR_VARIACION_ESCALADO < LIMITE_VELOCIDAD){
        variacion_factor_escala+=FACTOR_VARIACION_ESCALADO;
    }
    else
        variacion_factor_escala=LIMITE_VELOCIDAD;
}

void _head_with_face::head_slower(){
    if(variacion_factor_escala-FACTOR_VARIACION_ESCALADO > 0){
        variacion_factor_escala-=FACTOR_VARIACION_ESCALADO;
    }
    else
        variacion_factor_escala=0.01;   //Valor por defecto
}

void _head_with_face::auto_head(){
    if(topeAgrandar)    head_in();
    if(topeAcortar)     head_out();
    else if(ultimoAgrandar) head_out();
    else                    head_in();
}

