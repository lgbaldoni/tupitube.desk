set(TUPIOPACITYTOOL_HEADERS
    tweener.h
    configurator.h
    opacitysettings.h)

set(TUPIOPACITYTOOL_SOURCES
    tweener.cpp
    configurator.cpp
    opacitysettings.cpp)

add_library(tupiopacitytool MODULE ${TUPIOPACITYTOOL_SOURCES})
target_link_libraries(tupiopacitytool tupifwcore tupibase tupiplugincommon)

install(TARGETS tupiopacitytool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIOPACITYTOOL_HEADERS ?
