#include "chestZ.h"

_chest_z::_chest_z(){

    Vertices.resize(12);
    Triangles.resize(20);

    Vertices[0] =_vertex3f(-0.5,-0.5,0.5);
    Vertices[1] =_vertex3f(0,-0.5,0.5);
    Vertices[2] =_vertex3f(0.5,0,0.5);
    Vertices[3] =_vertex3f(0.5,0.5,0.5);
    Vertices[4] =_vertex3f(0,0,0.5);
    Vertices[5] =_vertex3f(-0.5,0,0.5);
    Vertices[6] =_vertex3f(-0.5,-0.5,-0.5);
    Vertices[7] =_vertex3f(0,-0.5,-0.5);
    Vertices[8] =_vertex3f(0.5,0,-0.5);
    Vertices[9] =_vertex3f(0.5,0.5,-0.5);
    Vertices[10] =_vertex3f(0,0,-0.5);
    Vertices[11] =_vertex3f(-0.5,0,-0.5);

    Triangles[0] =_vertex3ui(0,1,5);
    Triangles[1] =_vertex3ui(1,4,5);
    Triangles[2] =_vertex3ui(1,2,4);
    Triangles[3] =_vertex3ui(2,3,4);
    Triangles[4] =_vertex3ui(2,8,3);
    Triangles[5] =_vertex3ui(9,3,8);
    Triangles[6] =_vertex3ui(8,10,9);
    Triangles[7] =_vertex3ui(10,8,7);
    Triangles[8] =_vertex3ui(7,6,10);
    Triangles[9] =_vertex3ui(10,6,11);
    Triangles[10] =_vertex3ui(11,6,0);
    Triangles[11] =_vertex3ui(0,5,11);
    Triangles[12] =_vertex3ui(11,5,4);
    Triangles[13] =_vertex3ui(11,4,10);
    Triangles[14] =_vertex3ui(10,4,3);
    Triangles[15] =_vertex3ui(3,9,10);
    Triangles[16] =_vertex3ui(1,6,7);
    Triangles[17] =_vertex3ui(0,6,1);
    Triangles[18] =_vertex3ui(7,8,2);
    Triangles[19] =_vertex3ui(2,1,7);

    calcular_normales();
    calcular_colores();

}
