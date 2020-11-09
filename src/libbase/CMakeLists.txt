set(TUPIBASE_HEADERS
     tupexportinterface.h
     tupexportpluginobject.h
     tupfilterinterface.h
     tupmodulewidgetbase.h
     tuppluginmanager.h
     tuptoolinterface.h
     tuptoolplugin.h
     tuppaintareabase.h
     # tuppaintarearotator.h
     tupgraphicsscene.h
     tupguideline.h
     tupanimationrenderer.h
     # tupwebhunter.h
     tuprotationdial.h
     tupsecurity.h
     tupwatermark.h)

set(TUPIBASE_SOURCES
    tupexportpluginobject.cpp
    tupmodulewidgetbase.cpp
    tuppluginmanager.cpp
    tuptoolplugin.cpp
    tuppaintareabase.cpp
    # tuppaintarearotator.cpp
    tupgraphicsscene.cpp
    tupguideline.cpp
    tupanimationrenderer.cpp
    # tupwebhunter.cpp
    tuprotationdial.cpp
    tupsecurity.cpp
    tupwatermark.cpp)

add_library(tupibase SHARED ${TUPIBASE_SOURCES})
set_target_properties(tupibase PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupibase tupifwcore tupistore)

install(TARGETS tupibase LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(ADD_HEADERS)
  install(FILES ${TUPIBASE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupibase)
endif()
