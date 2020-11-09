set(TUPISCALETOOL_HEADERS
    tweener.h
    configurator.h
    scalesettings.h)

set(TUPISCALETOOL_SOURCES
    tweener.cpp
    configurator.cpp
    scalesettings.cpp)

add_library(tupiscaletool MODULE ${TUPISCALETOOL_SOURCES})
target_link_libraries(tupiscaletool tupifwcore tupibase tupiplugincommon)

install(TARGETS tupiscaletool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPISCALETOOL_HEADERS ?
