/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1), Cone(40), Cylinder(40), Sphere(100,100),
                                         Copa(40), CopaR(40), Hormigonera(40), Peon(40)
{
  setMinimumSize(300, 300);
  setFocusPolicy(Qt::StrongFocus);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
  switch(Keyevent->key()){
  case Qt::Key_1:
      Object=OBJECT_TETRAHEDRON;
      Window->change_combobox_objects_state(0);
      break;
  case Qt::Key_2:
      Object=OBJECT_CUBE;
      Window->change_combobox_objects_state(1);
      break;
  case Qt::Key_3:
      Object=OBJECT_CONE;
      Window->change_combobox_objects_state(2);
      break;
  case Qt::Key_4:
      Object=OBJECT_CYLINDER;
      Window->change_combobox_objects_state(3);
      break;
  case Qt::Key_5:
      Object=OBJECT_SPHERE;
      Window->change_combobox_objects_state(4);
      break;
  case Qt::Key_6:
      Object=OBJECT_PLY;
      Window->change_combobox_objects_state(5);
      //Para mostrar al usuario un menu con el que seleccionar archivo .ply
  {
      QString SeleccionarRuta = QFileDialog::getOpenFileName(
                  this,tr("Seleccione archivo .ply"), QDir::currentPath(), tr("Archivo PLY (*.ply)"));

      string ruta = SeleccionarRuta.toUtf8().constData();

      PLY.cargarPLY(ruta);
  }
      break;
  case Qt::Key_7:
      Object=OBJECT_HIERARCHICAL;
      Window->change_combobox_objects_state(7);
      break;
  case Qt::Key_8:
      Object=OBJECT_BOARD;
      Window->change_combobox_objects_state(8);
      break;

  case Qt::Key_A:
      Animate=!Animate;
      //Si el objeto mostrado es el jerarquico se activa la animacion de este
      if(Object == OBJECT_HIERARCHICAL) {
          Animate_arm = Animate_leg = Animate_body = Animate_escalado_antebrazo = Animate_giro_antebrazo = Animate_escalado_cabeza = Animate;
          Window->change_animation_arm_state(Animate_arm);
          Window->change_animation_leg_state(Animate_leg);
          Window->change_animation_body_state(Animate_body);
          Window->change_animation_rotate_antebrazo_state(Animate_giro_antebrazo);
          Window->change_animation_scale_antebrazo_state(Animate_escalado_antebrazo);
          Window->change_animation_scale_cabeza_state(Animate_escalado_cabeza);
     }
      Window->change_animation_state(Animate);

      if(Animate==true) Timer.start();
      else  Timer.stop();
      break;
  case Qt::Key_P:
      Draw_point=!Draw_point;
      Window->change_points_state(Draw_point);
      break;
  case Qt::Key_L:
      Draw_line=!Draw_line;
      Window->change_lines_state(Draw_line);
      break;
  case Qt::Key_F:
      Draw_fill=!Draw_fill;
      Window->change_fill_state(Draw_fill);
      break;

  case Qt::Key_F1:
      Render_mode = SOLID;
      Window->change_combobox_relleno_state(0);
      break;
  case Qt::Key_F2:
      Render_mode = SOLID_CHESS;
      Window->change_combobox_relleno_state(1);
      break;
  case Qt::Key_F3:
      Render_mode = ILLUMINATION_FLAT_SHADING;
      Window->change_combobox_relleno_state(2);
      break;
  case Qt::Key_F4:
      Render_mode = ILLUMINATION_SMOOTH_SHADING;
      Window->change_combobox_relleno_state(3);
      break;
  case Qt::Key_F5:
      Render_mode = TEXTURE;
      Window->change_combobox_relleno_state(4);
      break;
  case Qt::Key_F6:
      Render_mode = TEXTURE_ILLUMINATION_FLAT_SHADING;
      Window->change_combobox_relleno_state(5);
      break;
  case Qt::Key_F7:
      Render_mode = TEXTURE_ILLUMINATION_SMOOTH_SHADING;
      Window->change_combobox_relleno_state(6);
      break;
  case Qt::Key_F8:
      Render_mode = TRIANGLES_COLOR;
      Window->change_combobox_relleno_state(7);
      break;
  case Qt::Key_F9:
      Render_mode = VERTICES_COLOR;
      Window->change_combobox_relleno_state(8);
      break;

   case Qt::Key_J:
      First_light=!First_light;
      Window->change_light0_state(First_light);
      break;
   case Qt::Key_K:
      Second_light=!Second_light;
      Window->change_light1_state(Second_light);
      break;
   case Qt::Key_M:
      Material = (Material+1)%numero_materiales;
      break;
   case Qt::Key_G:
      if(Second_light)
       angulo_second_light = (angulo_second_light < 360 ) ? angulo_second_light += FACTOR_GIRO_LUZ1 : angulo_second_light = 0;
      break;
   case Qt::Key_H:
      if(Second_light)
       angulo_second_light = (angulo_second_light > 0) ? angulo_second_light -= FACTOR_GIRO_LUZ1 : angulo_second_light = 360;
      break;

  case Qt::Key_C:
      Camera_type = PERSPECTIVE_PROJECTION;
      Window->change_combobox_cameras_state(0);
      break;
  case Qt::Key_V:
      Camera_type = PARALLEL_PROJECTION;
      Window->change_combobox_cameras_state(1);
      break;

//  Como tengo más opciones que controlar que teclas "reservadas" en la P3 se me dijo en tutoria que todo se hiciese por interfaz
  /*
  case Qt::Key_Q:break;     case Qt::Key_W:break;
  case Qt::Key_S:break;     case Qt::Key_D:break;
  case Qt::Key_Z:break;     case Qt::Key_X:break;

  case Qt::Key_E:break;     case Qt::Key_R:break;
  case Qt::Key_T:break;     case Qt::Key_Y:break;
  case Qt::Key_U:break;     case Qt::Key_I:break;
  */

  case Qt::Key_Left:Observer_angle_y-=ANGLE_STEP;break;
  case Qt::Key_Right:Observer_angle_y+=ANGLE_STEP;break;
  case Qt::Key_Up:Observer_angle_x-=ANGLE_STEP;break;
  case Qt::Key_Down:Observer_angle_x+=ANGLE_STEP;break;
  case Qt::Key_PageUp:
      if(Camera_type == PERSPECTIVE_PROJECTION)         Observer_distance*=FACTOR_CAMARA;
      else if (Camera_type == PARALLEL_PROJECTION)      factor_escala*=FACTOR_CAMARA;
      break;
  case Qt::Key_PageDown:
      if(Camera_type == PERSPECTIVE_PROJECTION)         Observer_distance/=FACTOR_CAMARA;
      else if (Camera_type == PARALLEL_PROJECTION)      factor_escala/=FACTOR_CAMARA;
      break;
  }

  update();
}

