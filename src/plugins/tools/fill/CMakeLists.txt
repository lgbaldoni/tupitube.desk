#QT += opengl core gui svg xml network
#CONFIG += plugin warn_on
#TEMPLATE = lib
#TARGET = tupifilltool
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
#target.path = /plugins/
#
#HEADERS += filltool.h 
#
#SOURCES += filltool.cpp

set(TUPIFILLTOOL_SOURCES
    filltool.cpp)

add_library(tupifilltool MODULE ${TUPIFILLTOOL_SOURCES})
target_link_libraries(tupifilltool tupifwcore tupibase)

#
#FRAMEWORK_DIR = "../../../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
#LIBBASE_DIR = ../../../libbase
#STORE_DIR = ../../../store
#LIBTUPI_DIR = ../../../libtupi
#COMMON_DIR = ../common
#
#include($$LIBBASE_DIR/libbase.pri)	
#include($$STORE_DIR/store.pri)
#include($$LIBTUPI_DIR/libtupi.pri)
#include($$COMMON_DIR/common.pri)
