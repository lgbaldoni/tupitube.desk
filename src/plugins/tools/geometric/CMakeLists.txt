set(TUPIGEOMETRICTOOL_HEADERS
    geometrictool.h
    geometricsettings.h)

set(TUPIGEOMETRICTOOL_SOURCES
    geometrictool.cpp
    geometricsettings.cpp)

add_library(tupigeometrictool MODULE ${TUPIGEOMETRICTOOL_SOURCES})
target_link_libraries(tupigeometrictool tupifwcore tupibase)

install(TARGETS tupigeometrictool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIGEOMETRICTOOL_HEADERS ?
