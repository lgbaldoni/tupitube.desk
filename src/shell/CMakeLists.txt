set(SHELL_HEADERS
    tupsigndialog.h
    tupstatusbar.h
    tupnewproject.h
    tupapplication.h
    tuplocalprojectmanagerhandler.h
    tupmainwindow.h)

set(SHELL_SOURCES
    tupsigndialog.cpp
    tupstatusbar.cpp
    tupnewproject.cpp
    tupapplication.cpp
    tuplocalprojectmanagerhandler.cpp
    tupmainwindow.cpp
    tupmainwindow_gui.cpp
    main.cpp)

if(UNIX)
list(APPEND SHELL_HEAERS
     tupcrashhandler.h
     tupcrashwidget.h)
list(APPEND SHELL_SOURCES
     tupcrashhandler.cpp
     tupcrashwidget.cpp)
endif()

add_executable(tupitube.desk ${SHELL_SOURCES})
target_link_libraries(tupitube.desk tupifwgui tupistore tupiworkspace tupiplayer
   tupigui tupiexposure tupibrush tupicolorpalette tupiscenes tupilibrary
   tupitimeline tupitwitter tupinet tupimport)

if(UNIX AND NOT APPLE)
  install(DIRECTORY data DESTINATION ${TUPITUBE_SHARE})
  configure_file(${CMAKE_SOURCE_DIR}/tools/linux/tupitube.desk.in
    ${CMAKE_CURRENT_BINARY_DIR}/tupitube.desk)
  install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/tupitube.desk
    DESTINATION ${CMAKE_INSTALL_BINDIR})
  install(FILES ${CMAKE_SOURCE_DIR}/launcher/tupitube.xml
    DESTINATION ${CMAKE_INSTALL_DATADIR}/mime/packages)
  configure_file(${CMAKE_SOURCE_DIR}/launcher/tupitube.desktop.in
    ${CMAKE_CURRENT_BINARY_DIR}/tupitube.desktop)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/tupitube.desktop
    DESTINATION ${CMAKE_INSTALL_DATADIR}/applications)
# consider using the svg icon here
  install(FILES ${CMAKE_SOURCE_DIR}/launcher/icons/tupitube.desk.png
    DESTINATION ${CMAKE_INSTALL_DATADIR}/pixmaps)
  install(DIRECTORY html DESTINATION ${TUPITUBE_SHARE}/data)
# might have to set a customizable license path
  install(FILES man/copyright DESTINATION ${CMAKE_INSTALL_DATADIR}/doc/tupitube)
# should this be called tupitube.bin instead?
  install(TARGETS tupitube.desk RENAME tupitube.bin
    DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