/*****************************************************************************//**
 * Evento mover raton (mover camara)
 *
 *
 *
 *****************************************************************************/

//https://doc.qt.io/qt-5/qmouseevent.html
void _gl_widget::mouseMoveEvent(QMouseEvent * Event){

    int nueva_x = Event->x();   //Cogemos posicion del puntero
    int nueva_y = Event->y();

    if(Event->buttons() & Qt::LeftButton){
        //Mover el raton hacia los lados (X) provoca rotacion respecto de eje Y
        if(ultima_x < nueva_x)      Observer_angle_y+=MOUSE_STEP;
        else if(ultima_x > nueva_x) Observer_angle_y-=MOUSE_STEP;

        //Mover raton hacia arriba o abajo (Y) provoca rotacion respecto de eje X
        if(ultima_y < nueva_y)      Observer_angle_x+=MOUSE_STEP;
        else if(ultima_y > nueva_y) Observer_angle_x-=MOUSE_STEP;

        //Actualizamos valores para que no haga cosas raras
        ultima_x = nueva_x;
        ultima_y = nueva_y;
    }
    update();
}

/*****************************************************************************//**
 * Evento rueda raton (hacer zoom)
 *
 *
 *
 *****************************************************************************/

//https://doc.qt.io/qt-5/qwheelevent.html y https://doc.qt.io/qt-5/qpoint.html
void _gl_widget::wheelEvent(QWheelEvent * Event){

    QPoint puntero = Event->angleDelta();
    int posicion_y = puntero.ry();
    //Hay otra funcion, pixelDelta(), que parece ofrecer mejor respuesta, pero depende
    //de resolución de la pantalla y tiene problemas con algunos drivers.

    if(!puntero.isNull()){
        if (Camera_type==PERSPECTIVE_PROJECTION) {
            if (posicion_y > 0)         Observer_distance /= FACTOR_CAMARA;
            else if (posicion_y < 0)    Observer_distance *= FACTOR_CAMARA;
        } else if (Camera_type==PARALLEL_PROJECTION) {
            if (posicion_y > 0)         factor_escala /= FACTOR_CAMARA;
            else if (posicion_y < 0)    factor_escala *= FACTOR_CAMARA;
        }
    }
    Event->accept();
    update();
}

