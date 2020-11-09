set(MYPAINT_HEADERS
    brushmodes.h
    brushsettings-gen.h
    fifo.h
    helpers.h
    mapping.h
    mypaint.h
    mypaint-brush.h
    mypaint-brush-settings.h
    mypaint-brush-settings-gen.h
    mypaint-config.h
    mypaint-config.h.in
    mypaint-fixed-tiled-surface.h
    mypaint-glib-compat.h
    mypaint-rectangle.h
    mypaint-surface.h
    mypaint-tiled-surface.h
    operationqueue.h
    rng-double.h
    tiled-surface-private.h
    tilemap.h
    utils.h)

set(MYPAINT_SOURCES
    brushmodes.c
    fifo.c
    helpers.c
    ###libmypaint.c
    mapping.c
    mypaint.c
    mypaint-brush.c
    mypaint-brush-settings.c
    mypaint-fixed-tiled-surface.c
    mypaint-rectangle.c
    mypaint-surface.c
    mypaint-tiled-surface.c
    operationqueue.c
    rng-double.c
    tilemap.c
    utils.c)


add_library(mypaint SHARED ${MYPAINT_SOURCES})
set_target_properties(mypaint PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(mypaint PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(mypaint json-c)

### do I actually need this?
set_property(TARGET mypaint PROPERTY C_STANDARD 99)

install(TARGETS mypaint LIBRARY DESTINATION ${TUPITUBE_RASTER})

# what do we do with MYPAINT_HEADERS? install them somewhere?
