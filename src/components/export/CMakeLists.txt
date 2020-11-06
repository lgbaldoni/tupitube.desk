#INCLUDEPATH += $$EXPORT_DIR
#
#unix {
#    LIBS += -L$$EXPORT_DIR -ltupiexport
#}
#
#win32 {
#    LIBS += -L$$EXPORT_DIR/release/ -ltupiexport
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$EXPORT_DIR/libtupiexport.so
#}

#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupiexport
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tupexportwizard.h \
#           tuppluginselector.h \
#           tupsceneselector.h \
#           tupexportmodule.h \
#           tupvideoproperties.h \
#           tupexportwidget.h 
#

set(TUPIEXPORT_SOURCES
    tupexportwizard.cpp
    tuppluginselector.cpp
    tupsceneselector.cpp
    tupexportmodule.cpp
    tupvideoproperties.cpp
    tupexportwidget.cpp)

add_library(tupiexport SHARED ${TUPIEXPORT_SOURCES})
set_target_properties(tupiexport PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiexport tupifwcore tupibase)

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
