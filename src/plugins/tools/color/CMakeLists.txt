set(TUPICOLORINGTOOL_HEADERS
    tweener.h
    configurator.h
    colorsettings.h)

set(TUPICOLORINGTOOL_SOURCES
    tweener.cpp
    configurator.cpp
    colorsettings.cpp)

add_library(tupicoloringtool MODULE ${TUPICOLORINGTOOL_SOURCES})
target_link_libraries(tupicoloringtool tupifwcore tupibase tupiplugincommon)

install(TARGETS tupicoloringtool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPICOLORINGTOOL_HEADERS ?
