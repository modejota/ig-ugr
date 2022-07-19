/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QImageReader>
#include <iostream>
#include "vertex.h"
#include "colors.h"
#include "axis.h"

#include "tetrahedron.h"
#include "cube.h"
#include "objectPLY.h"
#include "objectPLYR.h"
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "mazinger_z.h"
#include "board.h"
#include "octahedron.h"
#include "otros_objetos.h"


namespace _gl_widget_ne {

  const float X_MIN=-.1;
  const float X_MAX=.1;
//  const float Y_MIN=-.1;
//  const float Y_MAX=.1;
  const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
  const float BACK_PLANE_PERSPECTIVE=1000;
  const float FRONT_PLANE_PARALLEL=-10000;
  const float BACK_PLANE_PARALLEL=10000;
  const float DEFAULT_DISTANCE=2;
  const float ANGLE_STEP=1;
  const float MOUSE_STEP=2.5;   //El movimiento de raton es más rapido que el por tecla
  const float FACTOR_CAMARA = 1.25; //Factor del zoom tanto por teclado como por rueda de raton

  typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
  typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE,OBJECT_PLY,OBJECT_PLYR,
               OBJECT_CONE,OBJECT_CYLINDER,OBJECT_SPHERE,OBJECT_HIERARCHICAL,OBJECT_BOARD,
               OBJECT_COPA,OBJECT_COPAR,OBJECT_HORMIGONERA,OBJECT_OCTOHEDRON,OBJECT_PEON} _object;
  typedef enum {SOLID,SOLID_CHESS,ILLUMINATION_FLAT_SHADING,ILLUMINATION_SMOOTH_SHADING,
                TEXTURE, TEXTURE_ILLUMINATION_FLAT_SHADING,TEXTURE_ILLUMINATION_SMOOTH_SHADING,
                TRIANGLES_COLOR,VERTICES_COLOR} _mode_rendering;
  typedef enum {PERSPECTIVE_PROJECTION,PARALLEL_PROJECTION} _camera_type;

}

class _window;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _gl_widget : public QOpenGLWidget
{
Q_OBJECT
public:
  _gl_widget(_window *Window1);

  void clear_window();
  void change_projection();
  void change_observer();

  void draw_axis();
  void draw_objects();


  float getVelocidadBrazos()                { return Mazinger.getVelocidadBrazos();  }
  float getVelocidadGiroAntebrazos()        { return Mazinger.getVelocidadGiroAntebrazos();   }
  float getVelocidadEscaladoAntebrazos()    { return Mazinger.getVelocidadEscaladoAntebrazos();  }
  float getVelocidadPiernas()   { return Mazinger.getVelocidadPiernas(); }
  float getVelocidadCuerpo()    { return Mazinger.getVelocidadCuerpo();  }
  float getVelocidadCabeza()    { return Mazinger.getVelocidadCabeza();  }

//  void comprobar_ultimo_checkbox_animacion();

  void selector_luces();
  void selector_material();

  void pick();

protected:
  void resizeGL(int Width1, int Height1) Q_DECL_OVERRIDE;
  void paintGL() Q_DECL_OVERRIDE;
  void initializeGL() Q_DECL_OVERRIDE;
  void keyPressEvent(QKeyEvent *Keyevent) Q_DECL_OVERRIDE;
  void wheelEvent(QWheelEvent *Event) Q_DECL_OVERRIDE;
  void mouseMoveEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  void mousePressEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;
  void mouseReleaseEvent(QMouseEvent *Event) Q_DECL_OVERRIDE;

public slots:
  void checkbox_points_slot(int State);
  void checkbox_lines_slot(int State);
  void checkbox_fill_slot(int State);

  void checkbox_animation_slot(int State);
  void checkbox_animation_arm_slot(int State);
  void checkbox_animation_leg_slot(int State);
  void checkbox_animation_body_slot(int State);
  void checkbox_animation_scale_antebrazo_slot(int State);
  void checkbox_animation_rotate_antebrazo_slot(int State);
  void checkbox_animation_scale_cabeza_slot(int State);

  void boton_brazo_derecho_arriba_slot(bool);
  void boton_brazo_derecho_abajo_slot(bool);
  void boton_antebrazo_derecho_arriba_slot(bool);
  void boton_antebrazo_derecho_abajo_slot(bool);
  void boton_antebrazo_derecho_fuera_slot(bool);
  void boton_antebrazo_derecho_dentro_slot(bool);

