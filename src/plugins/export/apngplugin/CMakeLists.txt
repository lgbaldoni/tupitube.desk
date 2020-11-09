set(TUPIAPNGPLUGIN_HEADERS
    apngplugin.h)

set(TUPIAPNGPLUGIN_SOURCES
    apngplugin.cpp)

add_library(tupiapngplugin MODULE ${TUPIAPNGPLUGIN_SOURCES})
target_link_libraries(tupiapngplugin tupifwcore tupibase)

install(TARGETS tupiapngplugin DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIAPNGPLUGIN_HEADERS ?
