HEADERS += \
  base.h \
  caja.h \
  camara_completa.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cuerpo_camara.h \
  cylinder.h \
  file_ply_stl.h \
  lente.h \
  object3DR.h \
  object3d.h \
  axis.h \
  objectPLY.h \
  objectPLYR.h \
  pie_camara.h \
  plataformaTV.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  window.h

SOURCES += \
  base.cc \
  basic_object3d.cc \
  caja.cc \
  camara_completa.cc \
  cone.cc \
  cube.cc \
  cuerpo_camara.cc \
  cylinder.cc \
  file_ply_stl.cc \
  lente.cc \
  object3DR.cc \
  object3d.cc \
  axis.cc \
  objectPLY.cc \
  objectPLYR.cc \
  pie_camara.cc \
  plataformaTV.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
