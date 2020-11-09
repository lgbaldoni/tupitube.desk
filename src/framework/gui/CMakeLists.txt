set(TUPIFWGUI_HEADERS
     taction.h
     tactionmanager.h
     tanimwidget.h
     tapplication.h
     tbackupdialog.h
     tbuttonbar.h
     tcellview.h
     tcirclebutton.h
     tcirclebuttonbar.h
     tclicklineedit.h
     # tcollapsiblewidget.h
     tcolorbutton.h
     tcommandhistory.h
     tconfigurationdialog.h
     tcontrolnode.h
     tdoublecombobox.h
     tdualcolorbutton.h
     teditspinbox.h
     tflatbutton.h
     tfontchooser.h
     tformfactory.h
     tformvalidator.h
     ticon.h
     # tideality.h
     timagebutton.h
     titemselector.h
     tlabel.h
     tmainwindow.h
     tmainwindowabstractsettings.h
     # tmainwindowfactory.h
     tmoviegenerator.h
     tmoviegeneratorinterface.h
     tnodegroup.h
     tseparator.h
     toptionaldialog.h
     tosd.h
     tpathhelper.h
     tpushbutton.h
     tradiobuttongroup.h
     trulerbase.h
     # tstackedmainwindow.h
     tstylecombobox.h
     tabbedmainwindow.h
     tabdialog.h
     # ttabwidget.h
     themedocument.h
     thememanager.h
     tipdialog.h
     ttoolbox.h
     toolview.h
     treelistwidget.h
     treewidgetsearchline.h
     tvhbox.h
     tviewbutton.h
     # twaitstyle.h
     twidgetlistview.h
     twizard.h
     tworkspacemainwindow.h
     txyspinbox.h
     tcolorcell.h
     tslider.h
     tsizebox.h
     tcolorarrow.xpm
     tcolorreset.xpm
     tmsgdialog.h)

set(TUPIFWGUI_SOURCES
    taction.cpp
    tactionmanager.cpp
    tanimwidget.cpp
    tapplication.cpp
    tbackupdialog.cpp
    tbuttonbar.cpp
    tcellview.cpp
    tcirclebutton.cpp
    tcirclebuttonbar.cpp
    tclicklineedit.cpp
    tcolorbutton.cpp
    # tcollapsiblewidget.cpp
    tcommandhistory.cpp
    tconfigurationdialog.cpp
    tcontrolnode.cpp
    tdoublecombobox.cpp
    tdualcolorbutton.cpp
    teditspinbox.cpp
    tflatbutton.cpp
    tfontchooser.cpp
    tformfactory.cpp
    tformvalidator.cpp
    ticon.cpp
    tlabel.cpp
    timagebutton.cpp
    titemselector.cpp
    tmainwindow.cpp
    # tmainwindowfactory.cpp
    tmoviegenerator.cpp
    tnodegroup.cpp
    tseparator.cpp
    toptionaldialog.cpp
    tosd.cpp
    tpathhelper.cpp
    tpushbutton.cpp
    tradiobuttongroup.cpp
    trulerbase.cpp
    # tstackedmainwindow.cpp
    tstylecombobox.cpp
    tabbedmainwindow.cpp
    tabdialog.cpp
    # ttabwidget.cpp
    themedocument.cpp
    thememanager.cpp
    tipdialog.cpp
    ttoolbox.cpp
    toolview.cpp
    treelistwidget.cpp
    treewidgetsearchline.cpp
    tvhbox.cpp
    tviewbutton.cpp
    # twaitstyle.cpp
    twidgetlistview.cpp
    twizard.cpp
    tworkspacemainwindow.cpp
    txyspinbox.cpp
    tsizebox.cpp
    tcolorcell.cpp
    tslider.cpp
    tmsgdialog.cpp)


add_library(tupifwgui SHARED ${TUPIFWGUI_SOURCES})
set_target_properties(tupifwgui PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupifwgui tupifwcore Qt::Widgets Qt::Xml)

install(TARGETS tupifwgui LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(ADD_HEADERS)
  install(FILES ${TUPIFWGUI_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupigui)
endif()
