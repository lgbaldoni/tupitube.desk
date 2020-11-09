set(TUPISHEARTOOL_HEADERS
    tweener.h
    configurator.h
    shearsettings.h)

set(TUPISHEARTOOL_SOURCES
    tweener.cpp
    configurator.cpp
    shearsettings.cpp)

add_library(tupisheartool MODULE ${TUPISHEARTOOL_SOURCES})
target_link_libraries(tupisheartool tupifwcore tupibase tupiplugincommon)

install(TARGETS tupisheartool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPISHEARTOOL_HEADERS ?