  void boton_brazo_izquierdo_arriba_slot(bool);
  void boton_brazo_izquierdo_abajo_slot(bool);
  void boton_antebrazo_izquierdo_arriba_slot(bool);
  void boton_antebrazo_izquierdo_abajo_slot(bool);
  void boton_antebrazo_izquierdo_fuera_slot(bool);
  void boton_antebrazo_izquierdo_dentro_slot(bool);

  void boton_brazos_arriba_slot(bool);
  void boton_brazos_abajo_slot(bool);
  void boton_antebrazos_arriba_slot(bool);
  void boton_antebrazos_abajo_slot(bool);
  void boton_antebrazos_fuera_slot(bool);
  void boton_antebrazos_dentro_slot(bool);

  void boton_pierna_derecha_arriba_slot(bool);
  void boton_pierna_derecha_abajo_slot(bool);
  void boton_pierna_izquierda_arriba_slot(bool);
  void boton_pierna_izquierda_abajo_slot(bool);
  void boton_piernas_forward_slot(bool);
  void boton_piernas_backward_slot(bool);
  void boton_pecho_derecha_slot(bool);
  void boton_pecho_izquierda_slot(bool);
  void boton_cabeza_fuera_slot(bool);
  void boton_cabeza_dentro_slot(bool);

  void boton_brazos_velocidadRA_slot(bool);
  void boton_brazos_velocidadRD_slot(bool);
  void boton_antebrazos_velocidadRA_slot(bool);
  void boton_antebrazos_velocidadRD_slot(bool);
  void boton_antebrazos_velocidadEA_slot(bool);
  void boton_antebrazos_velocidadED_slot(bool);
  void boton_cuerpo_velocidadA_slot(bool);
  void boton_cuerpo_velocidadD_slot(bool);
  void boton_pierna_velocidadA_slot(bool);
  void boton_pierna_velocidadD_slot(bool);
  void boton_cabezaA_slot(bool);
  void boton_cabezaD_slot(bool);

  void checkbox_luz0_slot(int State);
  void checkbox_luz1_slot(int State);
  void boton_luz1_derecha_slot(bool);
  void boton_luz1_izquierda_slot(bool);

  void combobox_object_slot(int State);
  void combobox_relleno_slot(int State);
  void combobox_cameras_slot(int State);

private slots:
  void tick();


private:
  _window *Window;
  _axis Axis;

  //Objetos
  _tetrahedron Tetrahedron;     // -- P1
  _cube Cube;
  _objectPLY PLY;               // -- P2
  _objectPLYR PLYR;
  _cone Cone;
  _cylinder Cylinder;
  _sphere Sphere;
  _mazinger_z Mazinger;         // -- P3
  _board Tablero;               // -- P4
  _octahedron Octohedron;       // -- Extras
  _copa Copa;                       // Por revolucion, solo 1 corte con tapa abajo
  _copa_reves CopaR;                // Por revolucion, solo 1 corte con tapa arriba
  _hormigonera Hormigonera;         // Por revolucion, con 0 cortes
  _peon Peon;                       // Por revolucion, con 2 cortes

  //Datos enum para selecciones
  _gl_widget_ne::_object Object;
  _gl_widget_ne::_mode_rendering Render_mode;
  _gl_widget_ne::_camera_type Camera_type;

  //Modos de visualizacion basicos (fill es un interuptor para solidos)
  bool Draw_point;
  bool Draw_line;
  bool Draw_fill;

  //Control animacion (P3)
  bool Animate;
  bool Animate_arm, Animate_leg, Animate_body;
  bool Animate_giro_antebrazo, Animate_escalado_antebrazo;
  bool Animate_escalado_cabeza;
  //Timer para la animacion (P3)
  QTimer Timer;

  //Control de luces y materiales (P4)
  float angulo_second_light;
  static const int FACTOR_GIRO_LUZ1 = 10;
  bool First_light, Second_light;
  unsigned int Material, numero_materiales;

  //Control de las camaras (P5)
  float Observer_angle_x;
  float Observer_angle_y;
  float Observer_distance;
  int Window_width, Window_height;
  float extremo_ventana;
  float factor_escala;

  //Control de la interaccion (P5)
  int ultima_x, ultima_y;
  int Selection_position_x, Selection_position_y;

};

#endif
