set(RASTERBRUSHES_HEADERS
    rasterbrusheswidget.h
    rasterbutton.h)

set(RASTERBRUSHES_SOURCES
    rasterbrusheswidget.cpp
    rasterbutton.cpp)

add_library(rasterbrushes SHARED ${RASTERBRUSHES_SOURCES})
set_target_properties(rasterbrushes PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rasterbrushes tupifwcore tupibase)

install(TARGETS rasterbrushes LIBRARY DESTINATION ${TUPITUBE_RASTER})

# what do we do with RASTERBRUSHES_HEADERS? install them somewhere?