/*****************************************************************************//**
 * Hacer click con el raton. (pulsar y soltar)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::mousePressEvent(QMouseEvent *Event){
    if(Event->buttons() & Qt::RightButton){
        Selection_position_x = Event->x();
        Selection_position_y = Window_height - Event->y();   //OpenGL asume y=0 abajo de la ventana, la mayoria de SOs asumen y=0 arriba de la ventana.
    }
}
void _gl_widget::mouseReleaseEvent(QMouseEvent *Event){
    if(Draw_fill && (Event->button() & Qt::RightButton)){   pick();     update();   }
}

/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
  // Front_plane>0  Back_plane>PlanoDelantero)

  float RA = float(Window_height)/float(Window_width);  //Relacion de aspecto, por si el lienzo no fuese cuadrado

  if(Camera_type == PERSPECTIVE_PROJECTION){
      glFrustum(-extremo_ventana,extremo_ventana,-extremo_ventana*RA,extremo_ventana*RA,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
  }
  else if (Camera_type == PARALLEL_PROJECTION){
      glOrtho(-extremo_ventana*factor_escala,extremo_ventana*factor_escala,-extremo_ventana*factor_escala*RA,extremo_ventana*factor_escala*RA,
              FRONT_PLANE_PARALLEL,BACK_PLANE_PARALLEL);
  }


}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
  Axis.draw_line();

  if (Draw_point){
    glPointSize(5);
    glColor3fv((GLfloat *) &BLACK);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_point();break;
    case OBJECT_CUBE:Cube.draw_point();break;
    case OBJECT_PLY:PLY.draw_point();break;
    case OBJECT_PLYR:PLYR.draw_point();break;
    case OBJECT_CONE:Cone.draw_point();break;
    case OBJECT_CYLINDER:Cylinder.draw_point();break;
    case OBJECT_SPHERE:Sphere.draw_point();break;
    case OBJECT_HIERARCHICAL:Mazinger.draw_point();break;
    case OBJECT_BOARD:Tablero.draw_point();break;
    case OBJECT_OCTOHEDRON:Octohedron.draw_point();break;
    case OBJECT_COPA:Copa.draw_point();break;
    case OBJECT_COPAR:CopaR.draw_point();break;
    case OBJECT_HORMIGONERA:Hormigonera.draw_point();break;
    case OBJECT_PEON:Peon.draw_point();break;
    default:break;
    }
  }

  if (Draw_line){
    glLineWidth(1.5);
    glColor3fv((GLfloat *) &MAGENTA);
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_line();break;
    case OBJECT_CUBE:Cube.draw_line();break;
    case OBJECT_PLY:PLY.draw_line();break;
    case OBJECT_PLYR:PLYR.draw_line();break;
    case OBJECT_CONE:Cone.draw_line();break;
    case OBJECT_CYLINDER:Cylinder.draw_line();break;
    case OBJECT_SPHERE:Sphere.draw_line();break;
    case OBJECT_HIERARCHICAL:Mazinger.draw_line();break;
    case OBJECT_BOARD:Tablero.draw_line();break;
    case OBJECT_OCTOHEDRON:Octohedron.draw_line();break;
    case OBJECT_COPA:Copa.draw_line();break;
    case OBJECT_COPAR:CopaR.draw_line();break;
    case OBJECT_HORMIGONERA:Hormigonera.draw_line();break;
    case OBJECT_PEON:Peon.draw_line();break;
    default:break;
    }
  }

  // -- P4 -- Draw_fill pasa a ser un interruptor de los modos de visualizado con relleno
  if (Draw_fill){
    glColor3fv((GLfloat *) &BLUE);
    switch(Render_mode) {
    case SOLID:
        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_fill();break;
        case OBJECT_CUBE:Cube.draw_fill();break;
        case OBJECT_PLY:PLY.draw_fill();break;
        case OBJECT_PLYR:PLYR.draw_fill();break;
        case OBJECT_CONE:Cone.draw_fill();break;
        case OBJECT_CYLINDER:Cylinder.draw_fill();break;
        case OBJECT_SPHERE:Sphere.draw_fill();break;
        case OBJECT_HIERARCHICAL:Mazinger.draw_fill();break;
        case OBJECT_BOARD:Tablero.draw_fill();break;
        case OBJECT_OCTOHEDRON:Octohedron.draw_fill();break;
        case OBJECT_COPA:Copa.draw_fill();break;
        case OBJECT_COPAR:CopaR.draw_fill();break;
        case OBJECT_HORMIGONERA:Hormigonera.draw_fill();break;
        case OBJECT_PEON:Peon.draw_fill();break;
        default:break;
        }   break;
    case SOLID_CHESS:
        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_chess();break;
        case OBJECT_CUBE:Cube.draw_chess();break;
        case OBJECT_PLY:PLY.draw_chess();break;
        case OBJECT_PLYR:PLYR.draw_chess();break;
        case OBJECT_CONE:Cone.draw_chess();break;
        case OBJECT_CYLINDER:Cylinder.draw_chess();break;
        case OBJECT_SPHERE:Sphere.draw_chess();break;
        case OBJECT_HIERARCHICAL:Mazinger.draw_chess();break;
        case OBJECT_BOARD:Tablero.draw_chess();break;
        case OBJECT_OCTOHEDRON:Octohedron.draw_chess();break;
        case OBJECT_COPA:Copa.draw_chess();break;
        case OBJECT_COPAR:CopaR.draw_chess();break;
        case OBJECT_HORMIGONERA:Hormigonera.draw_chess();break;
        case OBJECT_PEON:Peon.draw_chess();break;
        default:break;
        } break;
    case ILLUMINATION_FLAT_SHADING:
        selector_luces();
        selector_material();
        glEnable(GL_LIGHTING);
        switch (Object) {
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_illumination_flat_shading();break;
        case OBJECT_CUBE:Cube.draw_illumination_flat_shading();break;
        case OBJECT_PLY:PLY.draw_illumination_flat_shading();break;
        case OBJECT_PLYR:PLYR.draw_illumination_flat_shading();break;
        case OBJECT_CONE:Cone.draw_illumination_flat_shading();break;
        case OBJECT_CYLINDER:Cylinder.draw_illumination_flat_shading();break;
        case OBJECT_SPHERE:Sphere.draw_illumination_flat_shading();break;
        case OBJECT_HIERARCHICAL:Mazinger.draw_illumination_flat_shading();break;
        case OBJECT_BOARD:Tablero.draw_illumination_flat_shading();break;
        default:break;
        }
        glDisable(GL_LIGHTING);
        break;
    case ILLUMINATION_SMOOTH_SHADING:
        selector_luces();
        selector_material();
        glEnable(GL_LIGHTING);
        switch (Object) {
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_illumination_smooth_shading();break;
        case OBJECT_CUBE:Cube.draw_illumination_smooth_shading();break;
        case OBJECT_PLY:PLY.draw_illumination_smooth_shading();break;
        case OBJECT_PLYR:PLYR.draw_illumination_smooth_shading();break;
        case OBJECT_CONE:Cone.draw_illumination_smooth_shading();break;
        case OBJECT_CYLINDER:Cylinder.draw_illumination_smooth_shading();break;
        case OBJECT_SPHERE:Sphere.draw_illumination_smooth_shading();break;
        case OBJECT_HIERARCHICAL:Mazinger.draw_illumination_smooth_shading();break;
        case OBJECT_BOARD:Tablero.draw_illumination_smooth_shading();break;
        default:break;
        }
        glDisable(GL_LIGHTING);
        break;
    case TEXTURE:
        //Asegurar que se utilice color de textura y no el del relleno
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        switch (Object){
        case OBJECT_BOARD:Tablero.draw_texture();
        default:break;
        } break;

    case TEXTURE_ILLUMINATION_FLAT_SHADING:
        selector_luces();
        selector_material();
        glEnable(GL_LIGHTING);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //Adecuar a iluminacion
        switch (Object) {
        case OBJECT_BOARD:Tablero.draw_texture_illumination_flat_shading();
        default: break;
        }
        glDisable(GL_LIGHTING);
        break;
    case TEXTURE_ILLUMINATION_SMOOTH_SHADING:
        selector_luces();
        selector_material();
        glEnable(GL_LIGHTING);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); //Adecuar a iluminacion
        switch (Object) {
        case OBJECT_BOARD:Tablero.draw_texture_illumination_smooth_shading();
        default: break;
        }
        glDisable(GL_LIGHTING);
        break;
    case TRIANGLES_COLOR:
        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_triangles_color();break;
        case OBJECT_CUBE:Cube.draw_triangles_color();break;
        case OBJECT_PLY:PLY.draw_triangles_color();break;
        case OBJECT_PLYR:PLYR.draw_triangles_color();break;
        case OBJECT_CONE:Cone.draw_triangles_color();break;
        case OBJECT_CYLINDER:Cylinder.draw_triangles_color();break;
        case OBJECT_SPHERE:Sphere.draw_triangles_color();break;
        case OBJECT_HIERARCHICAL:Mazinger.draw_triangles_color();break;
        case OBJECT_BOARD:Tablero.draw_triangles_color();break;
        case OBJECT_OCTOHEDRON:Octohedron.draw_triangles_color();break;
        case OBJECT_COPA:Copa.draw_triangles_color();break;
        case OBJECT_COPAR:CopaR.draw_triangles_color();break;
        case OBJECT_HORMIGONERA:Hormigonera.draw_triangles_color();break;
        case OBJECT_PEON:Peon.draw_triangles_color();break;
        default:break;
        } break;
    case VERTICES_COLOR:
        switch (Object){
        case OBJECT_TETRAHEDRON:Tetrahedron.draw_vertices_color();break;
        case OBJECT_CUBE:Cube.draw_vertices_color();break;
        case OBJECT_PLY:PLY.draw_vertices_color();break;
        case OBJECT_PLYR:PLYR.draw_vertices_color();break;
        case OBJECT_CONE:Cone.draw_vertices_color();break;
        case OBJECT_CYLINDER:Cylinder.draw_vertices_color();break;
        case OBJECT_SPHERE:Sphere.draw_vertices_color();break;
        case OBJECT_HIERARCHICAL:Mazinger.draw_vertices_color();break;
        case OBJECT_BOARD:Tablero.draw_vertices_color();break;
        case OBJECT_OCTOHEDRON:Octohedron.draw_vertices_color();break;
        case OBJECT_COPA:Copa.draw_vertices_color();break;
        case OBJECT_COPAR:CopaR.draw_vertices_color();break;
        case OBJECT_HORMIGONERA:Hormigonera.draw_vertices_color();break;
        case OBJECT_PEON:Peon.draw_vertices_color();break;
        default:break;
        } break;
    }
  }
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
  clear_window();
  change_projection();
  change_observer();
  draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
  Window_width=Width1;
  Window_height=Height1;
  glViewport(0,0,Width1,Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
  const GLubyte* strm;

  strm = glGetString(GL_VENDOR);
  std::cerr << "Vendor: " << strm << "\n";
  strm = glGetString(GL_RENDERER);
  std::cerr << "Renderer: " << strm << "\n";
  strm = glGetString(GL_VERSION);
  std::cerr << "OpenGL Version: " << strm << "\n";

  if (strm[0] == '1'){
    std::cerr << "Only OpenGL 1.X supported!\n";
    exit(-1);
  }

  strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
  std::cerr << "GLSL Version: " << strm << "\n";

  //Inicializar contexto para que las llamadas de GLEW no provoquen violacion de segmento
  glewExperimental = GL_TRUE;
  int err = glewInit();
  if(GLEW_OK != err){
      std::cerr << "Error: " << glewGetErrorString(err) << endl;
      exit(-1);
  }

  int Max_texture_size=0;
  glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
  std::cerr << "Max texture size: " << Max_texture_size << "\n";

  glClearColor(1.0,1.0,1.0,1.0);
  glEnable(GL_DEPTH_TEST);;

  Observer_angle_x=0;
  Observer_angle_y=0;
  Observer_distance=DEFAULT_DISTANCE;

  Window_width=width();
  Window_height=height();

  Object = OBJECT_TETRAHEDRON;
  Render_mode = SOLID;
  Camera_type = PERSPECTIVE_PROJECTION;

  Draw_point=false;
  Draw_line=true;
  Draw_fill=false;

  angulo_second_light = 0;
  numero_materiales = 4;
  First_light = Second_light = false;
  Material = 0;
  Animate = Animate_arm = Animate_leg = Animate_body = false;
  Animate_giro_antebrazo = Animate_escalado_antebrazo = Animate_escalado_cabeza = false;

  extremo_ventana = X_MAX;
  factor_escala = 10;
  ultima_x = ultima_y = 0;

  Timer.setInterval(0);
  connect(&Timer,SIGNAL(timeout()),this, SLOT(tick()));

  // Code for reading an image
  QString File_name("./texturas/dia_8192.jpg");
  QImage Image;
  QImageReader Reader(File_name);
  Reader.setAutoTransform(true);
  Image = Reader.read();
  if (Image.isNull()) {
    QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                             tr("Cannot load %1.").arg(QDir::toNativeSeparators(File_name)));
    exit(-1);
  }
  Image=Image.mirrored();
  Image=Image.convertToFormat(QImage::Format_RGB888);

  // Code to control the application of the texture
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

  // Code to pass the image to OpenGL to form a texture 2D
  glTexImage2D(GL_TEXTURE_2D,0,3,Image.width(),Image.height(),0,GL_RGB,GL_UNSIGNED_BYTE,Image.bits());

}

void _gl_widget::tick() {
    //Si estamos visualizando el objeto jerarquico se animará, en función de los checkbox
    if(Object == OBJECT_HIERARCHICAL) {
        if(Animate_arm) Mazinger.auto_arms();
        if(Animate_leg) Mazinger.auto_legs();
        if(Animate_body) Mazinger.auto_body();
        if(Animate_giro_antebrazo) Mazinger.auto_giro_antebrazo();
        if(Animate_escalado_antebrazo) Mazinger.auto_escalado_antebrazo();
        if(Animate_escalado_cabeza) Mazinger.auto_head();
    }
    //Si tenemos activada la segunda luz la iremos rotando. (Menor velocidad que si le damos con los botones de la interfaz)
    if(Second_light)
        angulo_second_light = (angulo_second_light < 360 ) ? angulo_second_light += 0.5 : angulo_second_light = 0;

    update();
}

void _gl_widget::selector_luces(){
    if(First_light){
        GLfloat Posicion[] = {0,0,10,0};
        glEnable(GL_LIGHT0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            glLightfv(GL_LIGHT0,GL_POSITION, (GLfloat *) &Posicion);
        glPopMatrix();
    } else glDisable(GL_LIGHT0);

    if(Second_light){
        GLfloat ambiental[] = {1,0,1,1};
        GLfloat difusa[] = {0.5,0.5,0.5,1};
        GLfloat especular[] = {0.5,0.5,0.5,1};
        GLfloat posicion[] = {10,0,0,1};
        glLightfv(GL_LIGHT1,GL_AMBIENT, (GLfloat *) &ambiental);
        glLightfv(GL_LIGHT1,GL_SPECULAR,(GLfloat *) &especular);
        glLightfv(GL_LIGHT1,GL_DIFFUSE, (GLfloat *) &difusa);

        glEnable(GL_LIGHT1);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            glRotatef(angulo_second_light,0,1,0);
            glLightfv(GL_LIGHT1,GL_POSITION, (GLfloat *) &posicion);
        glPopMatrix();
    } else glDisable(GL_LIGHT1);
}

void _gl_widget::selector_material(){
    _vertex3f Ambiental, Difusa, Especular;
    float brillo = 0;

    switch(Material){
    case 0:
        Ambiental = _vertex3f(0.2,0.2,0.2);
        Difusa    = _vertex3f(0.8,0.8,0.8);
        Especular = _vertex3f(0.0,0.0,0.0);
        brillo = 0;
        break;
    case 1: //"Mantis religiosa"
        Ambiental = _vertex3f(0.214,0.13,0.05);
        Difusa    = _vertex3f(0.214,0.43,0.18);
        Especular = _vertex3f(0.400,0.28,0.17);
        brillo = 0.7;
        break;
    case 2: //"Obsidiana"
        Ambiental = _vertex3f(0.25,0.35,0.27);
        Difusa    = _vertex3f(0.18,0.17,0.22);
        Especular = _vertex3f(0.33,0.33,0.35);
        brillo = 0.3;
        break;
    case 3: //"Agua de mar"
        Ambiental = _vertex3f(0.00,0.05,0.05);
        Difusa    = _vertex3f(0.40,0.50,0.20);
        Especular = _vertex3f(0.04,0.30,0.70);
        brillo = 0.1;
        break;
    }
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,(GLfloat *)&Ambiental);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,(GLfloat *)&Difusa);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,(GLfloat *)&Especular);
    glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,brillo);
}

void _gl_widget::pick(){
    makeCurrent();

    // Frame Buffer Object to do the off-screen rendering
    GLuint FBO;
    glGenFramebuffers(1,&FBO);
    glBindFramebuffer(GL_FRAMEBUFFER,FBO);

    // Texture for drawing
    GLuint Color_texture;
    glGenTextures(1,&Color_texture);
    glBindTexture(GL_TEXTURE_2D,Color_texture);
    // RGBA8
    glTexStorage2D(GL_TEXTURE_2D,1,GL_RGBA8, Window_width,Window_height);
    // this implies that there is not mip mapping
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

    // Texure for computing the depth
    GLuint Depth_texture;
    glGenTextures(1,&Depth_texture);
    glBindTexture(GL_TEXTURE_2D,Depth_texture);
    // Float
    glTexStorage2D(GL_TEXTURE_2D,1,GL_DEPTH_COMPONENT24, Window_width,Window_height);

    // Attatchment of the textures to the FBO
    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,Color_texture,0);
    glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,Depth_texture,0);

    // OpenGL will draw to these buffers (only one in this case)
    static const GLenum Draw_buffers[]={GL_COLOR_ATTACHMENT0};
    glDrawBuffers(1,Draw_buffers);

    /*************************/

    // dibujar escena para seleccion
    clear_window();
    change_projection();
    change_observer();

    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.draw_for_selection();break;
    case OBJECT_CUBE:Cube.draw_for_selection();break;
    case OBJECT_PLY:PLY.draw_for_selection();break;
    case OBJECT_PLYR:PLYR.draw_for_selection();break;
    case OBJECT_CONE:Cone.draw_for_selection();break;
    case OBJECT_CYLINDER:Cylinder.draw_for_selection();break;
    case OBJECT_SPHERE:Sphere.draw_for_selection();break;
    case OBJECT_BOARD:Tablero.draw_for_selection();break;
    case OBJECT_OCTOHEDRON:Octohedron.draw_for_selection();break;
    case OBJECT_COPA:Copa.draw_for_selection();break;
    case OBJECT_COPAR:CopaR.draw_for_selection();break;
    case OBJECT_HORMIGONERA:Hormigonera.draw_for_selection();break;
    case OBJECT_PEON:Peon.draw_for_selection();break;
    default:break;
    }

    /*************************/

    // get the pixel

    int Color;
    glReadBuffer(GL_FRONT);
    glPixelStorei(GL_PACK_ALIGNMENT,1);
    glReadPixels(Selection_position_x,Selection_position_y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,&Color);

    // convertir de RGB a identificador
    uint R = (uint)((Color & 0x000000FF));
    uint G = (uint)((Color & 0x0000FF00) >> 8) ;
    uint B = (uint)((Color & 0x00FF0000) >> 16);

    // actualizar el identificador de la parte seleccionada en el objeto
    int Triangulo_pick = (R << 16) + (G << 8) + B;
    // Tenemos 2^24 = 16777216 colores, pero el último es el blanco, que debemos descartar (representa no seleccion/vacio)
    if(Triangulo_pick == 16777215) Triangulo_pick = -1;

    // Mandar actualizar el triangulo seleccionado para el objeto correspondiente
    switch (Object){
    case OBJECT_TETRAHEDRON:Tetrahedron.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_CUBE:Cube.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_PLY:PLY.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_PLYR:PLYR.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_CONE:Cone.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_CYLINDER:Cylinder.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_SPHERE:Sphere.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_BOARD:Tablero.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_OCTOHEDRON:Octohedron.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_COPA:Copa.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_COPAR:CopaR.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_HORMIGONERA:Hormigonera.actualizar_trianglo_pick(Triangulo_pick);break;
    case OBJECT_PEON:Peon.actualizar_trianglo_pick(Triangulo_pick);break;
    default:break;
    }
    /*************************/

    glDeleteTextures(1,&Color_texture);
    glDeleteTextures(1,&Depth_texture);
    glDeleteFramebuffers(1,&FBO);
    // the normal framebuffer takes the control of drawing
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER,defaultFramebufferObject());
}



