set(TUPIFWSOUND_HEADERS
    taudioengineiface.h
    taudioplayer.h)

set(TUPIFWSOUND_SOURCES taudioplayer.cpp)

add_library(tupifwsound SHARED ${TUPIFWSOUND_SOURCES})
set_target_properties(tupifwsound PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR})
target_link_libraries(tupifwsound tupifwcore)

if(ADD_HEADERS)
  install(FILES ${TUPIFWSOUND_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupisound)
endif()
