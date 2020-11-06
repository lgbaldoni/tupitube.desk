#unix {
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR -ltupibase
#}
#
#win32 {
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR/release/ -ltupibase
#}#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupibase


#
#macx {
#    CONFIG += plugin warn_on
#} else {
#    CONFIG += dll warn_on
#}
#
#unix { 
#    !include(../../tupiglobal.pri) {
#        error("Please configure first")
#    }
#}
#
#win32 {
#    # LIBS += -llibEGL -llibGLESv2 -lgdi32 -luser32
#    LIBS += -lgdi32 -luser32
#    include(../../win.pri)
#}
#
#INSTALLS += target 
#target.path = /lib
#
#contains("DEFINES", "ADD_HEADERS") {
#    INSTALLS += headers 
#    headers.commands = cp *.h $(INSTALL_ROOT)/include/tupibase
#    headers.path = /include/tupibase
#}
#
#HEADERS += tupexportinterface.h \
#           tupexportpluginobject.h \
#           tupfilterinterface.h \
#           tupmodulewidgetbase.h \
#           tuppluginmanager.h \
#           tuptoolinterface.h \
#           tuptoolplugin.h  \
#           tuppaintareabase.h \
#           # tuppaintarearotator.h \
#           tupgraphicsscene.h \
#           tupguideline.h \
#           tupanimationrenderer.h \
#           # tupwebhunter.h \
#           tuprotationdial.h \
#           tupsecurity.h \
#           tupwatermark.h
#

set(TUPIBASE_SOURCES
    tupexportpluginobject.cpp
    tupmodulewidgetbase.cpp
    tuppluginmanager.cpp
    tuptoolplugin.cpp
    tuppaintareabase.cpp
    # tuppaintarearotator.cpp
    tupgraphicsscene.cpp
    tupguideline.cpp
    tupanimationrenderer.cpp
    # tupwebhunter.cpp
    tuprotationdial.cpp
    tupsecurity.cpp
    tupwatermark.cpp)

add_library(tupibase SHARED ${TUPIBASE_SOURCES})
set_target_properties(tupibase PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupibase tupifwcore tupistore)

#FRAMEWORK_DIR = "../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#LIBTUPI_DIR = ../libtupi
#include($$LIBTUPI_DIR/libtupi.pri)
#STORE_DIR = ../store
#include($$STORE_DIR/store.pri)