/* Utilizado hasta la P3. Antes de añadir la animacion de la luz morada tenia sentido que si quitaba todas las animaciones
   de las partes del modelo por separado se desactivase de forma general tambien
void _gl_widget::comprobar_ultimo_checkbox_animacion(){
    if(!Animate_arm && !Animate_body && !Animate_escalado_antebrazo && !Animate_giro_antebrazo && !Animate_leg){
           Window->change_animation_state(false);
           Animate = false;
           Timer.stop();
    }
}
*/

/*****************************************************************************//**
 * FUNCIONES DE LOS SLOTS.
 *
 *
 *
 *****************************************************************************/

void _gl_widget::checkbox_points_slot(int State) {
    if(State == Qt::Checked)        Draw_point = true;
    else                            Draw_point = false;
    update();
}
void _gl_widget::checkbox_lines_slot(int State) {
    if(State == Qt::Checked)        Draw_line = true;
    else                            Draw_line = false;
    update();
}
void _gl_widget::checkbox_fill_slot(int State) {
    if(State == Qt::Checked)        Draw_fill=true;
    else                            Draw_fill = false;
    update();
}

void _gl_widget::checkbox_animation_arm_slot(int State){
    if(State == Qt::Checked)    Animate_arm = true;
    else                        Animate_arm = false;
//    comprobar_ultimo_checkbox_animacion();
    update();
}
void _gl_widget::checkbox_animation_leg_slot(int State){
    if(State == Qt::Checked)    Animate_leg = true;
    else                        Animate_leg = false;
//    comprobar_ultimo_checkbox_animacion();
    update();
}
void _gl_widget::checkbox_animation_body_slot(int State){
    if(State == Qt::Checked)    Animate_body = true;
    else                        Animate_body = false;
//    comprobar_ultimo_checkbox_animacion();
    update();
}
void _gl_widget::checkbox_animation_scale_antebrazo_slot(int State){
    if(State == Qt::Checked)    Animate_escalado_antebrazo = true;
    else                        Animate_escalado_antebrazo = false;
//    comprobar_ultimo_checkbox_animacion();
    update();
}
void _gl_widget::checkbox_animation_rotate_antebrazo_slot(int State){
    if(State == Qt::Checked)    Animate_giro_antebrazo = true;
    else                        Animate_giro_antebrazo = false;
//    comprobar_ultimo_checkbox_animacion();
    update();
}
void _gl_widget::checkbox_animation_scale_cabeza_slot(int State){
    if(State == Qt::Checked)    Animate_escalado_cabeza = true;
    else                        Animate_escalado_cabeza = false;
//    comprobar_ultimo_checkbox_animacion();
    update();
}

