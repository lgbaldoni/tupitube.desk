#INCLUDEPATH += $$TWITTER_DIR
#
#unix {
#    LIBS += -L$$TWITTER_DIR -ltupitwitter
#}
#
#win32 {
#    LIBS += -L$$TWITTER_DIR/release/ -ltupitwitter
#}
#
#linux-g++ {
#    PRE_TARGETDEPS += $$TWITTER_DIR/libtupitwitter.so
#}
#

#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupitwitter
#
#INSTALLS += target
#target.path = /lib/
#
#CONFIG += dll warn_on
#
#HEADERS += tuptwitter.h \  
#           tuptwitterwidget.h
#
#SOURCES += tuptwitter.cpp \
#           tuptwitterwidget.cpp
#		   

set(TUPITWITTER_SOURCES
    tuptwitter.cpp
    tuptwitterwidget.cpp)

add_library(tupitwitter SHARED ${TUPITWITTER_SOURCES})
set_target_properties(tupitwitter PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupitwitter tupifwcore Qt::Network)


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
