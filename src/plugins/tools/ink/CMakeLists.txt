set(TUPIINKTOOL_HEADERS
    inktool.h
    inksettings.h)

set(TUPIINKTOOL_SOURCES
    inktool.cpp
    inksettings.cpp)

add_library(tupiinktool MODULE ${TUPIINKTOOL_SOURCES})
target_link_libraries(tupiinktool tupifwcore tupibase)

install(TARGETS tupiinktool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIINKTOOL_HEADERS ?
