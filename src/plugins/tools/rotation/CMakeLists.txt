set(TUPIROTATIONTOOL_HEADERS
    tweener.h
    configurator.h
    rotationsettings.h)

set(TUPIROTATIONTOOL_SOURCES
    tweener.cpp
    configurator.cpp
    rotationsettings.cpp)

add_library(tupirotationtool MODULE ${TUPIROTATIONTOOL_SOURCES})
target_link_libraries(tupirotationtool tupifwcore tupibase tupiplugincommon)

install(TARGETS tupirotationtool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIROTATIONTOOL_HEADERS ?