void _gl_widget::checkbox_animation_slot(int State){
    //Si estamos viendo el jerarquico la animacion activa todos sus movimientos y sus checkboxs
    if(Object == OBJECT_HIERARCHICAL){
        if(State==Qt::Checked){
            Animate_arm = Animate_body = Animate_leg = true;
            Animate = Animate_escalado_antebrazo = Animate_giro_antebrazo = Animate_escalado_cabeza = true;
            Timer.start();
         } else {
            Animate_arm = Animate_body = Animate_leg = false;
            Animate = Animate_escalado_antebrazo = Animate_giro_antebrazo = Animate_escalado_cabeza = false;
            Timer.stop();
        }
        Window->change_animation_arm_state(Animate_arm);
        Window->change_animation_leg_state(Animate_leg);
        Window->change_animation_body_state(Animate_body);
        Window->change_animation_rotate_antebrazo_state(Animate_giro_antebrazo);
        Window->change_animation_scale_antebrazo_state(Animate_escalado_antebrazo);
        Window->change_animation_scale_cabeza_state(Animate_escalado_cabeza);
    }
    //Si estamos con cualquier otro objeto solo activa la animacion de la luz magenta y un unico checkbox
    else{
        if(State==Qt::Checked){
            Animate = true;
            Timer.start();
        } else {
            Animate = false;
            Timer.stop();
        }
    }
}
void _gl_widget::combobox_object_slot(int State) {
    switch(State+1) {
        case 1: Object=OBJECT_TETRAHEDRON;break;
        case 2: Object=OBJECT_CUBE;break;
        case 3: Object=OBJECT_CONE;break;
        case 4: Object=OBJECT_CYLINDER;break;
        case 5: Object=OBJECT_SPHERE;break;
        case 6: Object=OBJECT_PLY;
        {
            QString SeleccionarRuta = QFileDialog::getOpenFileName(
                        this,tr("Seleccione archivo .ply"), QDir::currentPath(), tr("Archivo PLY (*.ply)"));

            string ruta = SeleccionarRuta.toUtf8().constData();

            PLY.cargarPLY(ruta);
        }
        break;
        case 7:Object=OBJECT_PLYR;
        {
            QString SeleccionarRuta = QFileDialog::getOpenFileName(
                        this,tr("Seleccione archivo .ply (Profile)"), QDir::currentPath(), tr("Archivo PLY (*.ply)"));

            string ruta = SeleccionarRuta.toUtf8().constData();

            PLYR.cargarPLYR(ruta,20);
        }
            break;
    case 8:Object=OBJECT_HIERARCHICAL;break;
    case 9:Object=OBJECT_BOARD;break;
    case 10:Object=OBJECT_OCTOHEDRON;break;
    case 11:Object=OBJECT_COPA;break;
    case 12:Object=OBJECT_COPAR;break;
    case 13:Object=OBJECT_HORMIGONERA;break;
    case 14:Object=OBJECT_PEON;break;
    }
    update();
}
void _gl_widget::combobox_relleno_slot(int State){
    switch(State+1){
    case 1: Render_mode = SOLID;break;
    case 2: Render_mode = SOLID_CHESS;break;
    case 3: Render_mode = ILLUMINATION_FLAT_SHADING;break;
    case 4: Render_mode = ILLUMINATION_SMOOTH_SHADING;break;
    case 5: Render_mode = TEXTURE;break;
    case 6: Render_mode = TEXTURE_ILLUMINATION_FLAT_SHADING;break;
    case 7: Render_mode = TEXTURE_ILLUMINATION_SMOOTH_SHADING;break;
    case 8: Render_mode = TRIANGLES_COLOR;break;
    case 9: Render_mode = VERTICES_COLOR;break;
    }
    update();
}
void _gl_widget::combobox_cameras_slot(int State){
    switch(State+1){
    case 1: Camera_type = PERSPECTIVE_PROJECTION;break;
    case 2: Camera_type = PARALLEL_PROJECTION;break;
    }
    update();
}

