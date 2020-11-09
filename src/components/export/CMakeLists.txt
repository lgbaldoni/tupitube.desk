set(TUPIEXPORT_HEADERS
    tupexportwizard.h
    tuppluginselector.h
    tupsceneselector.h
    tupexportmodule.h
    tupvideoproperties.h
    tupexportwidget.h)

set(TUPIEXPORT_SOURCES
    tupexportwizard.cpp
    tuppluginselector.cpp
    tupsceneselector.cpp
    tupexportmodule.cpp
    tupvideoproperties.cpp
    tupexportwidget.cpp)

add_library(tupiexport SHARED ${TUPIEXPORT_SOURCES})
set_target_properties(tupiexport PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiexport tupifwcore tupibase)

install(TARGETS tupiexport LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPIEXPORT_HEADERS ?
