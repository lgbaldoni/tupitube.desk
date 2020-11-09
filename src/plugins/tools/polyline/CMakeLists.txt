set(TUPIPOLYLINETOOL_HEADERS
    polylinetool.h
    polylinesettings.h)

set(TUPIPOLYLINETOOL_SOURCES
    polylinetool.cpp
    polylinesettings.cpp)

add_library(tupipolylinetool MODULE ${TUPIPOLYLINETOOL_SOURCES})
target_link_libraries(tupipolylinetool tupifwcore tupibase)

install(TARGETS tupipolylinetool DESTINATION ${TUPITUBE_PLUGIN})

# what do we do with TUPIPOLYLINETOOL_HEADERS ?
