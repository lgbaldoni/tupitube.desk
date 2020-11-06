#INCLUDEPATH += $$LIBCOLOR_DIR
#
#unix {
#    LIBS += -L$$LIBCOLOR_DIR -ltupicolor
#}
#
#win32 {
#    LIBS += -L$$LIBCOLOR_DIR/release -ltupicolor
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$LIBCOLOR_DIR/libtupicolor.so
#}
#
#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupicolor
#
#INSTALLS += tpal 
#
#tpal.target = palettes/*.tpal
#tpal.commands = test -d $(INSTALL_ROOT)/data/palettes/ || mkdir $(INSTALL_ROOT)/data/palettes; \
#                cp palettes/*.tpal $(INSTALL_ROOT)/data/palettes/
#tpal.path = /data/palettes/
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tupcolorpicker.h \
#           tupviewcolorcells.h \
#           tupcellscolor.h \
#           tuppaletteparser.h \
#           tupformitem.h \
#           tupcolorform.h \
#           tupcolorbutton.h \
#           tupcolorbuttonpanel.h
#

set(TUPICOLOR_SOURCES
    tupcolorpicker.cpp
    tupviewcolorcells.cpp
    tupcellscolor.cpp
    tuppaletteparser.cpp
    tupformitem.cpp
    tupcolorform.cpp
    tupcolorbutton.cpp
    tupcolorbuttonpanel.cpp)

add_library(tupicolor SHARED ${TUPICOLOR_SOURCES})
set_target_properties(tupicolor PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupicolor tupifwcore tupifwgui tupistore)

#FRAMEWORK_DIR = "../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
#unix {
#    STORE_DIR = ../store/
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR -ltupistore
#
#    LIBBASE_DIR = ../libbase/
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR -ltupibase
#
#    LIBTUPI_DIR = ../libtupi/
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR -ltupi
#
#    !include(../../tupiglobal.pri) {
#             error("libcolor: Run ./configure first!")
#    }
#}
#
#win32 {
#    include(../../win.pri)
#
#    STORE_DIR = ../store/
#    INCLUDEPATH += $$STORE_DIR
#    LIBS += -L$$STORE_DIR/release/ -ltupistore
#
#    LIBBASE_DIR = ../libbase/
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR/release/ -ltupibase
#
#    LIBTUPI_DIR = ../libtupi/
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR/release/ -ltupi 
#}
