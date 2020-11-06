#INCLUDEPATH += $$RASTERCOLOR_DIR
#
#unix {
#    LIBS += -L$$RASTERCOLOR_DIR -lrastercolor
#}
#
#win32 {
#    LIBS += -L$$RASTERCOLOR_DIR/release -lrastercolor
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$RASTERCOLOR_DIR/librastercolor.so
#}


#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = rastercolor
#
#CONFIG += dll warn_on
#
#HEADERS += rastercolorwidget.h
#SOURCES += rastercolorwidget.cpp 

set(RASTERCOLOR_SOURCES
    rastercolorwidget.cpp)

add_library(rastercolor SHARED ${RASTERCOLOR_SOURCES})
set_target_properties(rastercolor PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rastercolor tupifwcore tupibase tupicolor)

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
#	STORE_DIR = ../../../store/
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR -ltupistore
#
#    LIBBASE_DIR = ../../../libbase/
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR -ltupibase
#
#    LIBTUPI_DIR = ../../../libtupi/
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR -ltupi
#	
#    !include(../../../../tupiglobal.pri) {
#             error("Run ./configure first!")
#    }
#}
#
#unix:!mac {
#    INSTALLS += target
#    target.path = /lib/raster
#
#    STORE_DIR = ../../../store/
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR -ltupistore
#
#    LIBBASE_DIR = ../../../libbase/
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR -ltupibase
#
#    LIBTUPI_DIR = ../../../libtupi/
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR -ltupi
#	
#    !include(../../../../tupiglobal.pri) {
#             error("Run ./configure first!")
#    }
#}
#
#win32 {
#    include(../../../../win.pri)
#
#	STORE_DIR = ../../../store
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR/release -ltupistore
#
#    LIBBASE_DIR = ../../../libbase
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR/release -ltupibase
#
#    LIBTUPI_DIR = ../../../libtupi
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR/release -ltupi
#}
