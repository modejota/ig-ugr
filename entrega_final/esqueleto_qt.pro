HEADERS += \
  antebrazo.h \
  antebrazo_mano.h \
  arm_bone.h \
  board.h \
  body.h \
  body_with_accessories.h \
  both_Zs.h \
  both_eyes.h \
  brazo_arriba.h \
  chestZ.h \
  colors.h \
  basic_object3d.h \
  cone.h \
  cube.h \
  cylinder.h \
  eye.h \
  file_ply_stl.h \
  foot.h \
  full_arm.h \
  hand.h \
  head.h \
  head_with_face.h \
  joint_arm.h \
  joint_leg.h \
  leg.h \
  lower_limb.h \
  lower_limb_with_joint.h \
  mazinger_z.h \
  object3DR.h \
  object3d.h \
  axis.h \
  objectPLY.h \
  objectPLYR.h \
  octahedron.h \
  otros_objetos.h \
  sphere.h \
  tetrahedron.h \
  glwidget.h \
  upper_limb.h \
  window.h

SOURCES += \
  antebrazo.cc \
  antebrazo_mano.cc \
  arm_bone.cc \
  basic_object3d.cc \
  board.cc \
  body.cc \
  body_with_accessories.cc \
  both_Zs.cc \
  both_eyes.cc \
  brazo_arriba.cc \
  chestZ.cc \
  cone.cc \
  cube.cc \
  cylinder.cc \
  eye.cc \
  file_ply_stl.cc \
  foot.cc \
  full_arm.cc \
  hand.cc \
  head.cc \
  head_with_face.cc \
  joint_arm.cc \
  joint_leg.cc \
  leg.cc \
  lower_limb.cc \
  lower_limb_with_joint.cc \
  mazinger_z.cpp \
  object3DR.cc \
  object3d.cc \
  axis.cc \
  objectPLY.cc \
  objectPLYR.cc \
  octahedron.cc \
  otros_objetos.cc \
  sphere.cc \
  tetrahedron.cc \
  main.cc \
  glwidget.cc \
  upper_limb.cc \
  window.cc


LIBS += -L/usr/X11R6/lib64 -lGL -lGLEW


CONFIG += c++11
QT += widgets
