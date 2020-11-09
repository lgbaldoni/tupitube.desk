set(TUPIFILLTOOL_HEADERS
    filltool.h)

set(TUPIFILLTOOL_SOURCES
    filltool.cpp)

add_library(tupifilltool MODULE ${TUPIFILLTOOL_SOURCES})
target_link_libraries(tupifilltool tupifwcore tupibase)

install(TARGETS tupifilltool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIFILLTOOL_HEADERS ?
