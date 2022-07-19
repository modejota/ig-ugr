HEADERS += \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  file_ply_stl.h \
  object3DR.h \
  object3d.h \
  axis.h \
  objectPLY.h \
  objectPLYR.h \
  soporte.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  varilla.h \
  window.h

SOURCES += \
  basic_object3d.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  file_ply_stl.cc \
  object3DR.cc \
  object3d.cc \
  axis.cc \
  objectPLY.cc \
  objectPLYR.cc \
  soporte.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  varilla.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL


CONFIG += c++11
QT += widgets
