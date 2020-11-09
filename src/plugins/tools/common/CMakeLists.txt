set(TUPIPLUGINCOMMON_HEADERS
    buttonspanel.h
    tweenmanager.h
    stepsviewer.h
    # spinboxdelegate.h
    target.h)

set(TUPIPLUGINCOMMON_SOURCES
    buttonspanel.cpp
    tweenmanager.cpp
    stepsviewer.cpp
    # spinboxdelegate.cpp
    target.cpp)

add_library(tupiplugincommon SHARED ${TUPIPLUGINCOMMON_SOURCES})
set_target_properties(tupiplugincommon PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupiplugincommon tupifwcore tupifwgui tupistore)

install(TARGETS tupiplugincommon LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

if(ADD_HEADERS)
  install(FILES ${TUPIPLUGINCOMMON_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupiplugincommon)
endif()
