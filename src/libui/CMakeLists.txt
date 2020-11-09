#INSTALLS += images images-en 
#images-en.files += images/en/*.png 
#images-en.path = /data/en/images 
#images.files += images/es/*.png 
#images.path = /data/es/images/ 
#



set(TUPIGUI_HEADERS
    tupabout.h
    tupthemepreferences.h
    tuppaintareapreferences.h
    tupgeneralpreferences.h
    tuppreferencesdialog.h)

set(TUPIGUI_SOURCES
    tupabout.cpp
    tupthemepreferences.cpp
    tuppaintareapreferences.cpp
    tupgeneralpreferences.cpp
    tuppreferencesdialog.cpp)

add_library(tupigui SHARED ${TUPIGUI_SOURCES})
set_target_properties(tupigui PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupigui tupifwcore tupifwgui tupibase Qt::Network)

install(TARGETS tupigui LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

if(ADD_HEADERS)
  install(FILES ${TUPIGUI_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupigui)
endif()
