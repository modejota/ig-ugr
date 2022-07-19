#include "sphere.h"
#include <cmath>

_sphere::_sphere(unsigned int perfiles, unsigned int puntos_perfil, unsigned int grados, float Size){

   Vertices.resize(puntos_perfil);

   Vertices[0] = _vertex3f(0.0,Size,0.0);

   for(unsigned int i=1; i<(puntos_perfil-1); i++){
       double angulo = (M_PI * i) / (puntos_perfil-1);
       Vertices[i] = _vertex3f(Size*sin(angulo), Size*cos(angulo),0.0);
   }

   Vertices[puntos_perfil-1] = _vertex3f(0.0,-Size,0.0);

   //Primer y ultimo vertice del perfil se meten a mano para evitar falta de precisión en calculos trigonometricos

   this->revolucion(perfiles,grados);

   this->calcular_normales();
   calcular_colores();
}

void _sphere::calcular_normales(){
    NormalesVertices.resize(Vertices.size());
    for (unsigned int i = 0; i < Vertices.size(); i++){
        //Como esta centrada en el orgen la normal es el propio vertice
        NormalesVertices[i] = _vertex3f(Vertices[i].x, Vertices[i].y, Vertices[i].z);
        NormalesVertices[i].normalize();
    }
    NormalesTriangles.resize(Triangles.size());
    for (unsigned int i = 0; i < Triangles.size(); i+=2){
            NormalesTriangles[i] = (NormalesVertices[Triangles[i]._0] +
                          NormalesVertices[Triangles[i]._1] +
                          NormalesVertices[Triangles[i]._2]) / 3;
            NormalesTriangles[i].normalize();
            NormalesTriangles[i+1] = NormalesTriangles[i];
    }
}



