set(TUPICOLORPALETTE_HEADERS
    tupcolorpalettewidget.h)

set(TUPICOLORPALETTE_SOURCES
    tupcolorpalettewidget.cpp)
add_library(tupicolorpalette SHARED ${TUPICOLORPALETTE_SOURCES})
set_target_properties(tupicolorpalette PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupicolorpalette tupifwcore tupibase tupicolor)

install(TARGETS tupicolorpalette LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPICOLORPALETTE_HEADERS ?
