/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QGroupBox>
#include <QComboBox>

#include "window.h"
#include "glwidget.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_window::_window()
{

    QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QWidget *Central_widget = new QWidget(this);


    QFrame *Framed_widget= new QFrame(Central_widget);
    Framed_widget->setSizePolicy(Q);
    Framed_widget->setFrameStyle(QFrame::Panel);
    Framed_widget->setLineWidth(3);

    GL_widget = new _gl_widget(this);
    GL_widget->setSizePolicy(Q);

    //Creamos la tabla donde vamos a tener todas las opciones
    QTabWidget *Tab_widget = new QTabWidget;
    Tab_widget->setMaximumWidth(400);
//    Tab_widget->setMaximumHeight(1000); //Podria evitar que se salga de pantalla, acortando lo que pueda


    // ------------ APARTADO DE VISUALIZACION DE OBJETOS Y AJUSTES GENERALES ------------

    QWidget *Visualization_widget = new QWidget;
    QVBoxLayout *Visualization_layout= new QVBoxLayout;

    //Creo las etiquetas y los checkbox para los modos de visualizacion
    QLabel *Label_Points = new QLabel("Puntos (P): ");
    QLabel *Label_Lines  = new QLabel("Líneas (L): ");
    QLabel *Label_Fill   = new QLabel("Relleno (F): ");

    Checkbox_Points = new QCheckBox;
    Checkbox_Points->setCheckState(Qt::Unchecked);  // El dibujado de puntos viene desactivado por defecto
    connect(Checkbox_Points, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_points_slot(int)));

    Checkbox_Lines = new QCheckBox;
    Checkbox_Lines->setCheckState(Qt::Checked);  // El dibujado de lineas viene activado por defecto
    connect(Checkbox_Lines, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_lines_slot(int)));

    Checkbox_Fill = new QCheckBox;
    Checkbox_Fill->setCheckState(Qt::Unchecked);  // El dibujado de relleno viene desactivado por defecto
    connect(Checkbox_Fill, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_fill_slot(int)));

    //Creo el layout donde se van a meter los botones anteriores
    QGridLayout *Seleccion_visualizacion = new QGridLayout;
    //Creo la caja donde se va a meter el texto y los botones anteriores.
    QGroupBox *Vis_aux = new QGroupBox("Modos de visualización: ");
    //Lo conecto todo
    Vis_aux->setLayout(Seleccion_visualizacion);
    Visualization_layout->addWidget(Vis_aux);
//    Visualization_layout->addStretch();
    Visualization_widget->setLayout(Visualization_layout);
    //Añado las etiquetas y botones como tal
    Seleccion_visualizacion->addWidget(Label_Points,0,0,Qt::AlignRight);
    Seleccion_visualizacion->addWidget(Checkbox_Points,0,1);
    Seleccion_visualizacion->addWidget(Label_Lines,1,0,Qt::AlignRight);
    Seleccion_visualizacion->addWidget(Checkbox_Lines,1,1);
    Seleccion_visualizacion->addWidget(Label_Fill,2,0,Qt::AlignRight);
    Seleccion_visualizacion->addWidget(Checkbox_Fill,2,1);

    //Creo el combobox con los modos de relleno
    Combobox_relleno = new QComboBox;
    Combobox_relleno->addItem("Color sólido (F1)");
    Combobox_relleno->addItem("Ajedrez (F2)");
    Combobox_relleno->addItem("Sombreado plano (F3)");
    Combobox_relleno->addItem("Sombreado de Gouraud (F4)");
    Combobox_relleno->addItem("Textura (F5)");
    Combobox_relleno->addItem("Textura con sombreado plano (F6)");
    Combobox_relleno->addItem("Textura con sombreado de Gouraud (F7)");
    Combobox_relleno->addItem("Color aleatorio en los triangulos (F8)");
    Combobox_relleno->addItem("Color aleatorio en los vértices (F9)");
    connect(Combobox_relleno, SIGNAL(currentIndexChanged(int)), GL_widget, SLOT(combobox_relleno_slot(int)));

    //Creo el layout donde se va a meter el combobox
    QVBoxLayout *Seleccion_relleno = new QVBoxLayout;
    //Creo la caja donde se va a meter el texto y el selector de objetos
    QGroupBox *Relleno_aux = new QGroupBox("Modos de visualización con relleno:");
    //Lo conecto todo
    Relleno_aux->setLayout(Seleccion_relleno);
    Visualization_layout->addWidget(Relleno_aux);
//    Visualization_layout->addStretch();
    //Meto el selector de objetos
    Seleccion_relleno->addWidget(Combobox_relleno);

    //Creo el combobox con los modos de camara
    Combobox_cameras = new QComboBox;
    Combobox_cameras->addItem("Proyección de perspectiva (C)");
    Combobox_cameras->addItem("Proyección paralela (V)");
    connect(Combobox_cameras, SIGNAL(currentIndexChanged(int)), GL_widget, SLOT(combobox_cameras_slot(int)));
    //Creo el layout donde se va a meter el combobox
    QVBoxLayout *Seleccion_cameras = new QVBoxLayout;
    //Creo la caja donde se va a meter el texto y el selector de objetos
    QGroupBox *Cameras_aux = new QGroupBox("Tipos de cámara:");
    //Lo conecto todo
    Cameras_aux->setLayout(Seleccion_cameras);
    Visualization_layout->addWidget(Cameras_aux);
