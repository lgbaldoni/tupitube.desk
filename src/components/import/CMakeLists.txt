set(TUPIMPORT_HEADERS
    tuppaletteimporter.h)

set(TUPIMPORT_SOURCES
    tuppaletteimporter.cpp)

add_library(tupimport SHARED ${TUPIMPORT_SOURCES})
set_target_properties(tupimport PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupimport tupifwcore tupistore)

install(TARGETS tupimport LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPIMPORT_HEADERS ?
