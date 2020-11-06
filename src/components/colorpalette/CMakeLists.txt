#INCLUDEPATH += $$COLORPALETTE_DIR
#
#unix {
#    LIBS += -L$$COLORPALETTE_DIR -ltupicolorpalette
#}
#
#win32 {
#    LIBS += -L$$COLORPALETTE_DIR/release -ltupicolorpalette
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$COLORPALETTE_DIR/libtupicolorpalette.so
#}
#
#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupicolorpalette
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tupcolorpalettewidget.h
#

set(TUPICOLORPALETTE_SOURCES
    tupcolorpalettewidget.cpp)
add_library(tupicolorpalette SHARED ${TUPICOLORPALETTE_SOURCES})
set_target_properties(tupicolorpalette PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupicolorpalette tupifwcore tupibase tupicolor)

#
#FRAMEWORK_DIR = "../../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
#LIBCOLOR_DIR = "../../libcolor"
#include($$LIBCOLOR_DIR/libcolor.pri)
#
#unix {
#    STORE_DIR = ../../store/
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR -ltupistore
#
#    LIBBASE_DIR = ../../libbase/
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR -ltupibase
#
#    LIBTUPI_DIR = ../../libtupi/
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR -ltupi
#
#    !include(../../../tupiglobal.pri) {
#             error("Run ./configure first!")
#    }
#}
#
#win32 {
#    include(../../../win.pri)
#
#    STORE_DIR = ../../store/
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR/release/ -ltupistore
#
#    LIBBASE_DIR = ../../libbase/
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR/release/ -ltupibase
#
#    LIBTUPI_DIR = ../../libtupi/
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR/release/ -ltupi 
#}