//    Visualization_layout->addStretch();
    //Meto el selector de objetos
    Seleccion_cameras->addWidget(Combobox_cameras);

    //Creo las etiquetas y los checkbox para la seleccion de luces
    QLabel *Label_Luz0 = new QLabel("Luz blanca (J): ");
    QLabel *Label_Luz1 = new QLabel("Luz magenta (K): ");

    Checkbox_Luz0 = new QCheckBox;
    Checkbox_Luz0->setCheckState(Qt::Unchecked);
    connect(Checkbox_Luz0, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_luz0_slot(int)));

    Checkbox_Luz1 = new QCheckBox;
    Checkbox_Luz1->setCheckState(Qt::Unchecked);
    connect(Checkbox_Luz1, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_luz1_slot(int)));

    //Creo los botones para los giros de las luces
    QPushButton *BotonGirarDerechaLuz1 = new QPushButton("Girar hacia la derecha (G)", this);
    QPushButton *BotonGirarIzquierdaLuz1  = new QPushButton("Girar hacia la izquierda (H)", this);
    connect(BotonGirarDerechaLuz1,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_luz1_derecha_slot(bool)));
    connect(BotonGirarIzquierdaLuz1,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_luz1_izquierda_slot(bool)));

    //Creo el layout donde se van a meter los botones anteriores
    QGridLayout *Seleccion_luces = new QGridLayout;
    //Creo la caja donde se va a meter el texto y los botones anteriores.
    QGroupBox *Luces_aux = new QGroupBox("Selector de luces: ");
    //Lo conecto todo
    Luces_aux->setLayout(Seleccion_luces);
    Visualization_layout->addWidget(Luces_aux);
//    Visualization_layout->addStretch();
    //Añado las etiquetas y botones como tal
    Seleccion_luces->addWidget(Label_Luz0,0,0,Qt::AlignRight);
    Seleccion_luces->addWidget(Checkbox_Luz0,0,1);
    Seleccion_luces->addWidget(Label_Luz1,1,0,Qt::AlignRight);
    Seleccion_luces->addWidget(Checkbox_Luz1,1,1);

    //Creo el layout donde se van a meter los botones anteriores
    QGridLayout *Seleccion_giros_luces = new QGridLayout;
    //Creo la caja donde se va a meter el texto y los botones anteriores.
    QGroupBox *Giros_luces_aux = new QGroupBox("Giro de la luz magenta: ");
    //Lo conecto todo
    Giros_luces_aux->setLayout(Seleccion_giros_luces);
    Visualization_layout->addWidget(Giros_luces_aux);
//    Visualization_layout->addStretch();
    //Añado las etiquetas y botones como tal
    Seleccion_giros_luces->addWidget(BotonGirarDerechaLuz1,0,0);
    Seleccion_giros_luces->addWidget(BotonGirarIzquierdaLuz1,1,0);

    //Creo el combobox donde va a estar el selector de objetos y lo conecto
    Combobox_objects = new QComboBox;
    Combobox_objects->addItem("Tetraedro (1)");
    Combobox_objects->addItem("Cubo (2)");
    Combobox_objects->addItem("Cono (3)");
    Combobox_objects->addItem("Cilindro (4)");
    Combobox_objects->addItem("Esfera (5)");
    Combobox_objects->addItem("Lector .PLY (6)");
    Combobox_objects->addItem("Lector .PLY (Perfiles)");
    Combobox_objects->addItem("Mazinger Z (7)");
    Combobox_objects->addItem("Tablero (8)");
    Combobox_objects->addItem("Octoedro");
    Combobox_objects->addItem("Copa");
    Combobox_objects->addItem("Copa al reves");
    Combobox_objects->addItem("Hormigonera");
    Combobox_objects->addItem("Peon");
    connect(Combobox_objects, SIGNAL(currentIndexChanged(int)), GL_widget, SLOT(combobox_object_slot(int)));

    //Creo el layout donde se va a meter el combobox
    QVBoxLayout *Seleccion_objetos = new QVBoxLayout;
    //Creo la caja donde se va a meter el texto y el selector de objetos
    QGroupBox *Objects_aux = new QGroupBox("Objetos disponibles:");
    //Lo conecto todo
    Objects_aux->setLayout(Seleccion_objetos);
    Visualization_layout->addWidget(Objects_aux);
