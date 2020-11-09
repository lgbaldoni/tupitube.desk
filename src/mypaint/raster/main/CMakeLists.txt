set(RASTERMAIN_HEADERS
    rastercanvasbase.h
    rastercanvas.h
    rastermainwindow.h)

set(RASTERMAIN_SOURCES
    rastercanvasbase.cpp
    rastercanvas.cpp
    rastermainwindow.cpp)

add_library(rastermain SHARED ${RASTERMAIN_SOURCES})
set_target_properties(rastermain PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rastermain tupifwcore tupibase qtmypaint rasterbrushes rastercolor)

install(TARGETS rastermain LIBRARY DESTINATION ${TUPITUBE_RASTER})

install(DIRECTORY brushes DESTINATION ${TUPITUBE_SHARE}/themes/raster)
install(DIRECTORY resources DESTINATION ${TUPITUBE_SHARE}/themes/raster)

# what do we do with RASTERMAIN_HEADERS? install them somewhere?
