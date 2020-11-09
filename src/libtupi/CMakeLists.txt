set(TUPI_HEADERS
    tupgraphicalgorithm.h
    # tupglobal.h
    tuppaintareaproperties.h
    tupgradientcreator.h
    tupgradientselector.h
    tupgradientviewer.h
    tuppackagehandler.h
    tupprojectactionbar.h
    tupbrushmanager.h
    tupinputdeviceinformation.h
    tupsvg2qt.h
    tupitempreview.h
    tupcompress.h
    tupsocketbase.h
    tupxmlparserbase.h
    tupproxyitem.h
    # tupinthash.h
    tuppenthicknesswidget.h
    tupbrushstatus.h
    tuptoolstatus.h
    tupcolorwidget.h
    tuppaintareastatus.h)

set(TUPI_SOURCES
    tupgraphicalgorithm.cpp
    tuppaintareaproperties.cpp
    tupgradientcreator.cpp
    tupgradientselector.cpp
    tupgradientviewer.cpp
    tuppackagehandler.cpp
    tupprojectactionbar.cpp
    tupbrushmanager.cpp
    tupinputdeviceinformation.cpp
    tupsvg2qt.cpp
    tupitempreview.cpp
    tupcompress.cpp
    tupsocketbase.cpp
    tupxmlparserbase.cpp
    tupproxyitem.cpp
    tuppenthicknesswidget.cpp
    tupbrushstatus.cpp
    tuptoolstatus.cpp
    tupcolorwidget.cpp
    tuppaintareastatus.cpp)

add_library(tupi SHARED ${TUPI_SOURCES})
set_target_properties(tupi PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupi tupifwcore tupifwgui Qt::Network Qt::Svg QuaZip::QuaZip)

install(TARGETS tupi LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(ADD_HEADERS)
  install(FILES ${TUPI_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupi)
endif()
