set(TUPIWORKSPACE_HEADERS
    tuppaintarea.h
    tupconfigurationarea.h
    tupdocumentview.h
    tupimagedevice.h
    tuppaintareacommand.h
    tuplibrarydialog.h
    tupcanvas.h
    tupcanvasview.h
    tupimagedialog.h
    tupstoryboarddialog.h
    tuppendialog.h
    tuponiondialog.h
    # tupinfowidget.h
    tupruler.h
    tupcamerainterface.h
    tupreflexinterface.h
    tupbasiccamerainterface.h
    tupcameradialog.h
    tupcamerawindow.h
    tupvideosurface.h
    tuppapagayoimporter.h
    tuppapagayodialog.h
    tupreflexrenderarea.h
    tupmodesitem.h
    tupmodessettingsdialog.h
    tupmodeslist.h)

set(TUPIWORKSPACE_SOURCES
    tuppaintarea.cpp
    tupconfigurationarea.cpp
    tupdocumentview.cpp
    tupimagedevice.cpp
    tuppaintareacommand.cpp
    tuplibrarydialog.cpp
    tupcanvas.cpp
    tupcanvasview.cpp
    tupimagedialog.cpp
    tupstoryboarddialog.cpp
    tuppendialog.cpp
    tuponiondialog.cpp
    # tupinfowidget.cpp
    tupruler.cpp
    tupcamerainterface.cpp
    tupreflexinterface.cpp
    tupbasiccamerainterface.cpp
    tupcameradialog.cpp
    tupcamerawindow.cpp
    tupvideosurface.cpp
    tuppapagayoimporter.cpp
    tuppapagayodialog.cpp
    tupreflexrenderarea.cpp
    tupmodesitem.cpp
    tupmodessettingsdialog.cpp
    tupmodeslist.cpp)

# unclean, see if anything can be done about it
set(SHELL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/shell)
set(SELECTION_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/plugins/tools/selection)
set(POLYLINETOOL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/plugins/tools/polyline)

add_library(tupiworkspace SHARED ${TUPIWORKSPACE_SOURCES})
set_target_properties(tupiworkspace PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(tupiworkspace PUBLIC ${SHELL_INCLUDE_DIR}
  ${SELECTION_INCLUDE_DIR} ${POLYLINETOOL_INCLUDE_DIR})
target_link_libraries(tupiworkspace tupifwcore tupifwgui tupi tupibase rastermain
  Qt::Multimedia Qt::MultimediaWidgets Qt::PrintSupport)

install(TARGETS tupiworkspace LIBRARY DESTINATION ${TUPITUBE_TUPILIB})

# what do we do with TUPIWORKSPACE_HEADERS ?
