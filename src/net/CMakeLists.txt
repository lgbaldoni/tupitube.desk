#
#QT += xml network
#
#STORE_DIR = ../../src/store 
#LIBTUPI_DIR = ../../src/libtupi 
#LIBBASE_DIR = ../../src/libbase
#
#include($$STORE_DIR/store.pri)
#include($$LIBTUPI_DIR/libtupi.pri)
#include($$LIBBASE_DIR/libbase.pri)
#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupinet
#
#macx {
#    CONFIG += plugin warn_on
#} else {
#    CONFIG += dll warn_on
#}
#
#unix {
#    !include(../../tupiglobal.pri) {
#        error("Please configure first")
#    }
#}
#
#win32 {
#    include(../../win.pri)
#}
#
#INSTALLS += target
#target.path = /lib/
#
#contains("DEFINES", "ADD_HEADERS") {
#    INSTALLS += headers
#    headers.target = .
#    headers.commands = cp *.h $(INSTALL_ROOT)/include/tupinet
#    headers.path = /include/tupinet/
#}
#
#HEADERS += tupnetprojectmanagerparams.h \
#           tupnetprojectmanagerhandler.h \
#           tupnetsocket.h \
#           tupconnectpackage.h \
#           tuplistpackage.h \
#           tupopenpackage.h \
#           tupsavepackage.h \
#           tupnewprojectpackage.h \
#           tupnetfilemanager.h \
#           tupchat.h \
#           tupconnectdialog.h \
#           tupprojectparser.h \
#           tuplistprojectspackage.h \
#           tupprojectlistparser.h \
#           tuplistprojectdialog.h \
#           tupnotificationparser.h \
#           tupackparser.h \
#           tupimportprojectpackage.h \
#           tupchatpackage.h \
#           tupnotice.h \
#           # tupnoticepackage.h \
#           tupcommunicationparser.h \
#           tupimageexportpackage.h \
#           tupvideoexportpackage.h \
#           tupstoryboardupdatepackage.h \
#           tupstoryboardexportpackage.h \
#           tupstoryboardparser.h
#

set(TUPINET_SOURCES
    tupnetprojectmanagerparams.cpp
    tupnetprojectmanagerhandler.cpp
    tupnetsocket.cpp
    tupconnectpackage.cpp
    tuplistpackage.cpp
    tupopenpackage.cpp
    tupsavepackage.cpp
    tupnewprojectpackage.cpp
    tupnetfilemanager.cpp
    tupchat.cpp
    tupconnectdialog.cpp
    tupprojectparser.cpp
    tuplistprojectspackage.cpp
    tupprojectlistparser.cpp
    tuplistprojectdialog.cpp
    tupnotificationparser.cpp
    tupackparser.cpp
    tupimportprojectpackage.cpp
    tupchatpackage.cpp
    tupnotice.cpp
    # tupnoticepackage.cpp
    tupcommunicationparser.cpp
    tupimageexportpackage.cpp
    tupvideoexportpackage.cpp
    tupstoryboardupdatepackage.cpp
    tupstoryboardexportpackage.cpp
    tupstoryboardparser.cpp)

add_library(tupinet SHARED ${TUPINET_SOURCES})
set_target_properties(tupinet PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupinet tupifwcore tupistore)

#
#include(net_config.pri)
#
#FRAMEWORK_DIR = "../framework"
#include($$FRAMEWORK_DIR/framework.pri)
#
