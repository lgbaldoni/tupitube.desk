#INCLUDEPATH += $$BRUSH_DIR
#
#unix {
#    LIBS += -L$$BRUSH_DIR -ltupibrush
#}
#
#win32 {
#    LIBS += -L$$BRUSH_DIR/release/ -ltupibrush
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$BRUSH_DIR/libtupibrush.so
#}

#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupibrush
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tupbrushwidget.h 
#           # tuppenthicknesswidget.h

set(TUPIBRUSH_SOURCES
    tupbrushwidget.cpp)
    # tuppenthicknesswidget.cpp)

add_library(tupibrush SHARED ${TUPIBRUSH_SOURCES})
set_target_properties(tupibrush PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupibrush tupifwcore tupibase)


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
#	LIBBASE_DIR = ../../libbase/
#    INCLUDEPATH += $$LIBBASE_DIR
#    LIBS += -L$$LIBBASE_DIR/release/ -ltupibase
#
#	LIBTUPI_DIR = ../../libtupi/
#    INCLUDEPATH += $$LIBTUPI_DIR
#    LIBS += -L$$LIBTUPI_DIR/release/ -ltupi 
#}
