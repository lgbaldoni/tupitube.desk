set(TUPIIMAGEPLUGIN_HEADERS
    imageplugin.h)

set(TUPIIMAGEPLUGIN_SOURCES
    imageplugin.cpp)

add_library(tupiimageplugin MODULE ${TUPIIMAGEPLUGIN_SOURCES})
target_link_libraries(tupiimageplugin tupifwcore tupibase)

install(TARGETS tupiimageplugin DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIIMAGEPLUGIN_HEADERS ?
