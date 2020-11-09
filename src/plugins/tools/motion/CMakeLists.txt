set(TUPIMOTIONTOOL_HEADERS
    tweener.h
    configurator.h
    motionsettings.h)

set(TUPIMOTIONTOOL_SOURCES
    tweener.cpp
    configurator.cpp
    motionsettings.cpp)

add_library(tupimotiontool MODULE ${TUPIMOTIONTOOL_SOURCES})
target_link_libraries(tupimotiontool tupifwcore tupibase tupiplugincommon)

# this wasn't present in 0.2.15
install(TARGETS tupimotiontool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIMOTIONTOOL_HEADERS ?
