/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"
#include <random>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
  public:
  vector<_vertex3ui> Triangles;
  vector<_vertex3f> NormalesTriangles;
  vector<_vertex3f> NormalesVertices;
  vector<_vertex3f> Triangles_color;
  vector<_vertex3f> Vertices_color;
  vector<_vertex2f> CoordTex;
  int Triangulo_pick = -1;

  void draw_line();
  void draw_fill();
  void draw_chess();
  void draw_triangles_color();
  void draw_vertices_color();
  void draw_illumination_flat_shading();
  void draw_illumination_smooth_shading();
  void draw_texture();
  void draw_texture_illumination_flat_shading();
  void draw_texture_illumination_smooth_shading();

  void calcular_normales();
  void calcular_colores();
  void actualizar_trianglo_pick(int value){ Triangulo_pick=value;   }
  void draw_for_selection();
};

#endif // OBJECT3D_H