void _gl_widget::boton_brazo_derecho_arriba_slot(bool)       {   Mazinger.brazo_derecho_up();  update();     }
void _gl_widget::boton_brazo_derecho_abajo_slot(bool)        {   Mazinger.brazo_derecho_down();  update();   }
void _gl_widget::boton_antebrazo_derecho_arriba_slot(bool)          {   Mazinger.antebrazo_derecho_up(); update();  }
void _gl_widget::boton_antebrazo_derecho_abajo_slot(bool)           {   Mazinger.antebrazo_derecho_down(); update();}
void _gl_widget::boton_antebrazo_derecho_fuera_slot(bool)           {   Mazinger.antebrazo_derecho_out(); update(); }
void _gl_widget::boton_antebrazo_derecho_dentro_slot(bool)          {   Mazinger.antebrazo_derecho_in();  update(); }

void _gl_widget::boton_brazo_izquierdo_arriba_slot(bool)       {   Mazinger.brazo_izquierdo_up();  update();     }
void _gl_widget::boton_brazo_izquierdo_abajo_slot(bool)        {   Mazinger.brazo_izquierdo_down();  update();   }
void _gl_widget::boton_antebrazo_izquierdo_arriba_slot(bool)          {   Mazinger.antebrazo_izquierdo_up(); update();  }
void _gl_widget::boton_antebrazo_izquierdo_abajo_slot(bool)           {   Mazinger.antebrazo_izquierdo_down(); update();}
void _gl_widget::boton_antebrazo_izquierdo_fuera_slot(bool)           {   Mazinger.antebrazo_izquierdo_out(); update(); }
void _gl_widget::boton_antebrazo_izquierdo_dentro_slot(bool)          {   Mazinger.antebrazo_izquierdo_in();  update(); }

