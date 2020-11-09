set(TUPIPAPAGAYOTOOL_HEADERS
    mouthtarget.h
    papagayosettings.h
    buttonspanel.h
    configurator.h
    lipsyncmanager.h
    papagayotool.h)

set(TUPIPAPAGAYOTOOL_SOURCES
    mouthtarget.cpp
    papagayosettings.cpp
    buttonspanel.cpp
    configurator.cpp
    lipsyncmanager.cpp
    papagayotool.cpp)

add_library(tupipapagayotool MODULE ${TUPIPAPAGAYOTOOL_SOURCES})
target_link_libraries(tupipapagayotool tupifwcore tupifwgui tupibase)

install(TARGETS tupipapagayotool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIPAPAGAYOTOOL_HEADERS ?
