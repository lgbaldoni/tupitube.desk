#TEMPLATE = lib
#TARGET = tupifwsound
#
#macx {
#    CONFIG += plugin warn_on
#} else {
#    CONFIG += warn_on dll
#}
#
#!include(../tupconfig.pri) {
#    error("Run ./configure first")
#}
#
#INSTALLS += target
#target.path = /lib/
#
#contains("DEFINES", "ADD_HEADERS") {
#    INSTALLS += headers 
#    headers.files += *.h
#    headers.path = /include/tupisound
#}
#
#HEADERS += taudioengineiface.h \
#           taudioplayer.h
#SOURCES += taudioplayer.cpp

set(TUPIFWSOUND_SOURCES taudioplayer.cpp)

add_library(tupifwsound SHARED ${TUPIFWSOUND_SOURCES})
set_target_properties(tupifwsound PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR})
target_link_libraries(tupifwsound tupifwcore)
#
#INCLUDEPATH += ../core ../
#LIBS += -L../core -ltupifwcore
#
#linux-g{
#    TARGETDEPS += ../core/libtupifwcore.so
#}
