#include "sphere.h"
#include <cmath>

_sphere::_sphere(unsigned int perfiles, unsigned int puntos_perfil, float Size){

   Vertices.resize(puntos_perfil);

   Vertices[0] = _vertex3f(0.0,Size,0.0);

   for(unsigned int i=1; i<(puntos_perfil-1); i++){
       double angulo = (M_PI * i) / (puntos_perfil-1);
       Vertices[i] = _vertex3f(Size*sin(angulo), Size*cos(angulo),0.0);
   }

   Vertices[puntos_perfil-1] = _vertex3f(0.0,-Size,0.0);

   this->revolucion(perfiles);

}