//    Visualization_layout->addStretch();
    //Meto el selector de objetos
    Seleccion_objetos->addWidget(Combobox_objects);

    // ------------ APARTADO DE CONFIGURACION DE LA ANIMACION S (MODOS DE ANIMACION Y VELOCIDADES) ------------

    QWidget *AnimationS_widget = new QWidget;
    QVBoxLayout *AnimationS_layout = new QVBoxLayout;

    //Creo las etiquetas para los modos de animacion
    QLabel *Label_Full_Animation = new QLabel("Animación (A): ");
    QLabel *Label_Arm_Animation = new QLabel("Rotacion de los brazos: ");
    QLabel *Label_Leg_Animation = new QLabel("Rotación de las piernas: ");
    QLabel *Label_Body_Animation = new QLabel("Rotación del cuerpo: ");
    QLabel *Label_Antebrazo_Rotate_Animation = new QLabel("Rotacion del antebrzo: ");
    QLabel *Label_Antebrazo_Scale_Animation = new QLabel("Escalado de los antebrazos: ");
    QLabel *Label_Escalado_Cabeza_Animation = new QLabel("Escalado de la cabeza: ");

    Checkbox_Animation = new QCheckBox;
    Checkbox_Animation_Arm = new QCheckBox;
    Checkbox_Animation_Leg = new QCheckBox;
    Checkbox_Animation_Body = new QCheckBox;
    Checkbox_Animation_Rotate_Antebrazo = new QCheckBox;
    Checkbox_Animation_Scale_Antebrazo = new QCheckBox;
    Checkbox_Animation_Scale_Cabeza = new QCheckBox;

    //Todas las animaciones vendran desactivadas por defecto
    Checkbox_Animation->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Arm->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Leg->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Body->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Rotate_Antebrazo->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Scale_Antebrazo->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Scale_Cabeza->setCheckState(Qt::Unchecked);
    //Tener en cuenta que la primera activa de primeras a todas las demas, pero se pueden ir quitando individualmente

    //Conectamos con las funciones
    connect(Checkbox_Animation, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_animation_slot(int)));
    connect(Checkbox_Animation_Arm, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_animation_arm_slot(int)));
    connect(Checkbox_Animation_Leg, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_animation_leg_slot(int)));
    connect(Checkbox_Animation_Rotate_Antebrazo, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_animation_rotate_antebrazo_slot(int)));
    connect(Checkbox_Animation_Body, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_animation_body_slot(int)));
    connect(Checkbox_Animation_Scale_Antebrazo, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_animation_scale_antebrazo_slot(int)));
    connect(Checkbox_Animation_Scale_Cabeza, SIGNAL(stateChanged(int)), GL_widget, SLOT(checkbox_animation_scale_cabeza_slot(int)));


    //Creo el layout donde se van a meter los botones anteriores
    QGridLayout *Seleccion_animacion = new QGridLayout;
    //Creo la caja donde se va a meter el texto y los botones anteriores.
    QGroupBox *AnimationS_aux = new QGroupBox("Selectores de la animación automática: ");
    //Lo conecto todo
    AnimationS_aux->setLayout(Seleccion_animacion);
    AnimationS_layout->addWidget(AnimationS_aux);
    AnimationS_layout->addStretch();
    AnimationS_widget->setLayout(AnimationS_layout);

    //Añado las etiquetas y botones como tal
    Seleccion_animacion->addWidget(Label_Full_Animation,0,0,Qt::AlignCenter);
    Seleccion_animacion->addWidget(Checkbox_Animation,0,1);
    Seleccion_animacion->addWidget(Label_Arm_Animation,1,0,Qt::AlignCenter);
    Seleccion_animacion->addWidget(Checkbox_Animation_Arm,1,1);
    Seleccion_animacion->addWidget(Label_Leg_Animation,2,0,Qt::AlignCenter);
    Seleccion_animacion->addWidget(Checkbox_Animation_Leg,2,1);
    Seleccion_animacion->addWidget(Label_Body_Animation,3,0,Qt::AlignCenter);
    Seleccion_animacion->addWidget(Checkbox_Animation_Body,3,1);
    Seleccion_animacion->addWidget(Label_Antebrazo_Rotate_Animation,4,0,Qt::AlignCenter);
    Seleccion_animacion->addWidget(Checkbox_Animation_Rotate_Antebrazo,4,1);
    Seleccion_animacion->addWidget(Label_Antebrazo_Scale_Animation,5,0,Qt::AlignCenter);
    Seleccion_animacion->addWidget(Checkbox_Animation_Scale_Antebrazo,5,1);
    Seleccion_animacion->addWidget(Label_Escalado_Cabeza_Animation,6,0,Qt::AlignCenter);
    Seleccion_animacion->addWidget(Checkbox_Animation_Scale_Cabeza,6,1);


    //Creo los cuadro con el texto y las opciones para las variaciones en la velocidad de los movimientos.
    QGroupBox *AnimationS_aux1 = new QGroupBox("Velocidad de rotación los brazos:");
    QGroupBox *AnimationS_aux2 = new QGroupBox("Velocidad de rotación de los antebrazos:");
    QGroupBox *AnimationS_aux3 = new QGroupBox("Velocidad de escalado de los antebrazos:");
    QGroupBox *AnimationS_aux4 = new QGroupBox("Velocidad de rotación del tronco superior:");
    QGroupBox *AnimationS_aux5 = new QGroupBox("Velocidad de rotación de las piernas:");
    QGroupBox *AnimationS_aux6 = new QGroupBox("Velocidad de escalado de la cabeza:");


    //Creo los distintos layout donde van a ir los botones para las distintas velocidades y lo meto dento de la caja con el texto
    QVBoxLayout *BotonesVelocidadRotacionBrazo   = new QVBoxLayout;
    QVBoxLayout *BotonesVelocidadRotacionAntebrazo = new QVBoxLayout;
    QVBoxLayout *BotonesVelocidadEscaladoAntebrazo  = new QVBoxLayout;
    QVBoxLayout *BotonesVelocidadRotacionCuerpo = new QVBoxLayout;
    QVBoxLayout *BotonesVelocidadRotacionPiernas    = new QVBoxLayout;
    QVBoxLayout *BotonesVelocidadEscaladoCabeza = new QVBoxLayout;
    AnimationS_aux1->setLayout(BotonesVelocidadRotacionBrazo);
    AnimationS_aux2->setLayout(BotonesVelocidadRotacionAntebrazo);
    AnimationS_aux3->setLayout(BotonesVelocidadEscaladoAntebrazo);
    AnimationS_aux4->setLayout(BotonesVelocidadRotacionCuerpo);
    AnimationS_aux5->setLayout(BotonesVelocidadRotacionPiernas);
    AnimationS_aux6->setLayout(BotonesVelocidadEscaladoCabeza);

    //Creamos los distintos botones
    QPushButton *BotonVelocidadRotacionBrazosA = new QPushButton("Aumentar", this);
    QPushButton *BotonVelocidadRotacionBrazosD  = new QPushButton("Disminuir", this);
    QPushButton *BotonVelocidadRotacionAntebrazosA = new QPushButton("Aumentar", this);
    QPushButton *BotonVelocidadRotacionAntebrazosD = new QPushButton("Disminuir", this);
    QPushButton *BotonVelocidadEscaladoAntebrazosA = new QPushButton("Aumentar", this);
    QPushButton *BotonVelocidadEscaladoAntebrazosD = new QPushButton("Disminuir", this);

    QPushButton *BotonVelocidadCuerpoA = new QPushButton("Aumentar", this);
    QPushButton *BotonVelocidadCuerpoD = new QPushButton("Disminuir", this);
    QPushButton *BotonVelocidadPiernaA  = new QPushButton("Aumentar", this);
    QPushButton *BotonVelocidadPiernaD = new QPushButton("Disminuir", this);
    QPushButton *BotonVelocidadCabezaA  = new QPushButton("Aumentar", this);
    QPushButton *BotonVelocidadCabezaD = new QPushButton("Disminuir", this);

    //Añadimos los botones
    BotonesVelocidadRotacionBrazo->addWidget(BotonVelocidadRotacionBrazosA);
    BotonesVelocidadRotacionBrazo->addWidget(BotonVelocidadRotacionBrazosD);
    BotonesVelocidadRotacionAntebrazo->addWidget(BotonVelocidadRotacionAntebrazosA);
    BotonesVelocidadRotacionAntebrazo->addWidget(BotonVelocidadRotacionAntebrazosD);
    BotonesVelocidadEscaladoAntebrazo->addWidget(BotonVelocidadEscaladoAntebrazosA);
    BotonesVelocidadEscaladoAntebrazo->addWidget(BotonVelocidadEscaladoAntebrazosD);
    BotonesVelocidadRotacionCuerpo->addWidget(BotonVelocidadCuerpoA);
    BotonesVelocidadRotacionCuerpo->addWidget(BotonVelocidadCuerpoD);
    BotonesVelocidadRotacionPiernas->addWidget(BotonVelocidadPiernaA);
    BotonesVelocidadRotacionPiernas->addWidget(BotonVelocidadPiernaD);
    BotonesVelocidadEscaladoCabeza->addWidget(BotonVelocidadCabezaA);
    BotonesVelocidadEscaladoCabeza->addWidget(BotonVelocidadCabezaD);

    //Conectamos con todos los SLOTS.
    connect(BotonVelocidadRotacionBrazosA,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_brazos_velocidadRA_slot(bool)));
    connect(BotonVelocidadRotacionBrazosD,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_brazos_velocidadRD_slot(bool)));
    connect(BotonVelocidadRotacionAntebrazosA,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazos_velocidadRA_slot(bool)));
    connect(BotonVelocidadRotacionAntebrazosD,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazos_velocidadRD_slot(bool)));
    connect(BotonVelocidadEscaladoAntebrazosA,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazos_velocidadEA_slot(bool)));
    connect(BotonVelocidadEscaladoAntebrazosD,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazos_velocidadED_slot(bool)));
    connect(BotonVelocidadCuerpoA,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_cuerpo_velocidadA_slot(bool)));
    connect(BotonVelocidadCuerpoD,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_cuerpo_velocidadD_slot(bool)));
    connect(BotonVelocidadPiernaA,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_pierna_velocidadA_slot(bool)));
    connect(BotonVelocidadPiernaD,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_pierna_velocidadD_slot(bool)));
    connect(BotonVelocidadCabezaA,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_cabezaA_slot(bool)));
    connect(BotonVelocidadCabezaD,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_cabezaD_slot(bool)));

    //Meto los conjuntos de opciones
    AnimationS_layout->addWidget(AnimationS_aux1);
    AnimationS_layout->addWidget(AnimationS_aux2);
    AnimationS_layout->addWidget(AnimationS_aux3);
    AnimationS_layout->addWidget(AnimationS_aux4);
    AnimationS_layout->addWidget(AnimationS_aux5);
    AnimationS_layout->addWidget(AnimationS_aux6);

    //Creacion de las cajas donde se muestran los valores de las distintas velocidad.
    Line_edit_arm_speed = new QLineEdit;
    Line_edit_arm_speed->setMaxLength(4);
    Line_edit_arm_speed->setReadOnly(true);
    Line_edit_arm_speed->setText( QString::number(GL_widget->getVelocidadBrazos()));

    Line_edit_leg_speed = new QLineEdit;
    Line_edit_leg_speed->setMaxLength(4);
    Line_edit_leg_speed->setReadOnly(true);
    Line_edit_leg_speed->setText( QString::number(GL_widget->getVelocidadPiernas()));

    Line_edit_rotate_antebrazo_speed= new QLineEdit;
    Line_edit_rotate_antebrazo_speed->setMaxLength(4);
    Line_edit_rotate_antebrazo_speed->setReadOnly(true);
    Line_edit_rotate_antebrazo_speed->setText( QString::number(GL_widget->getVelocidadGiroAntebrazos()));

    Line_edit_body_speed = new QLineEdit;
    Line_edit_body_speed->setMaxLength(4);
    Line_edit_body_speed->setReadOnly(true);
    Line_edit_body_speed->setText( QString::number(GL_widget->getVelocidadCuerpo()));

    Line_edit_scale_antebrazo_speed= new QLineEdit;
    Line_edit_scale_antebrazo_speed->setMaxLength(6);
    Line_edit_scale_antebrazo_speed->setReadOnly(true);
    Line_edit_scale_antebrazo_speed->setText( QString::number(GL_widget->getVelocidadEscaladoAntebrazos()));

    Line_edit_scale_cabeza_speed  = new QLineEdit;
    Line_edit_scale_cabeza_speed->setMaxLength(4);
    Line_edit_scale_cabeza_speed->setReadOnly(true);
    Line_edit_scale_cabeza_speed->setText( QString::number(GL_widget->getVelocidadCabeza()));

    //Por lo visto los label no se pueden reutilizar en varios sitios
    QLabel * Label_velocidad = new QLabel("Velocidad actual:");
    QLabel * Label_velocidad2 = new QLabel("Velocidad actual:");
    QLabel * Label_velocidad3 = new QLabel("Velocidad actual:");
    QLabel * Label_velocidad4 = new QLabel("Velocidad actual:");
    QLabel * Label_velocidad5 = new QLabel("Velocidad actual:");
    QLabel * Label_velocidad6 = new QLabel("Velocidad actual:");

    QGridLayout *Layout_velocidad_brazos = new QGridLayout;
    Layout_velocidad_brazos->addWidget(Label_velocidad,0,0);
    Layout_velocidad_brazos->addWidget(Line_edit_arm_speed,0,1);
    BotonesVelocidadRotacionBrazo->addLayout(Layout_velocidad_brazos);

    QGridLayout *Layout_velocidad_piernas = new QGridLayout;
    Layout_velocidad_piernas->addWidget(Label_velocidad2,0,0);
    Layout_velocidad_piernas->addWidget(Line_edit_leg_speed,0,1);
    BotonesVelocidadRotacionPiernas->addLayout(Layout_velocidad_piernas);

    QGridLayout *Layout_velocidad_rotacion_antebrazo = new QGridLayout;
    Layout_velocidad_rotacion_antebrazo->addWidget(Label_velocidad3,0,0);
    Layout_velocidad_rotacion_antebrazo->addWidget(Line_edit_rotate_antebrazo_speed,0,1);
    BotonesVelocidadRotacionAntebrazo->addLayout(Layout_velocidad_rotacion_antebrazo);

    QGridLayout *Layout_velocidad_cuerpo = new QGridLayout;
    Layout_velocidad_cuerpo->addWidget(Label_velocidad4,0,0);
    Layout_velocidad_cuerpo->addWidget(Line_edit_body_speed,0,1);
    BotonesVelocidadRotacionCuerpo->addLayout(Layout_velocidad_cuerpo);

    QGridLayout *Layout_velocidad_escalado_antebrazo = new QGridLayout;
    Layout_velocidad_escalado_antebrazo->addWidget(Label_velocidad5,0,0);
    Layout_velocidad_escalado_antebrazo->addWidget(Line_edit_scale_antebrazo_speed,0,1);
    BotonesVelocidadEscaladoAntebrazo->addLayout(Layout_velocidad_escalado_antebrazo);

    QGridLayout *Layout_velocidad_escalado_cabeza = new QGridLayout;
    Layout_velocidad_escalado_cabeza->addWidget(Label_velocidad6,0,0);
    Layout_velocidad_escalado_cabeza->addWidget(Line_edit_scale_cabeza_speed,0,1);
    BotonesVelocidadEscaladoCabeza->addLayout(Layout_velocidad_escalado_cabeza);

    // ------------ APARTADO DE CONFIGURACION DE LA ANIMACION I (BRAZOS) ------------

    QWidget *Animation1_widget= new QWidget;
    QVBoxLayout *Animation1_layout = new QVBoxLayout;

    //Creo los cuadros con el texto y las opciones para el modelo jerarquico
    QGroupBox *Animation1_aux = new QGroupBox("Movimientos del brazo derecho:");
    QGroupBox *Animation2_aux = new QGroupBox("Movimientos del brazo izquierdo:");
    QGroupBox *Animation3_aux = new QGroupBox("Movimientos de ambos brazos:");

    //Creo los distintos layout donde van a ir los botones para los distintos objetos y lo meto dento de la caja con el texto
    QVBoxLayout *BotonesBrazoDerecho   = new QVBoxLayout;
    QVBoxLayout *BotonesBrazoIzquierdo = new QVBoxLayout;
    QVBoxLayout *BotonesAmbosBrazos = new QVBoxLayout;
    Animation1_aux->setLayout(BotonesBrazoDerecho);
    Animation2_aux->setLayout(BotonesBrazoIzquierdo);
    Animation3_aux->setLayout(BotonesAmbosBrazos);


    //Creamos los distintos botones
    QPushButton *BotonBrazoDerechoArriba = new QPushButton("Brazo arriba", this);
    QPushButton *BotonBrazoDerechoAbajo  = new QPushButton("Brazo abajo", this);
    QPushButton *BotonBrazoIzquierdoArriba = new QPushButton("Brazo arriba", this);
    QPushButton *BotonBrazoIzquierdoAbajo = new QPushButton("Brazo abajo", this);

    QPushButton *BotonAntebrazoDerechoArriba = new QPushButton("Antebrazo arriba", this);
    QPushButton *BotonAntebrazoDerechoAbajo = new QPushButton("Antebrazo abajo", this);
    QPushButton *BotonAntebrazoIzquierdoArriba = new QPushButton("Antebrazo arriba", this);
    QPushButton *BotonAntebrazoIzquierdoAbajo = new QPushButton("Antebrazo abajo", this);

    QPushButton *BotonAntebrazoDerechoOut  = new QPushButton("Antebrazo fuera", this);
    QPushButton *BotonAntebrazoDerechoIn = new QPushButton("Antebrazo dentro", this);
    QPushButton *BotonAntebrazoIzquierdoOut  = new QPushButton("Antebrazo fuera", this);
    QPushButton *BotonAntebrazoIzquierdoIn = new QPushButton("Antebrazo dentro", this);

    QPushButton *BotonBrazosArriba = new QPushButton("Brazos arriba",this);
    QPushButton *BotonBrazosAbajo = new QPushButton("Brazos abajo",this);
    QPushButton *BotonAntebrazosArriba = new QPushButton("Antebrazos arriba",this);
    QPushButton *BotonAntebrazosAbajo = new QPushButton("Antebrazos abajo",this);
    QPushButton *BotonesAntebrazosOut = new QPushButton("Antebrazos fuera",this);
    QPushButton *BotonesAntebrazosIn = new QPushButton("Antebrazos dentro",this);


    //Añadimos los botones
    BotonesBrazoDerecho->addWidget(BotonBrazoDerechoArriba);
    BotonesBrazoDerecho->addWidget(BotonBrazoDerechoAbajo);
    BotonesBrazoDerecho->addWidget(BotonAntebrazoDerechoArriba);
    BotonesBrazoDerecho->addWidget(BotonAntebrazoDerechoAbajo);
    BotonesBrazoDerecho->addWidget(BotonAntebrazoDerechoOut);
    BotonesBrazoDerecho->addWidget(BotonAntebrazoDerechoIn);

    BotonesBrazoIzquierdo->addWidget(BotonBrazoIzquierdoArriba);
    BotonesBrazoIzquierdo->addWidget(BotonBrazoIzquierdoAbajo);
    BotonesBrazoIzquierdo->addWidget(BotonAntebrazoIzquierdoArriba);
    BotonesBrazoIzquierdo->addWidget(BotonAntebrazoIzquierdoAbajo);
    BotonesBrazoIzquierdo->addWidget(BotonAntebrazoIzquierdoOut);
    BotonesBrazoIzquierdo->addWidget(BotonAntebrazoIzquierdoIn);

    BotonesAmbosBrazos->addWidget(BotonBrazosArriba);
    BotonesAmbosBrazos->addWidget(BotonBrazosAbajo);
    BotonesAmbosBrazos->addWidget(BotonAntebrazosArriba);
    BotonesAmbosBrazos->addWidget(BotonAntebrazosAbajo);
    BotonesAmbosBrazos->addWidget(BotonesAntebrazosOut);
    BotonesAmbosBrazos->addWidget(BotonesAntebrazosIn);


    //Conectamos con todos los SLOT
    connect(BotonBrazoDerechoArriba,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_brazo_derecho_arriba_slot(bool)));
    connect(BotonBrazoDerechoAbajo,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_brazo_derecho_abajo_slot(bool)));
    connect(BotonAntebrazoDerechoArriba,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazo_derecho_arriba_slot(bool)));
    connect(BotonAntebrazoDerechoAbajo,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazo_derecho_abajo_slot(bool)));
    connect(BotonAntebrazoDerechoOut,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazo_derecho_fuera_slot(bool)));
    connect(BotonAntebrazoDerechoIn,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazo_derecho_dentro_slot(bool)));

    connect(BotonBrazoIzquierdoArriba,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_brazo_izquierdo_arriba_slot(bool)));
    connect(BotonBrazoIzquierdoAbajo,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_brazo_izquierdo_abajo_slot(bool)));
    connect(BotonAntebrazoIzquierdoArriba,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazo_izquierdo_arriba_slot(bool)));
    connect(BotonAntebrazoIzquierdoAbajo,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazo_izquierdo_abajo_slot(bool)));
    connect(BotonAntebrazoIzquierdoOut,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazo_izquierdo_fuera_slot(bool)));
    connect(BotonAntebrazoIzquierdoIn,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazo_izquierdo_dentro_slot(bool)));

    connect(BotonBrazosArriba,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_brazos_arriba_slot(bool)));
    connect(BotonBrazosAbajo,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_brazos_abajo_slot(bool)));
    connect(BotonAntebrazosArriba,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazos_arriba_slot(bool)));
    connect(BotonAntebrazosAbajo,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazos_abajo_slot(bool)));
    connect(BotonesAntebrazosOut,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazos_fuera_slot(bool)));
    connect(BotonesAntebrazosIn,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_antebrazos_dentro_slot(bool)));

    //Meto los conjuntos de opciones y seteo el layout.
    Animation1_layout->addWidget(Animation1_aux);
    Animation1_layout->addWidget(Animation2_aux);
    Animation1_layout->addWidget(Animation3_aux);
    Animation1_widget->setLayout(Animation1_layout);



    // ------------ APARTADO DE CONFIGURACION DE LA ANIMACION II (CUERPO Y PIERNAS) ------------

    QWidget *Animation2_widget= new QWidget;
    QVBoxLayout *Animation2_layout = new QVBoxLayout;

    //Creo los cuadros con el texto y las opciones para el modelo jerarquico
    QGroupBox *Animation4_aux = new QGroupBox("Movimientos del tronco superior:");
    QGroupBox *Animation5_aux = new QGroupBox("Movimientos de ambas piernas:");
    QGroupBox *Animation6_aux = new QGroupBox("Movimientos de la pierna derecha:");
    QGroupBox *Animation7_aux = new QGroupBox("Movimientos de la pierna izquierda:");
    QGroupBox *Animation8_aux = new QGroupBox("Movimientos de la cabeza: ");

    //Creo los distintos layout donde van a ir los botones para los distintos objetos y lo meto dento de la caja con el texto
    QVBoxLayout *BotonesPecho   = new QVBoxLayout;
    QVBoxLayout *BotonesPiernas = new QVBoxLayout;
    QVBoxLayout *BotonesPiernaDerecha = new QVBoxLayout;
    QVBoxLayout *BotonesPiernaIzquierda= new QVBoxLayout;
    QVBoxLayout *BotonesCabeza = new QVBoxLayout;

    Animation4_aux->setLayout(BotonesPecho);
    Animation5_aux->setLayout(BotonesPiernas);
    Animation6_aux->setLayout(BotonesPiernaDerecha);
    Animation7_aux->setLayout(BotonesPiernaIzquierda);
    Animation8_aux->setLayout(BotonesCabeza);

    //Creamos los distintos botones
    QPushButton *BotonPiernaDerechaArriba = new QPushButton("Pierna arriba",this);
    QPushButton *BotonPiernaDerechaAbajo = new QPushButton("Pierna abajo",this);
    QPushButton *BotonPiernaIzquierdaArriba = new QPushButton("Pierna arriba",this);
    QPushButton *BotonPiernaIzquierdaAbajo = new QPushButton("Pierna abajo",this);
    QPushButton *BotonPiernasForward = new QPushButton("Andar hacia delante",this);
    QPushButton *BotonPiernasBackwards = new QPushButton("Andar hacia atrás",this);
    QPushButton *BotonCuerpoDerecha = new QPushButton("Rotar derecha",this);
    QPushButton *BotonCuerpoIzquierda = new QPushButton("Rotar izquierda",this);
    QPushButton *BotonCabezaFuera = new QPushButton("Cabeza fuera",this);
    QPushButton *BotonCabezaDentro = new QPushButton("Cabeza dentro",this);

    //Añadimos los botones
    BotonesPecho->addWidget(BotonCuerpoDerecha);
    BotonesPecho->addWidget(BotonCuerpoIzquierda);
    BotonesPiernas->addWidget(BotonPiernasForward);
    BotonesPiernas->addWidget(BotonPiernasBackwards);
    BotonesPiernaDerecha->addWidget(BotonPiernaDerechaArriba);
    BotonesPiernaDerecha->addWidget(BotonPiernaDerechaAbajo);
    BotonesPiernaIzquierda->addWidget(BotonPiernaIzquierdaArriba);
    BotonesPiernaIzquierda->addWidget(BotonPiernaIzquierdaAbajo);
    BotonesCabeza->addWidget(BotonCabezaFuera);
    BotonesCabeza->addWidget(BotonCabezaDentro);

    //Conectamos con todos los SLOT
    connect(BotonPiernaDerechaArriba,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_pierna_derecha_arriba_slot(bool)));
    connect(BotonPiernaDerechaAbajo,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_pierna_derecha_abajo_slot(bool)));
    connect(BotonPiernaIzquierdaArriba,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_pierna_izquierda_arriba_slot(bool)));
    connect(BotonPiernaIzquierdaAbajo,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_pierna_izquierda_abajo_slot(bool)));
    connect(BotonPiernasForward,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_piernas_forward_slot(bool)));
    connect(BotonPiernasBackwards,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_piernas_backward_slot(bool)));
    connect(BotonCuerpoDerecha,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_pecho_derecha_slot(bool)));
    connect(BotonCuerpoIzquierda,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_pecho_izquierda_slot(bool)));
    connect(BotonCabezaFuera,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_cabeza_fuera_slot(bool)));
    connect(BotonCabezaDentro,SIGNAL(clicked(bool)),GL_widget,SLOT(boton_cabeza_dentro_slot(bool)));


    Animation2_layout->addWidget(Animation4_aux);
    Animation2_layout->addWidget(Animation5_aux);
    Animation2_layout->addWidget(Animation6_aux);
    Animation2_layout->addWidget(Animation7_aux);
    Animation2_layout->addWidget(Animation8_aux);
    Animation2_widget->setLayout(Animation2_layout);


    Tab_widget->addTab(Visualization_widget,"Visualization");
    Tab_widget->addTab(AnimationS_widget,"Animation (S)");
    Tab_widget->addTab(Animation1_widget,"Animation (I)");
    Tab_widget->addTab(Animation2_widget,"Animation (II)");

    QHBoxLayout *Horizontal_frame = new QHBoxLayout();
    Horizontal_frame->setContentsMargins(1,1,1,1);

    Horizontal_frame->addWidget(GL_widget);
    Framed_widget->setLayout(Horizontal_frame);

    QHBoxLayout *Horizontal_main = new QHBoxLayout(Central_widget);

    Horizontal_main->addWidget(Framed_widget);
    Horizontal_main->addWidget(Tab_widget);

    Central_widget->setLayout(Horizontal_main);
    setCentralWidget(Central_widget);

    // actions for file menu
    QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
    Exit->setShortcut(tr("Ctrl+Q"));
    Exit->setToolTip(tr("Exit the application"));
    connect(Exit, SIGNAL(triggered()), this, SLOT(close()));

    // menus
    QMenu *File_menu=menuBar()->addMenu(tr("&File"));
    File_menu->addAction(Exit);
    File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

    setWindowTitle(tr("Prácticas IG - José Alberto Gómez García"));

    //  Mantengo la proporcion cuadrada del lienzo asignando un tamaño cuadrado fijo
    GL_widget->setFixedSize(800,800);

    //  Lo hacemos más largo al añadir la tabla de opciones
    resize(1200,800);

}

