set(TUPITWITTER_HEADERS
    tuptwitter.h
    tuptwitterwidget.h)

set(TUPITWITTER_SOURCES
    tuptwitter.cpp
    tuptwitterwidget.cpp)

add_library(tupitwitter SHARED ${TUPITWITTER_SOURCES})
set_target_properties(tupitwitter PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupitwitter tupifwcore Qt::Network)

install(TARGETS tupitwitter LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPITWITTER_HEADERS ?