void _gl_widget::boton_brazos_arriba_slot(bool)         {   Mazinger.arms_up();     update();   }
void _gl_widget::boton_brazos_abajo_slot(bool)          {   Mazinger.arms_down();   update();   }
void _gl_widget::boton_antebrazos_arriba_slot(bool)     {   Mazinger.antebrazos_up();   update();   }
void _gl_widget::boton_antebrazos_abajo_slot(bool)      {   Mazinger.antebrazos_down(); update();   }
void _gl_widget::boton_antebrazos_fuera_slot(bool)      {   Mazinger.antebrazos_out();  update();   }
void _gl_widget::boton_antebrazos_dentro_slot(bool)     {   Mazinger.antebrazos_in();   update();   }

void _gl_widget::boton_pierna_derecha_arriba_slot(bool) {   Mazinger.right_leg_up();    update();   }
void _gl_widget::boton_pierna_derecha_abajo_slot(bool)  {   Mazinger.right_leg_down();  update();   }
void _gl_widget::boton_pierna_izquierda_arriba_slot(bool)   {   Mazinger.left_leg_up(); update();   }
void _gl_widget::boton_pierna_izquierda_abajo_slot(bool)    {   Mazinger.left_leg_down();   update();   }
void _gl_widget::boton_piernas_forward_slot(bool)           {   Mazinger.legs_forward();    update();   }
void _gl_widget::boton_piernas_backward_slot(bool)          {   Mazinger.legs_backwards();  update();   }
void _gl_widget::boton_pecho_derecha_slot(bool)     {   Mazinger.body_right();  update();   }
void _gl_widget::boton_pecho_izquierda_slot(bool)   {   Mazinger.body_left();   update();   }
void _gl_widget::boton_cabeza_fuera_slot(bool)      { Mazinger.cabeza_out(); update(); }
void _gl_widget::boton_cabeza_dentro_slot(bool)     { Mazinger.cabeza_in(); update(); }