void _window::change_points_state(bool State) {
    Checkbox_Points->blockSignals(true);
    if(State == true)           Checkbox_Points->setCheckState(Qt::Checked);
    else                        Checkbox_Points->setCheckState(Qt::Unchecked);
    Checkbox_Points->blockSignals(false);
}

void _window::change_lines_state(bool State) {
    Checkbox_Lines->blockSignals(true);
    if(State == true)           Checkbox_Lines->setCheckState(Qt::Checked);
    else                        Checkbox_Lines->setCheckState(Qt::Unchecked);
    Checkbox_Lines->blockSignals(false);
}

void _window::change_fill_state(bool State) {
    Checkbox_Fill->blockSignals(true);
    if(State == true)           Checkbox_Fill->setCheckState(Qt::Checked);
    else                        Checkbox_Fill->setCheckState(Qt::Unchecked);
    Checkbox_Fill->blockSignals(false);
}

void _window::change_light0_state(bool State){
    Checkbox_Luz0->blockSignals(true);
    if(State == true)           Checkbox_Luz0->setCheckState(Qt::Checked);
    else                        Checkbox_Luz0->setCheckState(Qt::Unchecked);
    Checkbox_Luz0->blockSignals(false);
}
void _window::change_light1_state(bool State){
    Checkbox_Luz1->blockSignals(true);
    if(State == true)           Checkbox_Luz1->setCheckState(Qt::Checked);
    else                        Checkbox_Luz1->setCheckState(Qt::Unchecked);
    Checkbox_Luz1->blockSignals(false);
}

