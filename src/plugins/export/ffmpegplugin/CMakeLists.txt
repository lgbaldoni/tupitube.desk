set(TUPIFFMPEGPLUGIN_HEADERS
    tffmpegmoviegenerator.h
    ffmpegplugin.h)

set(TUPIFFMPEGPLUGIN_SOURCES
    tffmpegmoviegenerator.cpp
    ffmpegplugin.cpp)

add_library(tupiffmpegplugin MODULE ${TUPIFFMPEGPLUGIN_SOURCES})
target_include_directories(tupiffmpegplugin PUBLIC ${FFMPEG_INCLUDE_DIRS})
target_link_libraries(tupiffmpegplugin tupifwcore tupibase ${FFMPEG_LIBRARIES})
# unsure about the link to FFMPEG_LIBRARIES, it appears to be automated, but
# I'm going to leave it there for good measure

install(TARGETS tupiffmpegplugin DESTINATION ${TUPITUBE_PLUGIN})

if(ADD_HEADERS)
  install(FILES ${TUPIFFMPEGPLUGIN_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/tupiffmpeg)
endif()
