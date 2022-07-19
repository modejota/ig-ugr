#include "object3DR.h"
#include <cmath>

_object3DR::_object3DR(){}

void _object3DR::revolucion(unsigned int num_rotaciones, unsigned int grados) {

    if(num_rotaciones < 3) num_rotaciones = 3;  //Se necesitan por lo menos 3 perfiles para generar un objeto 3D
    float proporcion = (float)grados/360;
    if(proporcion > 1)  proporcion = 1;         //Se corrige por si se introdujese un valor correspondiente a mas de una rotacion

    // Guardar los puntos de los extremos, ya que en funcion de los cortes deberemos almacenarlos al final del vector
    _vertex3f ini = *(Vertices.begin());
    auto it_fin = Vertices.end();
    it_fin--;
    _vertex3f fin = *(it_fin);

    //Comprobamos si tenemos 0, 1 o 2 cortes con el eje.
    bool tapa_abajo = ini.x == 0;
    bool tapa_arriba = fin.x == 0;
    bool arriba_abajo = ini.y > fin.y;	//True quiere decir que damos el perfil de arriba a abajo (esfera), falso lo damos de abajo a arriba (cono, cilindro y creo que PLY)

    //En funcion de los cortes deberemos rotar mas o menos puntos del perfil
    unsigned int num_ext_rotar = 0;
    if (!tapa_abajo) num_ext_rotar++;
    if (!tapa_arriba) num_ext_rotar++;

    unsigned int puntos_medios = Vertices.size() - 2 + num_ext_rotar;
    unsigned int puntos_totales = puntos_medios*num_rotaciones + 2 - num_ext_rotar;

    // Traer los puntos intermedios al inicio en caso de que el primer punto corte al eje
    if(tapa_abajo) {
        for (unsigned int i = 0; i < puntos_medios; i++){
            Vertices[i] = Vertices[i+1];
        }
    }

    // Redimensionar el vector de vertices
    Vertices.resize(puntos_totales);

    double angulo;
    // El bucle externo realiza cada una de las rotaciones
    for (unsigned int i = 1; i < num_rotaciones; i++){
        // Realiza la rotacion para cada uno de los puntos del perfil
        for (unsigned int j = 0; j < puntos_medios; j++){
            if(proporcion == 1) {
                angulo = (2 * M_PI * i) / num_rotaciones;
            }
            else {
                angulo = (2 * M_PI * i * proporcion) / (num_rotaciones-1);
            }
            Vertices[i * puntos_medios + j] = RotarPunto(Vertices[j],'Y',angulo);
        }
    }

    // Añadimos de ser necesarios los puntos que cortan al eje al final
    if(tapa_abajo && tapa_arriba) {    
        Vertices[puntos_totales - 2] = ini;
        Vertices[puntos_totales - 1] = fin;
    }
    else if (tapa_abajo)   Vertices[puntos_totales - 1] = ini;
    else if (tapa_arriba)  Vertices[puntos_totales - 1] = fin;



    //GENERACION DE LOS TRIANGULOS DE LA FIGURA

    unsigned int num_vertex = Vertices.size();
    puntos_medios = (num_vertex - 2 + num_ext_rotar) / num_rotaciones; // Numero de puntos medios del perfil original

    // El numero de trinagulos se puede calcular mediante la siguiente expresion:
    unsigned int num_triangulos = puntos_medios * num_rotaciones * 2;

    Triangles.resize(num_triangulos);

    unsigned int h = 0;

    // Aniadimos los triangulos del bloque central, cuando lo haya
    for (unsigned int i = 0; i < (puntos_medios - 1); i++){
        for (unsigned int j = 0; j < num_rotaciones; j++){
            int A = i + j * puntos_medios;
            int B = (i + (j +1) * puntos_medios) % (puntos_medios * num_rotaciones);
            int C = i + 1 + j * puntos_medios;
            int D = (i + 1 + (j + 1) * puntos_medios) % (puntos_medios * num_rotaciones);

            if(arriba_abajo) {
                Triangles[h] = _vertex3ui (A, C, B);
                Triangles[h+1] = _vertex3ui (B, C, D);
            }
            else {
                Triangles[h] = _vertex3ui (A, B, C);
                Triangles[h + 1] = _vertex3ui (D, C, B);
            }

            h += 2;
        }
    }

    // Aniadimos los triangulos de la parte inferior
    if(tapa_abajo) {
        for (unsigned int i = 0; i < num_rotaciones; i++){
            unsigned int A = num_vertex - 2;
            unsigned int B = i * puntos_medios;
            unsigned int C = ((i + 1) * puntos_medios) % (puntos_medios * num_rotaciones);

            if(arriba_abajo) {
                Triangles[h] = _vertex3ui (A, B, C);
            }
            else {
                Triangles[h] = _vertex3ui (C, B, A);
            }
            h++;
        }
    }

    if (tapa_arriba) {
        // Aniadimos los triangulos de la parte superior
        for (unsigned int i = 0; i < num_rotaciones; i++){
            unsigned int A = num_vertex - 1;
            unsigned int B = puntos_medios - 1 + i * puntos_medios;
            unsigned int C = (puntos_medios - 1 + (i + 1) * puntos_medios) % (puntos_medios * num_rotaciones);

            if(arriba_abajo) {
                Triangles[h] = _vertex3ui(C, B, A);
            }
            else {
                Triangles[h] = _vertex3ui (A, B, C);
            }
            h++;
        }
    }
}


_vertex3f _object3DR::RotarPunto(_vertex3f vertice, char eje, double angulo){

    _vertex3f rotado;
    switch (eje) {
        case 'X':
            rotado.x = vertice.x;
            rotado.y = cos(angulo) * vertice.y - sin(angulo) * vertice.z;
            rotado.z = sin(angulo) * vertice.y + cos(angulo) * vertice.y;
            return rotado;
        case 'Y':
            rotado.x =  cos(angulo) * vertice.x + sin(angulo) * vertice.z;
            rotado.y = vertice.y;
            rotado.z = -sin(angulo) * vertice.x + cos(angulo) * vertice.z;
            return rotado;
        case 'Z':
            rotado.x = cos(angulo) * vertice.x - sin(angulo) * vertice.y;
            rotado.y = sin(angulo) * vertice.x + cos(angulo) * vertice.y;
            rotado.z = vertice.z;
            return rotado;
        default:
            return {0.0,0.0,0.0};
    }

}

