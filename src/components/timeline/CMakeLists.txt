#INCLUDEPATH += $$TIMELINE_DIR
#
#unix {
#    LIBS += -L$$TIMELINE_DIR -ltupitimeline
#}
#
#win32 {
#    LIBS += -L$$TIMELINE_DIR\release -ltupitimeline
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$TIMELINE_DIR/libtupitimeline.so
#}

#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupitimeline
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tuptimeline.h \
#           tuptimelineruler.h \
#           tuptimelinetable.h \ 
#           tupscenecontainer.h \
#           # tuplayerindex.h \
#           tuptimelineheader.h
#

set(TUPITIMELINE_SOURCES
    tuptimeline.cpp
    tuptimelineruler.cpp
    tuptimelinetable.cpp
    tupscenecontainer.cpp
    # tuplayerindex.cpp
    tuptimelineheader.cpp)

add_library(tupitimeline SHARED ${TUPITIMELINE_SOURCES})
set_target_properties(tupitimeline PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupitimeline tupifwcore tupi tupibase)


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
