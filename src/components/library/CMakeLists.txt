set(TUPILIBRARY_HEADERS
    tuplibrarywidget.h
    tupitemmanager.h
    tupsymboleditor.h
    tuptreedelegate.h
    tupnewitemdialog.h
    tuplibrarydisplay.h
    tupsoundplayer.h)

set(TUPILIBRARY_SOURCES
    tuplibrarywidget.cpp
    tupitemmanager.cpp
    tupsymboleditor.cpp
    tuptreedelegate.cpp
    tupnewitemdialog.cpp
    tuplibrarydisplay.cpp
    tupsoundplayer.cpp)

add_library(tupilibrary SHARED ${TUPILIBRARY_SOURCES})
set_target_properties(tupilibrary PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupilibrary tupifwcore tupifwgui tupi tupibase Qt::Multimedia)

install(TARGETS tupilibrary LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPILIBRARY_HEADERS?
