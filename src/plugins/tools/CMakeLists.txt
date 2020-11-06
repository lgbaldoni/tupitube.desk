#STORE_DIR = ../../store
#LIBTUPI_DIR = ../../libtupi
#LIBBASE_DIR = ../../libbase
#COMMON_DIR = ../../plugins/tools/common
#
#include($$STORE_DIR/store.pri)
#include($$LIBTUPI_DIR/libtupi.pri)
#include($$LIBBASE_DIR/libbase.pri)
#include($$COMMON_DIR/common.pri)

#CONFIG += ordered warn_on

add_subdirectory(common)
add_subdirectory(pencil)
add_subdirectory(ink)
#add_subdirectory(# scheme)
add_subdirectory(selection)
add_subdirectory(nodes)
#add_subdirectory(# text)
add_subdirectory(geometric)
#add_subdirectory(# shift)
add_subdirectory(fill)
#add_subdirectory(# eraser)
add_subdirectory(polyline)
add_subdirectory(motion)
add_subdirectory(rotation)
add_subdirectory(scale)
add_subdirectory(shear)
add_subdirectory(opacity)
add_subdirectory(color)
add_subdirectory(papagayo)
