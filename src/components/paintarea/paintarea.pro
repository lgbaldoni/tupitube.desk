# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./src/components/paintarea
# Target is a library:  paintarea

INSTALLS += target
target.path = /lib/

macx {
    CONFIG += staticlib warn_on
}

HEADERS += tuppaintarea.h \
           tupconfigurationarea.h \
           tupviewdocument.h \
           # tupdocumentruler.h \
           tuppaintareastatus.h \
           tupimagedevice.h \
           tuppaintareacommand.h \
           tuplibrarydialog.h \
           tupcolorwidget.h \
           tupbrushstatus.h \
           tuptoolstatus.h \
           tupcanvas.h \
           tupcanvasview.h \
           tupimagedialog.h \
           tupstoryboarddialog.h \
           tuppendialog.h \
           tupexposuredialog.h \
           tupexposurescene.h \
           tuptoolsdialog.h \
           tupiruler.h

SOURCES += tuppaintarea.cpp \
           tupconfigurationarea.cpp \
           tupviewdocument.cpp \
           # tupdocumentruler.cpp \
           tuppaintareastatus.cpp \
           tupimagedevice.cpp \
           tuppaintareacommand.cpp \
           tuplibrarydialog.cpp \
           tupcolorwidget.cpp \
           tupbrushstatus.cpp \
           tuptoolstatus.cpp \
           tupcanvas.cpp \
           tupcanvasview.cpp \
           tupimagedialog.cpp \
           tupstoryboarddialog.cpp \
           tuppendialog.cpp \
           tupexposuredialog.cpp \
           tupexposurescene.cpp \
           tuptoolsdialog.cpp \
           tupiruler.cpp

*:!macx{
    CONFIG += dll warn_on
}

TEMPLATE = lib
TARGET = paintarea

PLUGIN_DIR = ../../plugins/export/genericexportplugin
INCLUDEPATH += $$PLUGIN_DIR

SELECTION_DIR = ../../plugins/tools/selecttool
INCLUDEPATH += $$SELECTION_DIR

POLYLINE_DIR = ../../plugins/tools/polylinetool
INCLUDEPATH += $$POLYLINE_DIR

FRAMEWORK_DIR = "../../framework"
include($$FRAMEWORK_DIR/framework.pri)
include(../components_config.pri)
