# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/plugins/tools/filltool
# Target is a library:  

INSTALLS += target 
target.path = /plugins/ 

HEADERS += filltool.h  \
           cliphelper.h \
           qbezier_p.h \
           qmath_p.h \
           qnumeric.h \
           qnumeric_p.h \
           qpathclipper_p.h
SOURCES += filltool.cpp  \
           cliphelper.cpp \
           qbezier.cpp \
           qnumeric.cpp \
           qpathclipper.cpp

CONFIG += plugin warn_on
TEMPLATE = lib
TARGET = filltool

FRAMEWORK_DIR = "../../../framework"
include($$FRAMEWORK_DIR/framework.pri)
include(../tools_config.pri)

include(../../../../tupiglobal.pri)


