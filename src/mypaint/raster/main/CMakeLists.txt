#QT += core gui widgets xml
#CONFIG += dll warn_on
#
#TEMPLATE = lib
#TARGET = rastermain
#
#HEADERS += rastercanvasbase.h \
#          rastercanvas.h \
#          rastermainwindow.h
#

set(RASTERMAIN_SOURCES
    rastercanvasbase.cpp
    rastercanvas.cpp
    rastermainwindow.cpp)

add_library(rastermain SHARED ${RASTERMAIN_SOURCES})
set_target_properties(rastermain PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rastermain tupifwcore tupibase qtmypaint rasterbrushes rastercolor)

#INCLUDEPATH += ../../libmypaint
#INCLUDEPATH += ../../qtmypaint
#
#INCLUDEPATH += ../brushes
#LIBS += -L../brushes -lrasterbrushes
#
#INCLUDEPATH += ../color
#LIBS += -L../color -lrastercolor
#
#FRAMEWORK_DIR = "../../../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
#LIBCOLOR_DIR = "../../../libcolor"
#include($$LIBCOLOR_DIR/libcolor.pri)
#
#macx {
#    INSTALLS += target
#    target.path = /lib
#
#    INSTALLS += brushes
#    brushes.target = .
#    brushes.commands = cp -r brushes $(INSTALL_ROOT)/themes/raster
#    brushes.path = /themes/raster/brushes
#
#    INSTALLS += resources
#    resources.target = .
#    resources.commands = cp -r resources $(INSTALL_ROOT)/themes/raster
#    resources.path = /themes/raster/resources
#
#    STORE_DIR = ../../../store
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR/ -ltupistore
#
#    LIBBASE_DIR = ../../../libbase
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR/ -ltupibase
#
#    LIBTUPI_DIR = ../../../libtupi
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR/ -ltupi
#
#    LIBS += -L../../json-c -ljson-c
#    LIBS += -L$$OUT_PWD/../../qtmypaint -lqtmypaint
#
#    !include(../../../../tupiglobal.pri) {
#        error("Run ./configure first!")
#    }
#}
#
#unix:!mac {
#    INSTALLS += target
#    target.path = /lib/raster
#
#    INSTALLS += brushes
#    brushes.target = .
#    brushes.commands = cp -r brushes $(INSTALL_ROOT)/themes/raster
#    brushes.path = /themes/raster/brushes
#
#    INSTALLS += resources
#    resources.target = .
#    resources.commands = cp -r resources $(INSTALL_ROOT)/themes/raster
#    resources.path = /themes/raster/resources
#
#    STORE_DIR = ../../../store
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR/ -ltupistore
#
#    LIBBASE_DIR = ../../../libbase
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR/ -ltupibase
#
#    LIBTUPI_DIR = ../../../libtupi
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR/ -ltupi
#
#    LIBS += -L../../json-c -ljson-c
#    LIBS += -L$$OUT_PWD/../../qtmypaint/ -lqtmypaint
#	
#    !include(../../../../tupiglobal.pri) {
#        error("Run ./configure first!")
#    }
#}
#
#win32 {
#    STORE_DIR = ../../../store
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR/release/ -ltupistore
#
#    LIBBASE_DIR = ../../../libbase
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR/release/ -ltupibase
#
#    LIBTUPI_DIR = ../../../libtupi
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR/release/ -ltupi
#	
#    LIBS += -L../../json-c/release/ -ljson-c
#    LIBS += -L$$OUT_PWD/../../qtmypaint/release/ -lqtmypaint
#
#    INCLUDEPATH += ../brushes
#    LIBS += -L../brushes/release/ -lrasterbrushes
#
#    INCLUDEPATH += ../color
#    LIBS += -L../color/release/ -lrastercolor
#
#    include(../../../../win.pri)
#}
