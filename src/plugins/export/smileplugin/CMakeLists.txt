set(TUPISMILEPLUGIN_HEADERS
    smileplugin.h)

set(TUPISMILEPLUGIN_SOURCES
    smileplugin.cpp)

add_library(tupismileplugin MODULE ${TUPISMILEPLUGIN_SOURCES})
target_link_libraries(tupismileplugin tupifwcore tupibase)

install(TARGETS tupismileplugin DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPISMILEPLUGIN_HEADERS ?
