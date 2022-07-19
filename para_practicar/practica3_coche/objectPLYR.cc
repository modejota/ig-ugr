#include "objectPLYR.h"
#include "file_ply_stl.h"

using namespace std;


_objectPLYR::_objectPLYR(){}


void _objectPLYR::cargarPLYR(const string &ruta){
    _file_ply Lectura;
    vector<float> temp_vert;
    vector<unsigned int> temp_triang;

    if (Lectura.open(ruta) == 1)
        Lectura.read(temp_vert,temp_triang);

    temp_triang.clear();
    Lectura.close();

    Vertices.resize(temp_vert.size()/3);

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

}
