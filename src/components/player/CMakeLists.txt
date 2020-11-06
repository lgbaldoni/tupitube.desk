#INCLUDEPATH += $$PLAYER_DIR
#
#unix {
#    LIBS += -L$$PLAYER_DIR -ltupiplayer
#}
#
#win32 {
#    LIBS += -L$$PLAYER_DIR/release/ -ltupiplayer
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$PLAYER_DIR/libtupiplayer.so
#}
#


#QT += opengl core gui svg xml network multimedia
#TEMPLATE = lib
#TARGET = tupiplayer
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tupcamerawidget.h \
#           tupcamerabar.h \
#           tupscreen.h \
#           tupcamerastatus.h \
#           tupanimationspace.h \
#           tupinfodialog.h
#

set(TUPIPLAYER_SOURCES
    tupcamerawidget.cpp
    tupcamerabar.cpp
    tupscreen.cpp
    tupcamerastatus.cpp
    tupanimationspace.cpp
    tupinfodialog.cpp)

add_library(tupiplayer SHARED ${TUPIPLAYER_SOURCES})
set_target_properties(tupiplayer PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiplayer tupifwcore tupiexport Qt::Multimedia)

#EXPORT_DIR = ../export
#include($$EXPORT_DIR/export.pri)
#
#FRAMEWORK_DIR = "../../framework"
#include($$FRAMEWORK_DIR/framework.pri)
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
