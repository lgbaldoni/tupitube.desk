#unix {
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR -ltupistore
#}
#
#win32 {
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR/release/ -ltupistore
#}



#
#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupistore
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
#    include(../../quazip.win.pri)
#    include(../../win.pri)
#}
#
#INSTALLS += target
#target.path = /lib/
#
#contains("DEFINES", "ADD_HEADERS") {
#    INSTALLS += headers
#    headers.target = .
#    headers.commands = cp *.h $(INSTALL_ROOT)/include/tupistore
#    headers.path = /include/tupistore/
#}
#
#HEADERS += tuplayer.h \
#           tuppalettedocument.h \
#           tupframe.h \
#           tupprojectrequest.h \
#           tupscene.h \
#           tupproject.h \
#           tupprojectmanager.h \
#           tupprojectcommand.h \
#           tupabstractserializable.h \
#           tupframegroup.h \
#           tuppathitem.h \
#           tuprectitem.h \
#           tuppixmapitem.h \
#           tuptextitem.h \
#           tupbuttonitem.h \
#           tupitemfactory.h \
#           tupellipseitem.h \
#           # tupglobal_store.h \
#           tuppaintareaevent.h \
#           tupserializer.h \
#           tuplineitem.h \
#           tupitemconverter.h \
#           tupitemgroup.h \
#           tupprojectmanagerparams.h \
#           tupabstractprojectmanagerhandler.h \
#           tupcommandexecutor.h \
#           tupgraphicobject.h \
#           tuplibrary.h \
#           tuplibraryobject.h \
#           tuplibraryfolder.h \
#           tuprequestbuilder.h \
#           tuprequestparser.h \
#           tupprojectresponse.h \
#           tupabstractprojectresponsehandler.h \
#           tupfilemanager.h \
#           tupprojectloader.h \
#           tupgraphiclibraryitem.h \
#           tupitemtweener.h \
#           tuptweenerstep.h \
#           tupsoundlayer.h \
#           tupsvgitem.h \
#           tupbackgroundscene.h \
#           tupbackground.h \
#           tupstoryboard.h \
#           tuplipsync.h
#

set(TUPISTORE_SOURCES
    tuplayer.cpp
    tuppalettedocument.cpp
    tupframe.cpp
    tupprojectrequest.cpp
    tupscene.cpp
    tupproject.cpp
    tupprojectmanager.cpp
    tupprojectcommand.cpp
    tupframegroup.cpp
    tuppathitem.cpp
    tuprectitem.cpp
    tuppixmapitem.cpp
    tuptextitem.cpp
    ###tupbuttonitem.cpp
    tupellipseitem.cpp
    tuppaintareaevent.cpp
    tupserializer.cpp
    tuplineitem.cpp
    tupitemconverter.cpp
    tupitemgroup.cpp
    tupprojectmanagerparams.cpp
    tupabstractprojectmanagerhandler.cpp
    tupcommandexecutor.cpp
    tupcommandexecutor_frames.cpp
    tupcommandexecutor_items.cpp
    tupcommandexecutor_layers.cpp
    tupgraphicobject.cpp
    tuplibrary.cpp
    tuplibraryobject.cpp
    tuplibraryfolder.cpp
    tupcommandexecutor_library.cpp
    tuprequestbuilder.cpp
    tuprequestparser.cpp
    tupprojectresponse.cpp
    tupabstractprojectresponsehandler.cpp
    tupitemfactory.cpp
    tupfilemanager.cpp
    tupprojectloader.cpp
    tupgraphiclibraryitem.cpp
    tupitemtweener.cpp
    tuptweenerstep.cpp
    tupsoundlayer.cpp
    tupsvgitem.cpp
    tupbackgroundscene.cpp
    tupbackground.cpp
    tupstoryboard.cpp
    tuplipsync.cpp)

add_library(tupistore SHARED ${TUPISTORE_SOURCES})
set_target_properties(tupistore PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupistore tupifwcore tupi Qt5::Svg)
#STORE_DIR = .
#
#FRAMEWORK_DIR = "../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#LIBTUPI_DIR = ../libtupi
#include($$LIBTUPI_DIR/libtupi.pri)
