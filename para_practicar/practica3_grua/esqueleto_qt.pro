HEADERS += \
  agarre.h \
  barra.h \
  barra_gancho.h \
  barra_gancho_completa.h \
  barra_vertical.h \
  base.h \
  cajetilla.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  file_ply_stl.h \
  gancho.h \
  grua.h \
  object3DR.h \
  object3d.h \
  axis.h \
  objectPLY.h \
  objectPLYR.h \
  paletilla.h \
  parte_arriba.h \
  parte_arriba_completa.h \
  pivote.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  union_barras.h \
  window.h

SOURCES += \
  agarre.cc \
  barra.cpp \
  barra_gancho.cc \
  barra_gancho_completa.cc \
  barra_vertical.cc \
  base.cc \
  basic_object3d.cc \
  cajetilla.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  file_ply_stl.cc \
  gancho.cc \
  grua.cc \
  object3DR.cc \
  object3d.cc \
  axis.cc \
  objectPLY.cc \
  objectPLYR.cc \
  paletilla.cc \
  parte_arriba.cc \
  parte_arriba_completa.cc \
  pivote.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  union_barras.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
