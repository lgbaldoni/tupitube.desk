set(TUPITHEORAPLUGIN_HEADERS
    theoramoviegenerator.h
    theoraplugin.h)

set(TUPITHEORAPLUGIN_SOURCES
    theoramoviegenerator.cpp)
###    theoraplugin.cpp)

add_library(tupitheoraplugin MODULE ${TUPITHEORAPLUGIN_SOURCES})
target_link_libraries(tupitheoraplugin tupifwcore tupibase)

install(TARGETS tupitheoraplugin DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPITHEORAPLUGIN_HEADERS ?
