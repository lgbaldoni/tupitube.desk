set(TUPIBRUSH_HEADERS
    tupbrushwidget.h)
    # tuppenthicknesswidget.h

set(TUPIBRUSH_SOURCES
    tupbrushwidget.cpp)
    # tuppenthicknesswidget.cpp)

add_library(tupibrush SHARED ${TUPIBRUSH_SOURCES})
set_target_properties(tupibrush PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupibrush tupifwcore tupibase)

install(TARGETS tupibrush LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPIBRUSH_HEADERS ?
