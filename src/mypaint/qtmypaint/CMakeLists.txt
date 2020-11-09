#QT += core gui widgets xml
#
#TEMPLATE = lib
#CONFIG += dll warn_on
#
#TARGET = qtmypaint
#

set(QTMYPAINT_HEADERS
    mpbrush.h
    mptile.h
    mpsurface.h
    mphandler.h)

set(QTMYPAINT_SOURCES
    mpbrush.cpp
    mptile.cpp
    mpsurface.cpp
    mphandler.cpp)

add_library(qtmypaint SHARED ${QTMYPAINT_SOURCES})
set_target_properties(qtmypaint PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(qtmypaint tupifwcore mypaint)

install(TARGETS qtmypaint LIBRARY DESTINATION ${TUPITUBE_RASTER})

# what do we do with QTMYPAINT_HEADERS? install them somewhere?
