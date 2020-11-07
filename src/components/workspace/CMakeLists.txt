#INCLUDEPATH += /usr/include/qt5/QtMultimedia /usr/include/qt5/QtMultimediaWidgets
#INCLUDEPATH += $$WORKSPACE_DIR 
#
#unix {
#    LIBS += -L$$WORKSPACE_DIR -ltupiworkspace
#}
#
#win32 {
#    LIBS += -L$$WORKSPACE_DIR/release/ -ltupiworkspace
#}
#
#linux-g++ {
#PRE_TARGETDEPS += $$WORKSPACE_DIR/libtupiworkspace.so
#}
#

#QT += opengl core gui svg xml network
#QT += multimedia multimediawidgets printsupport
#TEMPLATE = lib
#TARGET = tupiworkspace
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tuppaintarea.h \
#           tupconfigurationarea.h \
#           tupdocumentview.h \
#           tupimagedevice.h \
#           tuppaintareacommand.h \
#           tuplibrarydialog.h \
#           tupcanvas.h \
#           tupcanvasview.h \
#           tupimagedialog.h \
#           tupstoryboarddialog.h \
#           tuppendialog.h \
#           tuponiondialog.h \
#           # tupinfowidget.h \
#           tupruler.h \
#           tupcamerainterface.h \
#           tupreflexinterface.h \
#           tupbasiccamerainterface.h \
#           tupcameradialog.h \
#           tupcamerawindow.h \
#           tupvideosurface.h \
#           tuppapagayoimporter.h \
#           tuppapagayodialog.h \
#           tupreflexrenderarea.h \
#           tupmodesitem.h \
#           tupmodessettingsdialog.h \
#           tupmodeslist.h
#

# tupdocumentview.cpp moc troubles
set(TUPIWORKSPACE_SOURCES
    tuppaintarea.cpp
    tupconfigurationarea.cpp
    tupdocumentview.cpp
    tupimagedevice.cpp
    tuppaintareacommand.cpp
    tuplibrarydialog.cpp
    tupcanvas.cpp
    tupcanvasview.cpp
    tupimagedialog.cpp
    tupstoryboarddialog.cpp
    tuppendialog.cpp
    tuponiondialog.cpp
    # tupinfowidget.cpp
    tupruler.cpp
    tupcamerainterface.cpp
    tupreflexinterface.cpp
    tupbasiccamerainterface.cpp
    tupcameradialog.cpp
    tupcamerawindow.cpp
    tupvideosurface.cpp
    tuppapagayoimporter.cpp
    tuppapagayodialog.cpp
    tupreflexrenderarea.cpp
    tupmodesitem.cpp
    tupmodessettingsdialog.cpp
    tupmodeslist.cpp)

### temporary?
set(SHELL_INCLUDE_DIR ../../shell)
set(SELECTION_INCLUDE_DIR ../../plugins/tools/selection)
set(POLYLINETOOL_INCLUDE_DIR ../../plugins/tools/polyline)
###

add_library(tupiworkspace SHARED ${TUPIWORKSPACE_SOURCES})
set_target_properties(tupiworkspace PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(tupiworkspace PUBLIC ${SHELL_INCLUDE_DIR} ${SELECTION_INCLUDE_DIR} ${POLYLINETOOL_INCLUDE_DIR})
target_link_libraries(tupiworkspace tupifwcore tupifwgui tupi tupibase rastermain
   Qt5::Multimedia Qt5::MultimediaWidgets Qt5::PrintSupport)



#
#SHELL_DIR = ../../shell/
#INCLUDEPATH += $$SHELL_DIR
#
#PLUGIN_DIR = ../../plugins/export/genericexportplugin
#INCLUDEPATH += $$PLUGIN_DIR
#
#SELECTION_DIR = ../../plugins/tools/selection
#INCLUDEPATH += $$SELECTION_DIR
#
#POLYLINE_DIR = ../../plugins/tools/polyline
#INCLUDEPATH += $$POLYLINE_DIR
#
#FRAMEWORK_DIR = "../../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
#LIBCOLOR_DIR = "../../libcolor"
#include($$LIBCOLOR_DIR/libcolor.pri)
#
#MYPAINT_DIR = "../../mypaint"
#include($$MYPAINT_DIR/mypaint.pri)
#
#unix {
#    INCLUDEPATH += /usr/include/qt5/QtMultimedia /usr/include/qt5/QtMultimediaWidgets
#
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
