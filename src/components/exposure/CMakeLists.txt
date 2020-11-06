#INCLUDEPATH += $$EXPOSURE_DIR
#
#unix {
#    LIBS += -L$$EXPOSURE_DIR -ltupiexposure
#}
#
#win32 {
#    LIBS += -L$$EXPOSURE_DIR/release/ -ltupiexposure
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$EXPOSURE_DIR/libtupiexposure.so
#}

#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupiexposure
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tupexposuresheet.h \
#           tupexposureheader.h \
#           tupexposuretable.h \
#           tupscenetabwidget.h
#

set(TUPIEXPOSURE_SOURCES
    tupexposuresheet.cpp
    tupexposureheader.cpp
    tupexposuretable.cpp
    tupscenetabwidget.cpp)

add_library(tupiexposure SHARED ${TUPIEXPOSURE_SOURCES})
set_target_properties(tupiexposure PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiexposure tupifwcore tupibase)


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
