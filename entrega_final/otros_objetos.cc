#include "otros_objetos.h"

//No es unidad. 2 puntos cortan al eje
_peon::_peon(unsigned int perfiles,unsigned int grados){
    
    Vertices.resize(14);

    Vertices[0] = _vertex3f(0.0,-1.4,0.0);
    Vertices[1] = _vertex3f(1.0,-1.4,0.0);
    Vertices[2] = _vertex3f(1.0,-1.1,0.0);
    Vertices[3] = _vertex3f(0.5,-0.7,0.0);
    Vertices[4] = _vertex3f(0.4,-0.4,0.0);
    Vertices[5] = _vertex3f(0.4,-0.4,0.0);
    Vertices[6] = _vertex3f(0.4, 0.5,0.0);
    Vertices[7] = _vertex3f(0.5, 0.6,0.0);
    Vertices[8] = _vertex3f(0.3, 0.6,0.0);
    Vertices[9] = _vertex3f(0.5, 0.8,0.0);
    Vertices[10] = _vertex3f(0.55,1.0,0.0);
    Vertices[11] = _vertex3f(0.5,1.2,0.0);
    Vertices[12] = _vertex3f(0.3,1.4,0.0);
    Vertices[13] = _vertex3f(0.0,1.4,0.0);

    this->revolucion(perfiles,grados);
    calcular_colores();
}

//Solo 1 punto corta eje (tapa abajo)
_copa::_copa(unsigned int perfiles,unsigned int grados){

    Vertices.resize(3);

    Vertices[0] = _vertex3f(0.5,0.5,0.0);
    Vertices[1] = _vertex3f(0.25,-0.5,0.0);
    Vertices[2] = _vertex3f(0.0,-0.5,0.0);

    this->revolucion(perfiles,grados);
    calcular_colores();

}

//Solo 1 punto corta eje (tapa arriba)
_copa_reves::_copa_reves(unsigned int perfiles,unsigned int grados){
    Vertices.resize(3);

    Vertices[0] = _vertex3f(0.5,-0.5,0.0);
    Vertices[1] = _vertex3f(0.25,0.5,0.0);
    Vertices[2] = _vertex3f(0.0, 0.5,0.0);

    this->revolucion(perfiles,grados);
    calcular_colores();
}

//Que 0 puntos corten al eje
_hormigonera::_hormigonera(unsigned int perfiles,unsigned int grados){

    Vertices.resize(3);

    Vertices[0] = _vertex3f(0.2,-0.5,0.0);
    Vertices[1] = _vertex3f(0.4, 0.0,0.0);
    Vertices[2] = _vertex3f(0.2, 0.5,0.0);

    this->revolucion(perfiles,grados);
    calcular_colores();
}


