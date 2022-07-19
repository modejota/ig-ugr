#include "objectPLY.h"
#include "file_ply_stl.h"

using namespace std;


_objectPLY::_objectPLY(){}


void _objectPLY::cargarPLY(const string &ruta){
    _file_ply Lectura;
    vector<float> temp_vert;
    vector<unsigned int> temp_triang;

    if (Lectura.open(ruta) == 1)
        Lectura.read(temp_vert,temp_triang);

    Lectura.close();

    Vertices.resize(temp_vert.size()/3);
    Triangles.resize(temp_triang.size()/3);

    unsigned int j = 0;
    for (unsigned int i=0; i < temp_vert.size(); i+=3)
    {
        _vertex3f vertice;
        vertice.x = temp_vert[i];
        vertice.y = temp_vert[i+1];
        vertice.z = temp_vert[i+2];

        Vertices[j] = vertice;
        j++;
    }

    j = 0;
    for (unsigned int i=0; i < temp_triang.size(); i+=3)
    {
        _vertex3ui triangulo;
        triangulo._0 = temp_triang[i];
        triangulo._1 = temp_triang[i+1];
        triangulo._2 = temp_triang[i+2];

        Triangles[j] = triangulo;
        j++;

    }

}
