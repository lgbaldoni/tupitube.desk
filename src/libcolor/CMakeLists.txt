file(GLOB TUPICOLOR_PALETTES palettes/*.tpal)

set(TUPICOLOR_HEADERS
    tupcolorpicker.h
    tupviewcolorcells.h
    tupcellscolor.h
    tuppaletteparser.h
    tupformitem.h
    tupcolorform.h
    tupcolorbutton.h
    tupcolorbuttonpanel.h)

set(TUPICOLOR_SOURCES
    tupcolorpicker.cpp
    tupviewcolorcells.cpp
    tupcellscolor.cpp
    tuppaletteparser.cpp
    tupformitem.cpp
    tupcolorform.cpp
    tupcolorbutton.cpp
    tupcolorbuttonpanel.cpp)

add_library(tupicolor SHARED ${TUPICOLOR_SOURCES})
set_target_properties(tupicolor PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupicolor tupifwcore tupifwgui tupistore)

install(TARGETS tupicolor LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(FILES ${TUPICOLOR_PALETTES} DESTINATION ${TUPITUBE_SHARE}/data/palettes)

if(ADD_HEADERS)
# not present in the original, so I'm disabling it
#  install(FILES ${TUPICOLOR_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupicolor)
endif()
