#QT += xml opengl svg
#
#INCLUDEPATH += ../plugins/tools/selection
#
#MYPAINT_DIR = ../mypaint
#LIBCOLOR_DIR = ../libcolor
#COLORPALETTE_DIR = ../components/colorpalette
#PLAYER_DIR = ../components/player
#WORKSPACE_DIR = ../components/workspace
#BRUSH_DIR = ../components/brush
## KINAS_DIR = ../components/kinas 
#IMPORT_DIR = ../components/import 
#EXPORT_DIR = ../components/export 
#EXPOSURE_DIR = ../components/exposure 
#TIMELINE_DIR = ../components/timeline 
#LIBRARY_DIR = ../components/library
#SCENES_DIR = ../components/scenes 
#TWITTER_DIR = ../components/twitter
#LIBUI_DIR = ../libui
#STORE_DIR = ../store 
#LIBTUPI_DIR = ../libtupi
#LIBBASE_DIR = ../libbase
#NET_DIR = ../net
#
#include($$MYPAINT_DIR/mypaint.pri)
#include($$LIBCOLOR_DIR/libcolor.pri)
#include($$COLORPALETTE_DIR/colorpalette.pri)
#include($$WORKSPACE_DIR/workspace.pri)
#include($$PLAYER_DIR/player.pri)
#include($$BRUSH_DIR/brush.pri)
## include($$KINAS_DIR/kinas.pri)
#include($$IMPORT_DIR/import.pri)
#include($$EXPORT_DIR/export.pri)
#include($$EXPOSURE_DIR/exposure.pri)
#include($$TIMELINE_DIR/timeline.pri)
#include($$LIBRARY_DIR/library.pri)
#include($$SCENES_DIR/scenes.pri)
#include($$TWITTER_DIR/twitter.pri)
#include($$LIBUI_DIR/libui.pri)
#include($$STORE_DIR/store.pri)
#include($$LIBTUPI_DIR/libtupi.pri)
#include($$LIBBASE_DIR/libbase.pri)
#include($$NET_DIR/net.pri)



#QT += opengl core gui svg xml network
#QT += multimedia multimediawidgets printsupport
#QT += widgets
#CONFIG += warn_on
#TEMPLATE = app
#
#macx {
#    CONFIG += console static
#    ICON = ../../launcher/icons/tupitube.desk.icns
#    QMAKE_INFO_PLIST = ./Info.plist
#    QMAKE_LFLAGS += -Wl,-rpath,@loader_path/../,-rpath,@executable_path/../,-rpath,@executable_path/../Frameworks
#    TARGET = ../../bin/TupiTube
#
#    INSTALLS += icons \
#                target \
#                tupidata \
#                html
#
#    icons.target = ../../launcher/icons/tupitube.desk.png
#    icons.commands = cp ../../launcher/icons/tupitube.desk.png $(INSTALL_ROOT)/pixmaps
#    icons.path = /pixmaps/
#
#    target.path = /bin/
#
#    tupidata.target = data
#    tupidata.commands = cp -r data/* $(INSTALL_ROOT)/data
#    tupidata.path = /data/
#
#    html.target = html
#    html.files = html
#    html.commands = cp -r html $(INSTALL_ROOT)/share/tupitube/data
#    html.path = /data/
#}
#
#unix:!mac {
#    INSTALLS += tupidata \
#                launcher \
#                mime \
#                target \
#                desktop \
#                icons \
#                html \
#                copyright
#
#    tupidata.target = data
#    tupidata.commands = cp -r data/* $(INSTALL_ROOT)/data
#    tupidata.path = /data/
#
#    launcher.target = ../../launcher/tupitube.desk
#    launcher.commands = cp ../../launcher/tupitube.desk $(INSTALL_ROOT)/bin; chmod 755 $(INSTALL_ROOT)/bin/tupitube.desk
#    launcher.path = /bin/
#
#    mime.target = ../../launcher/tupitube.xml
#    mime.commands = cp ../../launcher/tupitube.xml $(INSTALL_ROOT)/share/mime/packages
#    mime.path = /share/mime/packages/
#
#    desktop.target = ../../launcher/tupitube.desktop
#    desktop.commands = cp ../../launcher/tupitube.desktop $(INSTALL_ROOT)/applications
#    desktop.path = /applications/
#
#    icons.target = ../../launcher/icons/tupitube.desk.png
#    icons.commands = cp ../../launcher/icons/tupitube.desk.png $(INSTALL_ROOT)/pixmaps
#    icons.path = /pixmaps/
#
#    html.target = html 
#    html.files = html 
#    html.commands = cp -r html $(INSTALL_ROOT)/share/tupitube/data
#    html.path = /data/
#
#    copyright.target = man/copyright
#    copyright.commands = cp man/copyright $(INSTALL_ROOT)/share/doc/tupitube
#    copyright.path = /tupitube/
#
#    target.path = /bin/
#    TARGET = ../../bin/tupitube.bin
#}
#
#HEADERS += tupsigndialog.h \
#           tupstatusbar.h \
#           tupnewproject.h \
#           tupapplication.h \
#           tuplocalprojectmanagerhandler.h \
#           tupmainwindow.h
#

### check again if things can be done this way
###set(SHELL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#SOURCES += tupsigndialog.cpp \
#           tupstatusbar.cpp \
#           tupnewproject.cpp \
#           tupapplication.cpp \
#           tuplocalprojectmanagerhandler.cpp \
#           tupmainwindow.cpp \
#           tupmainwindow_gui.cpp \
#           main.cpp
#

set(SHELL_SOURCES
    tupsigndialog.cpp
    tupstatusbar.cpp
    tupnewproject.cpp
    tupapplication.cpp
    tuplocalprojectmanagerhandler.cpp
    tupmainwindow.cpp
    tupmainwindow_gui.cpp
    main.cpp)

if(UNIX)
list(APPEND SHELL_SOURCES
     tupcrashhandler.cpp
     tupcrashwidget.cpp)
endif()

add_executable(tupitube.desk ${SHELL_SOURCES})
target_link_libraries(tupitube.desk tupifwgui tupistore tupiworkspace tupiplayer
   tupigui tupiexposure tupibrush tupicolorpalette tupiscenes tupilibrary
   tupitimeline tupitwitter tupinet tupimport)

#unix {
#    HEADERS += tupcrashhandler.h \
#               tupcrashwidget.h
#}
#		   		   
#FRAMEWORK_DIR = ../framework
#include($$FRAMEWORK_DIR/framework.pri)
#
#unix {
#    !include(../../tupiglobal.pri) {
#        error("Please run configure first")
#    }
#}
#
#win32 {
#    TARGET = tupitube.desk
#	RC_ICONS = ../../tools/windows/tupitube.ico
#    include(../../win.pri)
#    include(../../quazip.win.pri)
#}
#
#include(shell_config.pri)
