#include "board.h"
#include "algorithm"


_board::_board(float Size, unsigned int casillas){
    int filas, columnas;
    filas = columnas = sqrt(casillas) + 1;

    float ext_neg= -Size/2;
    float ancho_casilla = Size/(filas-1);

    float ancho_casilla_text = 1.0/(filas-1);

    Vertices.resize(filas*columnas);
    Triangles.resize(2*casillas);
    CoordTex.resize(filas*columnas);

    // Calcular los vertices del tablero y de la textura
    float k = 0;
    for (int j = 0; j < columnas; j++){
        for (int i = 0; i < filas; i++){
            Vertices[k] = _vertex3f (ext_neg + ancho_casilla*i, ext_neg + ancho_casilla*j, 0);

            CoordTex[k] = _vertex2f (ancho_casilla_text*i, ancho_casilla_text*j);

            k++;
        }
    }

    // Calcular los triangulos. Independiente de textura
    k=0;
    for (int i = 0; i < sqrt(casillas); i++){ // i para columnas
        for (int j = 0; j < sqrt(casillas); j++){ // j para filas
            Triangles[k] = _vertex3ui (i*filas + j, i*filas + (j+1), (i+1)*filas + j);

            Triangles[k+1] = _vertex3ui ((i+1)*filas + j, i*filas + (j+1), (i+1)*filas + (j+1));

            k+=2;
        }
    }

    calcular_normales();
    calcular_colores();
}



