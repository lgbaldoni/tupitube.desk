set(TUPISTORE_HEADERS
     tuplayer.h
     tuppalettedocument.h
     tupframe.h
     tupprojectrequest.h
     tupscene.h
     tupproject.h
     tupprojectmanager.h
     tupprojectcommand.h
     tupabstractserializable.h
     tupframegroup.h
     tuppathitem.h
     tuprectitem.h
     tuppixmapitem.h
     tuptextitem.h
     tupbuttonitem.h
     tupitemfactory.h
     tupellipseitem.h
     # tupglobal_store.h
     tuppaintareaevent.h
     tupserializer.h
     tuplineitem.h
     tupitemconverter.h
     tupitemgroup.h
     tupprojectmanagerparams.h
     tupabstractprojectmanagerhandler.h
     tupcommandexecutor.h
     tupgraphicobject.h
     tuplibrary.h
     tuplibraryobject.h
     tuplibraryfolder.h
     tuprequestbuilder.h
     tuprequestparser.h
     tupprojectresponse.h
     tupabstractprojectresponsehandler.h
     tupfilemanager.h
     tupprojectloader.h
     tupgraphiclibraryitem.h
     tupitemtweener.h
     tuptweenerstep.h
     tupsoundlayer.h
     tupsvgitem.h
     tupbackgroundscene.h
     tupbackground.h
     tupstoryboard.h
     tuplipsync.h)

set(TUPISTORE_SOURCES
    tuplayer.cpp
    tuppalettedocument.cpp
    tupframe.cpp
    tupprojectrequest.cpp
    tupscene.cpp
    tupproject.cpp
    tupprojectmanager.cpp
    tupprojectcommand.cpp
    tupframegroup.cpp
    tuppathitem.cpp
    tuprectitem.cpp
    tuppixmapitem.cpp
    tuptextitem.cpp
    tupbuttonitem.cpp
    tupellipseitem.cpp
    tuppaintareaevent.cpp
    tupserializer.cpp
    tuplineitem.cpp
    tupitemconverter.cpp
    tupitemgroup.cpp
    tupprojectmanagerparams.cpp
    tupabstractprojectmanagerhandler.cpp
    tupcommandexecutor.cpp
    tupcommandexecutor_frames.cpp
    tupcommandexecutor_items.cpp
    tupcommandexecutor_layers.cpp
    tupgraphicobject.cpp
    tuplibrary.cpp
    tuplibraryobject.cpp
    tuplibraryfolder.cpp
    tupcommandexecutor_library.cpp
    tuprequestbuilder.cpp
    tuprequestparser.cpp
    tupprojectresponse.cpp
    tupabstractprojectresponsehandler.cpp
    tupitemfactory.cpp
    tupfilemanager.cpp
    tupprojectloader.cpp
    tupgraphiclibraryitem.cpp
    tupitemtweener.cpp
    tuptweenerstep.cpp
    tupsoundlayer.cpp
    tupsvgitem.cpp
    tupbackgroundscene.cpp
    tupbackground.cpp
    tupstoryboard.cpp
    tuplipsync.cpp)

add_library(tupistore SHARED ${TUPISTORE_SOURCES})
set_target_properties(tupistore PROPERTIES VERSION ${LIB_VERSION_STRING}
                      SOVERSION ${LIB_VERSION_MAJOR}
                      INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tupistore tupifwcore tupi Qt::Svg)

install(TARGETS tupistore LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(ADD_HEADERS)
  install(FILES ${TUPISTORE_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupistore)
endif()
