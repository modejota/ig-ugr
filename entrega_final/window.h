/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QComboBox>
#include <QMessageBox>
#include <QGuiApplication>


class _gl_widget;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _window : public QMainWindow
{
    Q_OBJECT

public:
    _window();

    void change_points_state(bool State);
    void change_lines_state(bool State);
    void change_fill_state(bool State);

    void change_light0_state(bool State);
    void change_light1_state(bool State);

    void change_animation_state(bool State);
    void change_animation_arm_state(bool State);
    void change_animation_leg_state(bool State);
    void change_animation_body_state(bool State);
    void change_animation_scale_antebrazo_state(bool State);
    void change_animation_rotate_antebrazo_state(bool State);
    void change_animation_scale_cabeza_state(bool State);

    void change_combobox_objects_state(int index);
    void change_combobox_relleno_state(int index);
    void change_combobox_cameras_state(int index);

    void cambiar_velocidad_rotacion_brazo(float valor);
    void cambiar_velocidad_rotacion_antebrazo(float valor);
    void cambiar_velocidad_escalado_antebrazo(float valor);
    void cambiar_velocidad_rotacion_cuerpo(float valor);
    void cambiar_velocidad_rotacion_piernas(float valor);
    void cambiar_velocidad_escalado_cabeza(float valor);

private:
  _gl_widget *GL_widget;
  QCheckBox *Checkbox_Points = nullptr;
  QCheckBox *Checkbox_Lines  = nullptr;
  QCheckBox *Checkbox_Fill   = nullptr;

  QCheckBox *Checkbox_Luz0 = nullptr;
  QCheckBox *Checkbox_Luz1 = nullptr;

  QCheckBox *Checkbox_Animation = nullptr;
  QCheckBox *Checkbox_Animation_Arm = nullptr;
  QCheckBox *Checkbox_Animation_Leg = nullptr;
  QCheckBox *Checkbox_Animation_Body = nullptr;
  QCheckBox *Checkbox_Animation_Rotate_Antebrazo = nullptr;
  QCheckBox *Checkbox_Animation_Scale_Antebrazo = nullptr;
  QCheckBox *Checkbox_Animation_Scale_Cabeza = nullptr;

  QComboBox *Combobox_objects = nullptr;
  QComboBox *Combobox_relleno = nullptr;
  QComboBox *Combobox_cameras = nullptr;

  QLineEdit *Line_edit_arm_speed = nullptr;
  QLineEdit *Line_edit_leg_speed = nullptr;
  QLineEdit *Line_edit_body_speed = nullptr;
  QLineEdit *Line_edit_scale_antebrazo_speed = nullptr;
  QLineEdit *Line_edit_rotate_antebrazo_speed = nullptr;
  QLineEdit *Line_edit_scale_cabeza_speed = nullptr;

};

#endif
