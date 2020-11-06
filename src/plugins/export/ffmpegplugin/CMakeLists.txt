#QT += opengl core gui svg xml network
#CONFIG += plugin warn_on
#TEMPLATE = lib
#TARGET = tupiffmpegplugin
#
#unix {
#    !include(../../../../tupiglobal.pri) {
#        error("Please run configure first")
#    }
#}
#
#INSTALLS += target
#target.path = /plugins/
#
#contains("DEFINES", "ADD_HEADERS") {
#    INSTALLS += headers
#    headers.target = .
#    headers.commands = /bin/cp *.h $(INSTALL_ROOT)/include/tupiffmpeg
#    headers.path = /include/tupiffmpeg
#}
#
#win32 {
#    include(../../../../win.pri)
#    include(../../../../ffmpeg.win.pri)
#}
#
#mac {
#    LIBS += -lavutil
#}
#
#HEADERS += tffmpegmoviegenerator.h \
#           ffmpegplugin.h
#
#SOURCES += tffmpegmoviegenerator.cpp \
#           ffmpegplugin.cpp
#

set(TUPIFFMPEGPLUGIN_SOURCES
    tffmpegmoviegenerator.cpp
    ffmpegplugin.cpp)

add_library(tupiffmpegplugin MODULE ${TUPIFFMPEGPLUGIN_SOURCES})
target_include_directories(tupiffmpegplugin PUBLIC ${FFMPEG_INCLUDE_DIRS})
target_link_libraries(tupiffmpegplugin tupifwcore tupibase ${FFMPEG_LIBRARIES})
# unsure about the link to FFMPEG_LIBRARIES, it appears to be automated, but
# I'm going to leave it there for good measure

#FRAMEWORK_DIR = "../../../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
#LIBBASE_DIR = ../../../libbase
#STORE_DIR = ../../../store
#LIBTUPI_DIR = ../../../libtupi
#
#include($$LIBBASE_DIR/libbase.pri)
#include($$STORE_DIR/store.pri)
#include($$LIBTUPI_DIR/libtupi.pri)
#
