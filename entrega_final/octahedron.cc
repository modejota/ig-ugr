#include "octahedron.h"

_octahedron::_octahedron(float Size){

    Vertices.resize(6);

    Vertices[0] = _vertex3f( 0.0, 0.0, Size/2);
    Vertices[1] = _vertex3f( Size/2, 0.0, 0.0);
    Vertices[2] = _vertex3f( 0.0, 0.0,-Size/2);
    Vertices[3] = _vertex3f(-Size/2, 0.0, 0.0);
    Vertices[4] = _vertex3f( 0.0, Size/2, 0.0);
    Vertices[5] = _vertex3f( 0.0,-Size/2, 0.0);

    Triangles.resize(8);

    Triangles[0] = _vertex3ui(0,1,4);
    Triangles[1] = _vertex3ui(1,2,4);
    Triangles[2] = _vertex3ui(2,3,4);
    Triangles[3] = _vertex3ui(3,0,4);
    Triangles[4] = _vertex3ui(0,5,1);
    Triangles[5] = _vertex3ui(1,5,2);
    Triangles[6] = _vertex3ui(2,5,3);
    Triangles[7] = _vertex3ui(3,5,0);

    calcular_normales();
    calcular_colores();

}
