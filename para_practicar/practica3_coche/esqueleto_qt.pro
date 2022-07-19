HEADERS += \
  chasis_abajo.h \
  chasis_arriba.h \
  chasis_completo.h \
  coche.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  eje_ruedas.h \
  faro.h \
  faros.h \
  file_ply_stl.h \
  object3DR.h \
  object3d.h \
  axis.h \
  objectPLY.h \
  objectPLYR.h \
  rueda.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  chasis_abajo.cc \
  chasis_arriba.cc \
  chasis_completo.cc \
  coche.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  eje_ruedas.cc \
  faro.cc \
  faros.cc \
  file_ply_stl.cc \
  object3DR.cc \
  object3d.cc \
  axis.cc \
  objectPLY.cc \
  objectPLYR.cc \
  rueda.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
