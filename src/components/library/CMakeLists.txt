#INCLUDEPATH += $$LIBRARY_DIR
#
#unix {
#    LIBS += -L$$LIBRARY_DIR -ltupilibrary
#}
#
#win32 {
#    LIBS += -L$$LIBRARY_DIR/release/ -ltupilibrary
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$LIBRARY_DIR/libtupilibrary.so
#}


#QT += opengl core gui svg xml network multimedia
#TEMPLATE = lib
#TARGET = tupilibrary
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tuplibrarywidget.h \
#           tupitemmanager.h  \
#           tupsymboleditor.h \
#           tuptreedelegate.h \
#           tupnewitemdialog.h \
#           tuplibrarydisplay.h \
#           tupsoundplayer.h
#

set(TUPILIBRARY_SOURCES
    tuplibrarywidget.cpp
    tupitemmanager.cpp
    tupsymboleditor.cpp
    tuptreedelegate.cpp
    tupnewitemdialog.cpp
    tuplibrarydisplay.cpp
    tupsoundplayer.cpp)

add_library(tupilibrary SHARED ${TUPILIBRARY_SOURCES})
set_target_properties(tupilibrary PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupilibrary tupifwcore tupifwgui tupi tupibase Qt5::Multimedia)

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
