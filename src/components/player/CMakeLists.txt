set(TUPIPLAYER_HEADERS
    tupcamerawidget.h
    tupcamerabar.h
    tupscreen.h
    tupcamerastatus.h
    tupanimationspace.h
    tupinfodialog.h)

set(TUPIPLAYER_SOURCES
    tupcamerawidget.cpp
    tupcamerabar.cpp
    tupscreen.cpp
    tupcamerastatus.cpp
    tupanimationspace.cpp
    tupinfodialog.cpp)

add_library(tupiplayer SHARED ${TUPIPLAYER_SOURCES})
set_target_properties(tupiplayer PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiplayer tupifwcore tupiexport Qt::Multimedia)

install(TARGETS tupiplayer LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPIPLAYER_HEADERS ?
