set(TUPINODESTOOL_HEADERS
    nodestool.h)

set(TUPINODESTOOL_SOURCES
    nodestool.cpp)

add_library(tupinodestool MODULE ${TUPINODESTOOL_SOURCES})
target_link_libraries(tupinodestool tupifwcore tupifwgui tupibase)

install(TARGETS tupinodestool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPINODESTOOL_HEADERS ?