void _gl_widget::boton_brazos_velocidadRA_slot(bool){
    Mazinger.increase_speed_brazo_movement();
    Window->cambiar_velocidad_rotacion_brazo(getVelocidadBrazos());
}
void _gl_widget::boton_brazos_velocidadRD_slot(bool){
    Mazinger.decrease_speed_brazo_movement();
    Window->cambiar_velocidad_rotacion_brazo(getVelocidadBrazos());
}
void _gl_widget::boton_antebrazos_velocidadRA_slot(bool){
    Mazinger.increase_speed_antebrazo_movement();
    Window->cambiar_velocidad_rotacion_antebrazo(getVelocidadGiroAntebrazos());
}
void _gl_widget::boton_antebrazos_velocidadRD_slot(bool){
    Mazinger.decrease_speed_antebrazo_movement();
    Window->cambiar_velocidad_rotacion_antebrazo(getVelocidadGiroAntebrazos());
}
void _gl_widget::boton_antebrazos_velocidadEA_slot(bool){
    Mazinger.increase_speed_antebrazo_scale();
    Window->cambiar_velocidad_escalado_antebrazo(getVelocidadEscaladoAntebrazos());
}
void _gl_widget::boton_antebrazos_velocidadED_slot(bool){
    Mazinger.decrease_speed_antebrazo_scale();
    Window->cambiar_velocidad_escalado_antebrazo(getVelocidadEscaladoAntebrazos());
}
void _gl_widget::boton_cuerpo_velocidadA_slot(bool){
    Mazinger.increase_speed_cuerpo_movement();
    Window->cambiar_velocidad_rotacion_cuerpo(getVelocidadCuerpo());
}
void _gl_widget::boton_cuerpo_velocidadD_slot(bool){
    Mazinger.decrease_speed_cuerpo_movement();
    Window->cambiar_velocidad_rotacion_cuerpo(getVelocidadCuerpo());
}
void _gl_widget::boton_pierna_velocidadA_slot(bool){
    Mazinger.increase_speed_piernas_movement();
    Window->cambiar_velocidad_rotacion_piernas(getVelocidadPiernas());
}
void _gl_widget::boton_pierna_velocidadD_slot(bool){
    Mazinger.decrease_speed_piernas_movement();
    Window->cambiar_velocidad_rotacion_piernas(getVelocidadPiernas());
}
void _gl_widget::boton_cabezaA_slot(bool){
    Mazinger.head_faster();
    Window->cambiar_velocidad_escalado_cabeza(getVelocidadCabeza());
}
void _gl_widget::boton_cabezaD_slot(bool){
    Mazinger.head_slower();
    Window->cambiar_velocidad_escalado_cabeza(getVelocidadCabeza());
}



void _gl_widget::checkbox_luz0_slot(int State){
    if(State == Qt::Checked)        First_light = true;
    else                            First_light = false;
    update();
}
void _gl_widget::checkbox_luz1_slot(int State){
    if(State == Qt::Checked)        Second_light = true;
    else                            Second_light = false;
    update();
}

void _gl_widget::boton_luz1_derecha_slot(bool){
    angulo_second_light = (angulo_second_light < 360 ) ? angulo_second_light += FACTOR_GIRO_LUZ1 : angulo_second_light = 0;
    update();
}
void _gl_widget::boton_luz1_izquierda_slot(bool){
    angulo_second_light = (angulo_second_light > 0) ? angulo_second_light -= FACTOR_GIRO_LUZ1 : angulo_second_light = 360;
    update();
}

