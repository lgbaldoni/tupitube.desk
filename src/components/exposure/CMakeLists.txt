set(TUPIEXPOSURE_HEADERS
    tupexposuresheet.h
    tupexposureheader.h
    tupexposuretable.h
    tupscenetabwidget.h)

set(TUPIEXPOSURE_SOURCES
    tupexposuresheet.cpp
    tupexposureheader.cpp
    tupexposuretable.cpp
    tupscenetabwidget.cpp)

add_library(tupiexposure SHARED ${TUPIEXPOSURE_SOURCES})
set_target_properties(tupiexposure PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiexposure tupifwcore tupibase)

install(TARGETS tupiexposure LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPIEXPOSURE_HEADERS ?
