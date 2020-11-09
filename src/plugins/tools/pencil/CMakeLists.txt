set(TUPIPENCILTOOL_HEADERS
    penciltool.h
    pensettings.h)

set(TUPIPENCILTOOL_SOURCES
    penciltool.cpp
    pensettings.cpp)

add_library(tupipenciltool MODULE ${TUPIPENCILTOOL_SOURCES})
target_link_libraries(tupipenciltool tupifwcore tupibase)

install(TARGETS tupipenciltool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIPENCILTOOL_HEADERS ?