void _window::change_animation_state(bool State) {
    Checkbox_Animation->blockSignals(true);
    if(State == true)           Checkbox_Animation->setCheckState(Qt::Checked);
    else                        Checkbox_Animation->setCheckState(Qt::Unchecked);
    Checkbox_Animation->blockSignals(false);
}

void _window::change_animation_arm_state(bool State) {
    Checkbox_Animation_Arm->blockSignals(true);
    if(State == true)           Checkbox_Animation_Arm->setCheckState(Qt::Checked);
    else                        Checkbox_Animation_Arm->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Arm->blockSignals(false);
}

void _window::change_animation_leg_state(bool State) {
    Checkbox_Animation_Leg->blockSignals(true);
    if(State == true)           Checkbox_Animation_Leg->setCheckState(Qt::Checked);
    else                        Checkbox_Animation_Leg->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Leg->blockSignals(false);
}

void _window::change_animation_body_state(bool State) {
    Checkbox_Animation_Body->blockSignals(true);
    if(State == true)           Checkbox_Animation_Body->setCheckState(Qt::Checked);
    else                        Checkbox_Animation_Body->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Body->blockSignals(false);
}

void _window::change_animation_rotate_antebrazo_state(bool State) {
    Checkbox_Animation_Rotate_Antebrazo->blockSignals(true);
    if(State == true)           Checkbox_Animation_Rotate_Antebrazo->setCheckState(Qt::Checked);
    else                        Checkbox_Animation_Rotate_Antebrazo->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Rotate_Antebrazo->blockSignals(false);
}

