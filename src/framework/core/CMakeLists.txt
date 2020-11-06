#QT += opengl core gui svg xml network
#TEMPLATE = lib
#TARGET = tupifwcore
#
#macx {
#    CONFIG += plugin warn_on
#} else {
#    CONFIG += warn_on dll
#}
#
#unix {
#    !include(../tupconfig.pri) {
#        error("Run ./configure first!")
#    }
#}
#
#win32 {
#    include(../../../win.pri)
#}
#
#INSTALLS += target
#target.path = /lib/
#
#contains("DEFINES", "ADD_HEADERS") {
#    INSTALLS += headers 
#    headers.files += *.h
#    headers.path = /include/tupicore
#}
#
#HEADERS += talgorithm.h \
#           tapplicationproperties.h \
#           tconfig.h \
#           tglobal.h \
#           tipdatabase.h \
#           tcachehandler.h \
#           txmlparserbase.h
#
#SOURCES += talgorithm.cpp \
#           tapplicationproperties.cpp \
#           tconfig.cpp \
#           tipdatabase.cpp \
#           tcachehandler.cpp \
#           txmlparserbase.cpp
#

# perhaps this stuff goes at upper levels
#    config.addDefine('TUPITUBE_VERSION=\\\\\"0.2\\\\\"')
#    config.addDefine('CODE_NAME=\\\\\"Gambá\\\\\"')
#    config.addDefine('REVISION=\\\\\"16\\\\\"')
#    config.addDefine('CONFIG_VERSION=\\\\\"3\\\\\"')

# now in the top CMakeLists.txt, see if proper 
# removed escapes, find out why they were needed in qmake
###add_definitions(-DCONFIG_VERSION=3)

set(TUPIFWCORE_SOURCES
     talgorithm.cpp
     tapplicationproperties.cpp
     tconfig.cpp
     tipdatabase.cpp
     tcachehandler.cpp
     txmlparserbase.cpp)

#unix {
#    contains(DEFINES, TUP_DEBUG) {
#        HEADERS += tdebug.h
#        SOURCES += tdebug.cpp
#    }
#}

#add the definition check and unix
#ifF(CMAKE_SYSTEM_NAME STREQUAL Linux)
if(UNIX)
if(NOT ${DISABLE_DEBUG})
list(APPEND TUPIFWCORE_SOURCES tdebug.cpp)
endif()
endif()

# find out if it has to be forced shared or something
#add_library(tupifwcore ${TUPIFWCORE_SOURCES})
add_library(tupifwcore SHARED ${TUPIFWCORE_SOURCES})

set_property(TARGET tupifwcore PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(tupifwcore PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})


target_link_libraries(tupifwcore Qt5::Gui Qt5::Widgets Qt5::Xml)
