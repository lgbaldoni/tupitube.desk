set(SHELL_HEADERS
    tupsigndialog.h
    tupstatusbar.h
    tupnewproject.h
    tupapplication.h
    tuplocalprojectmanagerhandler.h
    tupmainwindow.h)

### check again if things can be done this way
###set(SHELL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

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
# install launcher here, but we'll have to configure it first
  install(PROGRAMS ../../tools/linux/tupitube.desk DESTINATION ${CMAKE_INSTALL_BINDIR})
  install(FILES ../../launcher/tupitube.xml DESTINATION ${CMAKE_INSTALL_DATADIR}/mime/packages)
# this has to be created first!
#  install(FILES ../../launcher/tupitube.desktop ${CMAKE_INSTALL_DATADIR}/applications)
# consider using the svg icon here
  install(FILES ../../launcher/icons/tupitube.desk.png DESTINATION ${CMAKE_INSTALL_DATADIR}/pixmaps)
  install(DIRECTORY html DESTINATION ${TUPITUBE_SHARE}/data)
# might have to set a customizable license path
  install(FILES man/copyright DESTINATION ${CMAKE_INSTALL_DATADIR}/doc/tupitube)
# should this be called tupitube.bin instead?
  install(TARGETS tupitube.desk DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