void _window::change_animation_scale_antebrazo_state(bool State) {
    Checkbox_Animation_Scale_Antebrazo->blockSignals(true);
    if(State == true)           Checkbox_Animation_Scale_Antebrazo->setCheckState(Qt::Checked);
    else                        Checkbox_Animation_Scale_Antebrazo->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Scale_Antebrazo->blockSignals(false);
}
void _window::change_animation_scale_cabeza_state(bool State) {
    Checkbox_Animation_Scale_Cabeza->blockSignals(true);
    if(State == true)           Checkbox_Animation_Scale_Cabeza->setCheckState(Qt::Checked);
    else                        Checkbox_Animation_Scale_Cabeza->setCheckState(Qt::Unchecked);
    Checkbox_Animation_Scale_Cabeza->blockSignals(false);
}


void _window::change_combobox_objects_state(int index){
    Combobox_objects->blockSignals(true);
    Combobox_objects->setCurrentIndex(index);
    Combobox_objects->blockSignals(false);
}

void _window::change_combobox_relleno_state(int index){
    Combobox_relleno->blockSignals(true);
    Combobox_relleno->setCurrentIndex(index);
    Combobox_relleno->blockSignals(false);
}

void _window::change_combobox_cameras_state(int index){
    Combobox_cameras->blockSignals(true);
    Combobox_cameras->setCurrentIndex(index);
    Combobox_cameras->blockSignals(false);
}

void _window::cambiar_velocidad_rotacion_brazo(float valor){
    Line_edit_arm_speed->setText(QString::number(valor));
}

void _window::cambiar_velocidad_rotacion_piernas(float valor){
    Line_edit_leg_speed->setText(QString::number(valor));
}

void _window::cambiar_velocidad_rotacion_cuerpo(float valor){
    Line_edit_body_speed->setText(QString::number(valor));
}

void _window::cambiar_velocidad_rotacion_antebrazo(float valor){
    Line_edit_rotate_antebrazo_speed->setText(QString::number(valor));
}

void _window::cambiar_velocidad_escalado_antebrazo(float valor){
    Line_edit_scale_antebrazo_speed->setText(QString::number(valor));
}

void _window::cambiar_velocidad_escalado_cabeza(float valor){
    Line_edit_scale_cabeza_speed->setText(QString::number(valor));
}


