#STORE_DIR = ../../../../src/store
#LIBTUPI_DIR = ../../../../src/libtupi
#LIBBASE_DIR = ../../../../src/libbase
#
#include($$STORE_DIR/store.pri)
#include($$LIBTUPI_DIR/libtupi.pri)
#include($$LIBBASE_DIR/libbase.pri)


#INCLUDEPATH += $$COMMON_DIR
#
#unix {
#    LIBS += -L$$COMMON_DIR -ltupiplugincommon
#}
#
#win32 {
#    LIBS += -L$$COMMON_DIR/release/ -ltupiplugincommon
#}

#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupiplugincommon
#
#CONFIG += dll warn_on
#
#unix {
#    !include(../../../../tupiglobal.pri){
#        error("Please run configure first")
#    }
#}
#
#win32 {
#    include(../../../../win.pri)
#}
#
#INSTALLS += target 
#target.path = /lib/ 
#
##headers.target = .
##headers.commands = cp *.h $(INSTALL_ROOT)/include/plugincommon
##headers.path = /include/plugincommon
#
#HEADERS += buttonspanel.h \
#           tweenmanager.h \
#           stepsviewer.h \
#           # spinboxdelegate.h \
#           target.h
#

set(TUPIPLUGINCOMMON_SOURCES
    buttonspanel.cpp
    tweenmanager.cpp
    stepsviewer.cpp)
    # spinboxdelegate.cpp
###    target.cpp)

add_library(tupiplugincommon SHARED ${TUPIPLUGINCOMMON_SOURCES})
set_target_properties(tupiplugincommon PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiplugincommon tupifwcore tupifwgui tupistore)

#FRAMEWORK_DIR = "../../../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
#STORE_DIR = ../../../store
#LIBTUPI_DIR = ../../../libtupi
#LIBBASE_DIR = ../../../libbase
#
#include($$STORE_DIR/store.pri)
#include($$LIBTUPI_DIR/libtupi.pri)
#include($$LIBBASE_DIR/libbase.pri)
