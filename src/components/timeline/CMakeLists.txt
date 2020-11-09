set(TUPITIMELINE_HEADERS
    tuptimeline.h
    tuptimelineruler.h
    tuptimelinetable.h
    tupscenecontainer.h
    # tuplayerindex.h
    tuptimelineheader.h)

set(TUPITIMELINE_SOURCES
    tuptimeline.cpp
    tuptimelineruler.cpp
    tuptimelinetable.cpp
    tupscenecontainer.cpp
    # tuplayerindex.cpp
    tuptimelineheader.cpp)

add_library(tupitimeline SHARED ${TUPITIMELINE_SOURCES})
set_target_properties(tupitimeline PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupitimeline tupifwcore tupi tupibase)

install(TARGETS tupitimeline LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPITIMELINE_HEADERS ?
