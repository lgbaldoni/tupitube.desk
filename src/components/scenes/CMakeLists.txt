set(TUPISCENES_HEADERS
    tupsceneslist.h
    tupscenesdelegate.h
    tupsceneswidget.h)

set(TUPISCENES_SOURCES
    tupsceneslist.cpp
    tupscenesdelegate.cpp
    tupsceneswidget.cpp)

add_library(tupiscenes SHARED ${TUPISCENES_SOURCES})
set_target_properties(tupiscenes PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiscenes tupifwcore tupifwgui tupibase)

install(TARGETS tupiscenes LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPISCENES_HEADERS?
