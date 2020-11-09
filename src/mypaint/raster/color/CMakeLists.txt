set(RASTERCOLOR_HEADERS
    rastercolorwidget.h)

set(RASTERCOLOR_SOURCES
    rastercolorwidget.cpp)

add_library(rastercolor SHARED ${RASTERCOLOR_SOURCES})
set_target_properties(rastercolor PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rastercolor tupifwcore tupibase tupicolor)

install(TARGETS rastercolor LIBRARY DESTINATION ${TUPITUBE_RASTER})

# what do we do with RASTERCOLOR_HEADERS? install them somewhere?
