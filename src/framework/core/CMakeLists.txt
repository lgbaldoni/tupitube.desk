set(TUPIFWCORE_HEADERS
    tapplicationproperties.h
    tconfig.h
    tglobal.h
    tipdatabase.h
    tcachehandler.h
    txmlparserbase.h)

set(TUPIFWCORE_SOURCES
     talgorithm.cpp
     tapplicationproperties.cpp
     tconfig.cpp
     tipdatabase.cpp
     tcachehandler.cpp
     txmlparserbase.cpp)

#add the definition check and unix
#ifF(CMAKE_SYSTEM_NAME STREQUAL Linux)
if(UNIX)
  if(NOT ${DISABLE_DEBUG})
    list(APPEND TUPIFWCORE_SOURCES tdebug.cpp)
    list(APPEND TUPIFWCORE_HEADERS tdebug.h)
  endif()
endif()

# find out if it has to be forced shared or something
#add_library(tupifwcore ${TUPIFWCORE_SOURCES})
add_library(tupifwcore SHARED ${TUPIFWCORE_SOURCES})

set_property(TARGET tupifwcore PROPERTY POSITION_INDEPENDENT_CODE ON)
set_target_properties(tupifwcore PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tupifwcore Qt::Gui Qt::Widgets Qt::Xml)

install(TARGETS tupifwcore LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(ADD_HEADERS)
# are they files though? Perhaps there's something more specific, check it.
  install(FILES ${TUPIFWCORE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupicore)
endif()
