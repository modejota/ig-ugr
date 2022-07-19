/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
  glBegin(GL_TRIANGLES);
  for (unsigned int i=0;i<Triangles.size();i++){
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
  }
  glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
        for (unsigned int i=0;i<Triangles.size();i++){
            if (i == Triangulo_pick)    {    glColor3fv((GLfloat *) &YEllOW); }
            else { glColor3fv((GLfloat *) &BLUE); }
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
        for (unsigned int i=0;i<Triangles.size();i++){
            if (i%2 == 0)
                glColor3fv((GLfloat *) &GREEN);
            else
                glColor3fv((GLfloat *) &RED);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_triangles_color(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        glColor3fv((GLfloat *) &Triangles_color[i]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_vertices_color(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        glColor3fv((GLfloat *) &Vertices_color[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glColor3fv((GLfloat *) &Vertices_color[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glColor3fv((GLfloat *) &Vertices_color[Triangles[i]._2]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_illumination_flat_shading(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_FLAT);

    glBegin(GL_TRIANGLES);
        for (unsigned int i = 0; i < Triangles.size(); i++){
            glNormal3fv((GLfloat *) &NormalesTriangles[i]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    glEnd();

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_illumination_smooth_shading(){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glShadeModel(GL_SMOOTH);

    glBegin(GL_TRIANGLES);
        for (unsigned int i = 0; i < Triangles.size(); i++){
            glNormal3fv((GLfloat *) &NormalesVertices[Triangles[i]._0]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
            glNormal3fv((GLfloat *) &NormalesVertices[Triangles[i]._1]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
            glNormal3fv((GLfloat *) &NormalesVertices[Triangles[i]._2]);
            glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
        }
    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_texture(){
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        glTexCoord2f(CoordTex[Triangles[i]._0].x, CoordTex[Triangles[i]._0].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glTexCoord2f(CoordTex[Triangles[i]._1].x, CoordTex[Triangles[i]._1].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glTexCoord2f(CoordTex[Triangles[i]._2].x, CoordTex[Triangles[i]._2].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);

}

///*****************************************************************************//**
// *
// *
// *
// *****************************************************************************/

void _object3D::draw_texture_illumination_flat_shading(){
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT,GL_FILL);
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        glNormal3fv((GLfloat *) &NormalesTriangles[i]);

        glTexCoord2f(CoordTex[Triangles[i]._0].x, CoordTex[Triangles[i]._0].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

        glTexCoord2f(CoordTex[Triangles[i]._1].x, CoordTex[Triangles[i]._1].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glTexCoord2f(CoordTex[Triangles[i]._2].x, CoordTex[Triangles[i]._2].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_texture_illumination_smooth_shading(){
    glEnable(GL_TEXTURE_2D);
    glPolygonMode(GL_FRONT,GL_FILL);
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
    for(unsigned int i = 0; i < Triangles.size(); i++){
        glNormal3fv((GLfloat *) &NormalesVertices[Triangles[i]._0]);
        glTexCoord2f(CoordTex[Triangles[i]._0].x, CoordTex[Triangles[i]._0].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);

        glNormal3fv((GLfloat *) &NormalesVertices[Triangles[i]._1]);
        glTexCoord2f(CoordTex[Triangles[i]._1].x, CoordTex[Triangles[i]._1].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);

        glNormal3fv((GLfloat *) &NormalesVertices[Triangles[i]._2]);
        glTexCoord2f(CoordTex[Triangles[i]._2].x, CoordTex[Triangles[i]._2].y);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::calcular_normales(){
    NormalesTriangles.resize(Triangles.size());
    for (unsigned int i = 0; i < Triangles.size(); i++) {
        _vertex3f A = Vertices[Triangles[i]._1]-Vertices[Triangles[i]._0];
        _vertex3f B = Vertices[Triangles[i]._2]-Vertices[Triangles[i]._0];
        NormalesTriangles[i] = (A.cross_product(B)).normalize();
    }
    NormalesVertices.resize(Vertices.size());
    for (unsigned int i = 0; i < Triangles.size(); i++){
       NormalesVertices[Triangles[i]._0] += NormalesTriangles[i];
       NormalesVertices[Triangles[i]._1] += NormalesTriangles[i];
       NormalesVertices[Triangles[i]._2] += NormalesTriangles[i];
    }

    for (unsigned int i = 0; i < NormalesVertices.size(); i++){
       NormalesVertices[i].normalize();
    }

}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::calcular_colores(){
    random_device RD;
    mt19937 MT(RD());
    uniform_real_distribution<float> Random;

    _vertex3f Color;
    Triangles_color.resize(Triangles.size());
    for(unsigned int i = 0; i < Triangles_color.size(); i++){
        Color.r = Random(MT);
        Color.g = Random(MT);
        Color.b = Random(MT);
        Triangles_color[i] = Color;
    }

    Vertices_color.resize(Vertices.size());
    for(unsigned int i = 0; i < Vertices_color.size(); i++){
        Color.r = Random(MT);
        Color.g = Random(MT);
        Color.b = Random(MT);
        Vertices_color[i] = Color;
    }
}

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_for_selection(){

    float R,G,B;

    glPolygonMode(GL_FRONT,GL_FILL);
    glBegin(GL_TRIANGLES);
    for (unsigned int i=0;i<Triangles.size();i++){
        R = (i & 0x00FF0000) >> 16;
        G = (i & 0x0000FF00) >> 8;
        B = (i & 0x000000FF);

        glColor3f(R/255.0, G/255.0, B/255.0);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
        glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
    }
    glEnd();
}
