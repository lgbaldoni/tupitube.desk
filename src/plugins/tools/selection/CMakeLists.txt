set(TUPISELECTIONTOOL_HEADERS
    selectiontool.h
    node.h
    nodemanager.h
    selectionsettings.h)

set(TUPISELECTIONTOOL_SOURCES
    selectiontool.cpp
    node.cpp
    nodemanager.cpp
    selectionsettings.cpp)

add_library(tupiselectiontool MODULE ${TUPISELECTIONTOOL_SOURCES})
target_link_libraries(tupiselectiontool tupifwcore tupibase)

install(TARGETS tupiselectiontool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPISELECTIONTOOL_HEADERS ?
